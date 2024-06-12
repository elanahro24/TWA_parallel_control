/*
 * stgmembs.c
 */

// fix this later
//#include <assert.h>
#define assert(a)

#include "C:\ServoToGo\offsets.h"
#include "C:\ServoToGo\stg_comn.h"
#include "C:\ServoToGo\stgdefs.h"
#include "C:\ServoToGo\stgmembs.h"
#include "C:\ServoToGo\portio.h"
//#include "omnisem.h"

extern struct ServoToGo StgController;

/***************************************************************************/
/*                                                                         */
/*                           Constructor                                   */
/*                                                                         */
/***************************************************************************/

void ServoToGo_Constructor(void)
{
	//extern struct ServoToGo StgController;

	// you need to call init after this.
    StgController.byIndexPulsePolarity = 1;      // default active level high
    StgController.wNoBoardFlag = NO_BOARD;
};

void ServoToGo_Constructor2(unsigned short wRequestedIrq)
{
    StgController.wNoBoardFlag = NO_BOARD;
    Stg_Init(wRequestedIrq,StgController.wBaseAddress);
	/*
	EncoderInit();
    Initialize(wRequestedIrq);   // figure out board address, init irq controller
    SelectInterruptPeriod(_1_MILLISECOND);  // initialize timer
    StgController.byIndexPulsePolarity = 1;               // default active level high
    if (StgController.wModel == MODEL2)
        fOutP(StgController.wBaseAddress + CNTRL1, CNTRL1_NOT_SLAVE);
	*/
};

/***************************************************************************/
/*                                                                         */
/*                            Destructor                                   */
/*                                                                         */
/***************************************************************************/
void ServoToGo_Destructor(void)
{
    unsigned short nAxis;
	StopInterrupts();

    // set all the DAC outputs to 0.
    for (nAxis = 0; nAxis < MAX_AXIS; nAxis++)
        RawDAC(nAxis, 0);

    // set all the digital I/O bits to input
    DioDirection(0);
};

/***************************************************************************/
/*                                                                         */
/*                              ...Init                                    */
/*                                                                         */
/***************************************************************************/
void Stg_Init(unsigned short wRequestedIrq, unsigned short wAdd)
{
    StgController.byIndexPollAxis = 0;
    StgController.byIndexPulsePolarity = 1;
	StgController.wAxesInSys = 0;
	StgController.wSaveDirs = 0;

    StgController.wBaseAddress = wAdd;
    if ( !BrdtstOK(wAdd) )    // determines model and fills in wModel
    {
        StgController.wBaseAddress = 0;
        StgController.wNoBoardFlag = NO_BOARD;           // done in ctor
        return;
    }
    StgController.wNoBoardFlag = BOARD_PRESENT;
    if (StgController.wModel == MODEL2)
        fOutP(StgController.wBaseAddress + CNTRL1, CNTRL1_NOT_SLAVE);
   
    EncoderInit();
    Initialize(wRequestedIrq);   // init irq controller
    SelectInterruptPeriod(_1_MILLISECOND);    // initialize timer
};   

/***************************************************************************/
/*                                                                         */
/*                            DioDirection                                 */
/*                                                                         */
/***************************************************************************/
//
// Two overloaded functions, the first takes a port and a direction, the
// second takes a word with bits set for the direction of each port
//
void DioDirection2(unsigned short nPortBits, unsigned short nDirection)
{
    // sometimes you want to set the direction of a port, but may not know
    // what direction other ports are.  Here we select the port (or ports)
    // that we want to set the direction of, in nPortBits.  Then the direction,
    // either input or output, with nDirection.
    //
	unsigned short nSwDir;
    
	assert(nDirection <= 1);      // direction is either 0 or 1
    if (nDirection > 1)
        return;

	nSwDir = StgController.wSaveDirs;

    if (nDirection == STG_PORT_OUTPUT)
        nSwDir |= nPortBits;
    else
        nSwDir &= ~nPortBits;

    DioDirection(nSwDir);
};


//                                        Don't care.
//                                        |<------>|
// bits in nSwDir set direction of ports: xxxxxxxxxxbbbbbb
//                                                  ||||||
//                                                  |||||Port A
//       1 = Output                                 ||||PortB
//       0 = Input                                  |||Port C, high nibble
//                                                  ||Port C, low nibble
//                                                  |Port D (port D, low nibble)
//                                                  |(Port D, high nibble)

void DioDirection(const unsigned short nSwDir)
{
    unsigned char byHwDir;                   // direction bits for hardware
    unsigned long lCurrentData;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    // get the current data in the I/O ports.  We'll replace it when we're
    // done.  When you change a port to output, it will start at what the
    // input was (usually high).  This way, bits won't change (except for a
    // glitch) when a port is set to output.

    lCurrentData = RawDI();

    byHwDir = 0x9b;                          // initially all ports input

    if (nSwDir & STG_PORT_A)                 // check the bit for A out
         byHwDir &= ~A_DIR_BIT;                  // if output, set bit to 0
    if (nSwDir & STG_PORT_B)
         byHwDir &= ~B_DIR_BIT;
    if (nSwDir & STG_PORT_C_LO)
         byHwDir &= ~C_LOW_DIR_BIT;
    if (nSwDir & STG_PORT_C_HI)
         byHwDir &= ~C_HI_DIR_BIT;

    fOutP(StgController.wBaseAddress + ABC_DIR, byHwDir); // set direction for A, B and C

    SetDDir(nSwDir);
    StgController.wSaveDirs = nSwDir;                     // save, mostly for other function
    RawDO(lCurrentData);
};

void SetDDir(unsigned short nSwDir)
{
    unsigned char byHwDir;                   // direction bits for hardware
    unsigned char bySaveReg, bySaveIMR, bySaveCntrl1, bySaveCntrl0;

    if (StgController.wModel == MODEL1)
    {
        bySaveReg = fInP(StgController.wBaseAddress + INTC);   // INTC needs to be saved, because
                                                 // MIO_2 reinitializes the 8255 which
                                                 // implements the INTC register.
        byHwDir = 0x92;                          // initialize port D input
        if (nSwDir & STG_PORT_D)                 // is port D output?
             byHwDir &= ~D_DIR_BIT;              // if yes, set bit to 0,
        bySaveIMR = fInP(StgController.wBaseAddress + IMR);    // get the current interrupt mask
        fOutP(StgController.wBaseAddress + OCW1, 0xff);        // mask off all interrupts
        fOutP(StgController.wBaseAddress + MIO_2, byHwDir);    // set direction for port D
        fOutP(StgController.wBaseAddress + INTC, bySaveReg);   // restore interrupt control reg.
        fOutP(StgController.wBaseAddress + OCW1, bySaveIMR);   // restore interrupt mask
    }
    else  // Model 2
    {
        bySaveCntrl0 = fInP(StgController.wBaseAddress + CNTRL0); // CNTRL0 needs to be saved, because
                                                 // D_DIR reinitializes the 8255 which
                                                 // implements the CNTRL0 register.
        byHwDir = 0x8b;                          // initialize CNTRL0 as output reg.
                                                 // BRDTST to input.
                                                 // sets port D, high and low, to input
        if (nSwDir & STG_PORT_D_LO)              // low nibble
            byHwDir &= ~D_LOW_DIR_BIT;
        if (nSwDir & STG_PORT_D_HI)              // high nibble
            byHwDir &= ~D_HI_DIR_BIT;

        bySaveCntrl1 = fInP(StgController.wBaseAddress+CNTRL1);// save for interrupt enables

            // don't reset any latches; put in slave state;
            // disable interrupts, so the glitch in CTRL0 doesn't
            // cause an interrupt on wrong irq
        fOutP(StgController.wBaseAddress + CNTRL1, 0xf0);

        fOutP(StgController.wBaseAddress + D_DIR, byHwDir);    // set port D direction

            // restore CNTRL0, because it was re-initialized, which
            // lost any previous contents.
        fOutP(StgController.wBaseAddress + CNTRL0, bySaveCntrl0);

            // re-enable interrupts, and restore slave state, don't
            // reset any latches. (1111xxxx)
        fOutP(StgController.wBaseAddress+CNTRL1, (bySaveCntrl1 & 0x0f) | 0xf0);
    }
};

/***************************************************************************/
/*                                                                         */
/*                                RawDO                                    */
/*                                                                         */
/***************************************************************************/
//
// Overloaded functions:
//    1) takes a 32 bit value and sets all 32 iobits
//    2) takes which bit, which port, and what value, and sets only that bit
//

void RawDO(unsigned long lOutBits)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }
    if (StgController.wModel == MODEL1)
    {
        fOutP(StgController.wBaseAddress + DIO_A, ((IO32 *)&lOutBits)->port.A);
        fOutP(StgController.wBaseAddress + DIO_B, ((IO32 *)&lOutBits)->port.B);
        fOutP(StgController.wBaseAddress + DIO_C, ((IO32 *)&lOutBits)->port.C);
        fOutP(StgController.wBaseAddress + DIO_D, ((IO32 *)&lOutBits)->port.D);
    }
    else  // Model 2
    {
        fOutP(StgController.wBaseAddress + PORT_A, ((IO32 *)&lOutBits)->port.A);
        fOutP(StgController.wBaseAddress + PORT_B, ((IO32 *)&lOutBits)->port.B);
        fOutP(StgController.wBaseAddress + PORT_C, ((IO32 *)&lOutBits)->port.C);
        fOutP(StgController.wBaseAddress + PORT_D, ((IO32 *)&lOutBits)->port.D);
    }
};

void RawDO3(unsigned char byBitNumber, unsigned char bySet0or1,
                      unsigned short nPort)
{
    unsigned nOffset = 0;
    unsigned char byData = 0;
    const aPortOffset_1[] = {DIO_A, DIO_B, DIO_C, DIO_D};
	const aPortOffset_2[] = {PORT_A, PORT_B, PORT_C, PORT_D};

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    if (nPort > 3)
        return;

    if (StgController.wModel == MODEL1)
        nOffset = aPortOffset_1[nPort];
    else  // Model 2
        nOffset = aPortOffset_2[nPort];

    byData = fInP(StgController.wBaseAddress + nOffset);
    if (bySet0or1 == 1)
        byData |= 1 << byBitNumber;
    else
        byData &= ~(1u << byBitNumber);
    fOutP(StgController.wBaseAddress + nOffset, byData);
};

void RawDO2(unsigned char byData, short nPort)
{
    const aPortOffset_1[] = {DIO_A, DIO_B, DIO_C, DIO_D};
	const aPortOffset_2[] = {PORT_A, PORT_B, PORT_C, PORT_D};
	
	if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    if (nPort > 3)
        return;

    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + aPortOffset_1[nPort], byData);
    else  // Model 2
        fOutP(StgController.wBaseAddress + aPortOffset_2[nPort], byData);
};

// these next functions use the same constant that the direction functions,
// DioDirection(...) use.  These are prefered, since the same constant can
// be used in both situations, hopefully simplifying the code.

// helper function
short PortBits2Index(short nPort)
{
    int nPortIndex;

    switch(nPort)
    {
    case STG_PORT_A:
        nPortIndex = 0;
        break;
    case STG_PORT_B:
        nPortIndex = 1;
        break;
    case STG_PORT_C_LO:
    case STG_PORT_C_HI:
    case STG_PORT_C:
        nPortIndex = 2;
        break;
    case STG_PORT_D_LO:
    case STG_PORT_D_HI:
    case STG_PORT_D:
        nPortIndex = 3;
        break;
    }
    return nPortIndex;
};

void DigitalOut2(unsigned char byData, short nPortBits)
{
    RawDO2(byData, PortBits2Index(nPortBits));
};

void DigitalOut3(unsigned char byBitNumber, unsigned char bySet0or1,
                      unsigned short nPortBits)
{
    RawDO3(byBitNumber, bySet0or1, PortBits2Index(nPortBits));
};

/***************************************************************************/
/*                                                                         */
/*                                RawDI                                    */
/*                                                                         */
/***************************************************************************/

// some overloaded functions

unsigned long RawDI()
{
    IO32 xInBits;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        xInBits.all = 0;
        return(xInBits.all);
    }

    if (StgController.wModel == MODEL1)
    {
        xInBits.port.A = fInP(StgController.wBaseAddress + DIO_A);
        xInBits.port.B = fInP(StgController.wBaseAddress + DIO_B);
        xInBits.port.C = fInP(StgController.wBaseAddress + DIO_C);
        xInBits.port.D = fInP(StgController.wBaseAddress + DIO_D);
    }
    else  // Model 2
    {
        xInBits.port.A = fInP(StgController.wBaseAddress + PORT_A);
        xInBits.port.B = fInP(StgController.wBaseAddress + PORT_B);
        xInBits.port.C = fInP(StgController.wBaseAddress + PORT_C);
        xInBits.port.D = fInP(StgController.wBaseAddress + PORT_D);
    }
    return (xInBits.all);
};

unsigned char RawDI2(unsigned char byBitNumber, short nPort)
{
    const aPortOffset_1[] = {DIO_A, DIO_B, DIO_C, DIO_D};
	const aPortOffset_2[] = {PORT_A, PORT_B, PORT_C, PORT_D};

	unsigned char nData;

    if (nPort > 3)
        return 0;
    if (StgController.wModel == MODEL1)
        nData = fInP(StgController.wBaseAddress + aPortOffset_1[nPort]);
    else // Model 2
        nData = fInP(StgController.wBaseAddress + aPortOffset_2[nPort]);
    return nData & (1 << byBitNumber);
};

unsigned char RawDI1(short nPort)
{
    const aPortOffset_1[] = {DIO_A, DIO_B, DIO_C, DIO_D};
	const aPortOffset_2[] = {PORT_A, PORT_B, PORT_C, PORT_D};

    if (nPort > 3)
        return 0;

    if (StgController.wModel == MODEL1)
        return fInP(StgController.wBaseAddress + aPortOffset_1[nPort]);
    else
        return fInP(StgController.wBaseAddress + aPortOffset_2[nPort]);
};

unsigned long RawDI2b(long lPort, long lBitNumber)
{
    unsigned short wAddOff = 0;
    unsigned char bPortBits;

    switch (lPort)
    {
    case 0: wAddOff = DIO_A;
            break;
    case 1: wAddOff = DIO_B;
            break;
    case 2: wAddOff = DIO_C;
            break;
    case 3: if (StgController.wModel == MODEL1)
                wAddOff = DIO_D;
            else
                wAddOff = PORT_D;
            break;
    }
    bPortBits = fInP(StgController.wBaseAddress + wAddOff);
    if ( bPortBits & (1 << lBitNumber) )
        return 1;   // true
    return 0;       // false
};

/***************************************************************************/
/*                                                                         */
/*                               RawDAC                                    */
/*                                                                         */
/***************************************************************************/
void RawDAC(unsigned short nAxis, long lCounts)
{
    unsigned short nCounts;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    if ( nAxis > 7 )        // is axis within range?
       return;

    // input / output:
    //
    //    lCounts (decimal) ... -lCounts ... +0x1000 ... volts
    //
    //     0x1000  (4096)     0xfffff000           0       +10
    //          0                      0      0x1000         0
    // 0xfffff001 (-4095)          0xfff      0x1fff       -10

    // So, the domain might be different than you expected. I expected:
    //     0xf000 (-4096)  to  0xfff (4095), rather than
    //     0xf001 (-4095)  to 0x1000 (4096)

    // reverse slope so positive counts give positive voltage
    lCounts = - lCounts;
    
    // shift for DAC
    lCounts += 0x1000;
    
    if (lCounts > 0x1FFF)    // clamp + output
    {
        lCounts = 0x1FFF;
    }
    if (lCounts < 0)         // clamp - output
    {
        lCounts = 0;
    }

    if (StgController.wNoBoardFlag == NO_BOARD)      // are we simulating?
    {
        StgController.lSimDac[nAxis] = lCounts;
        return;
    }

	nCounts = (unsigned short) (lCounts + 0x1000); // correct range for DAC

    fOutPW(StgController.wBaseAddress + DAC_0 + (nAxis << 1), (unsigned short)lCounts);
};

/***************************************************************************/
/*                                                                         */
/*                               MotSim                                    */
/*                                                                         */
/***************************************************************************/
// a motor simulator
//
// takes it's input from lSimDac[]
// writes it's output to lSimEnc[]
//
// This isn't used in the DOS program, it's only used in the Windows 95 driver

void MotSim(void)
{
	static long lState_1[MAX_AXIS] = {0};                    // state variables
    long lScaledUp;
    const short nScale = 10;
	int nAxis;

    for (nAxis = 0; nAxis < MAX_AXIS; nAxis++)
    {
        // The input is guaranteed to be +/- 12 bits
        // Scale up state so we don't loose resolution
        lScaledUp = StgController.lSimDac[nAxis] << nScale;

        // note: I assume right shift is sign preserving (for signed value)

        // lag
        lState_1[nAxis] += (lScaledUp - lState_1[nAxis]) >> (4 + nAxis); //lint !e704
                                                          //   ^^^^^^^ time constant
                                                          // is different for each axis 

        // integrator (shift out the scale factor and then some)
        StgController.lSimEnc[nAxis] += lState_1[nAxis] >> (nScale + 1);               //lint !e704
    }
};

/***************************************************************************/
/*                                                                         */
/*                              StartADC                                   */
/*                                                                         */
/***************************************************************************/
void StartADC(unsigned short wAxis)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    if (wAxis > 7)
        return;

    if (StgController.wModel == MODEL1)
    {
        // do a dummy read from the ADC, just to set the input multiplexer to
        // the right channel
        fInPW(StgController.wBaseAddress + ADC_0 + (wAxis << 1));        //lint !e534

        // wait 4 uS for settling time on the multiplexer and ADC
        // you probably shouldn't really have a delay in
        // a driver.
        Timer2Delay(28);

        // now start conversion.
        fOutPW(StgController.wBaseAddress + ADC_0 + (wAxis << 1), 0);
    }
    else  // Model 2
    {
        unsigned char Cntrl0;

        Cntrl0 = fInP(StgController.wBaseAddress + CNTRL0) & 0x07;  // save irq

        Cntrl0 |= (wAxis << 4) | 0x88;  // shift bits to AD2, AD1, AD0
                                        // set bit 0x80 high for autozero
                                        // set bit 0x08 high, not calibrating
        fOutP(StgController.wBaseAddress + CNTRL0, Cntrl0);  // select ADC channel

        // don't have to do a dummy read for a model 2

        // wait 4 uS for settling time on the multiplexer and ADC
        // you probably shouldn't really have a delay in
        // a driver.
        Timer2Delay(28);

        // now start conversion.
        fOutPW(StgController.wBaseAddress + ADC, 0);

    }
};

void AutoZeroAdc(void)
{
    // set the Analog to Digital converter to autozero on each conversion

    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + INTC, fInP(StgController.wBaseAddress + INTC) & ~AUTOZERO);
    else   // MODEL2
        fOutP(StgController.wBaseAddress + CNTRL0, fInP(StgController.wBaseAddress + CNTRL0) | CNTRL0_AZ);
};

void DontAutoZeroAdc(void)
{
    // set the Analog to Digital converter to NOT autozero

    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + INTC, fInP(StgController.wBaseAddress + INTC) | AUTOZERO);
    else   // MODEL2
        fOutP(StgController.wBaseAddress + CNTRL0, fInP(StgController.wBaseAddress + CNTRL0) & ~CNTRL0_AZ);
};

void CalADC(void)
{
    // Start calibration cycle on ADC chip

    unsigned char Cntrl0;

    if (StgController.wModel == MODEL2)   // this function only in Model 2 board.
    {
        Cntrl0 = fInP(StgController.wBaseAddress + CNTRL0) & 0x07;       // save irq
        fOutP(StgController.wBaseAddress + CNTRL0, Cntrl0);              // cal is low
        // cal pulse should be 60 ns.  The ISA bus is 10 MHz. or 100 ns.
        // so we can just set it back high.
        fOutP(StgController.wBaseAddress + CNTRL0, Cntrl0 | 0x08);       // cal is high
    }
};

/***************************************************************************/
/*                                                                         */
/*                               RawADC                                    */
/*                                                                         */
/***************************************************************************/
short SpinReadADC(unsigned short wAxis)
{
    short counts, j;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return 0;
    }

    if (wAxis > 7)
         return -1;

    if (StgController.wModel == MODEL1)
    {
        // make sure conversion is done, assume polling delay is done.
        // EOC (End Of Conversion) is bit 0x08 in IIR (Interrupt Request
        // Register) of Interrupt Controller.  Don't wait forever though
        // bail out eventually.

        for (j = 0; (!(CurrentIRR() & 0x08)) && (j < 10000); j++);

        counts = ( fInPW(StgController.wBaseAddress + ADC_0 + (wAxis << 1)) );
    }
    else
    {
        // is the conversion done?
        for (j = 0; (fInP(StgController.wBaseAddress + BRDTST) & BRDTST_EOC) && (j < 10000); j++);

        // conversion is done, get counts.
        counts = fInPW(StgController.wBaseAddress + ADC);
    }

    if (counts & 0x1000)       // is sign bit negative?
        counts |= 0xf000;      // sign extend
    else
        counts &= 0xfff;       // make sure high order bits are zero.

    return counts;
};

long ReadADC(unsigned short wAxis, short *counts)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return STG_SUCCESS;
    }

    if (wAxis > 7)
         return STG_FAILURE;

    if (StgController.wModel == MODEL1)
    {
        if ( !(CurrentIRR() & 0x08) ) // is the conversion done?
            return STG_FAILURE;                  // no, return failure

        // conversion is done, get counts.
//        counts = fInPW(wBaseAddress + ADC_0 + (wAxis << 1));
//        counts = fInPW(wBaseAddress + ADC_1);  // debug
    }
    else  // Model 2
    {
        // is the conversion done?
        if ( fInP(StgController.wBaseAddress + BRDTST) & BRDTST_EOC )
            return STG_FAILURE;                 // no, return failure

        // conversion is done, get counts.
//        counts = fInPW(wBaseAddress + ADC_1);
    }

    *counts = fInPW(StgController.wBaseAddress + ADC_0 + (wAxis << 1));

    if (*counts & 0x1000)       // is sign bit negative?
        *counts |= 0xf000;      // sign extend
    else
        *counts &= 0xfff;       // make sure high order bits are zero.

    return STG_SUCCESS;

};

/***************************************************************************/
/*                                                                         */
/*                             EncoderInit                                 */
/*                                                                         */
/***************************************************************************/
//
// sets global variable: wAxesInSys
//
void EncoderInit(void)
{
	unsigned short wAdd, wA;
    LONGBYTE enc[8];

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        StgController.wAxesInSys = MAX_AXIS;
        return;
    }

    // It is possible that the encoder counts are being held by battery
    // backup, so we'll read the encoders, and save the values
    // Then we'll initialize the encoder chips, since it's more likely that
    // the ecoders were not kept alive by battery and need to be initialized

    EncReadAll(&enc);

    // probably the right thing is to sign extend the 24 bits, so, instead
    // of a 24 bit unsigned count, we have +/- 23 bits.

//    for ( i = 0; i < 8; i++)
//    {
//        byEncHighByte[i] = enc[i].Byte[2] & 0x80 ? 0xff : 0;
//        byOldByte2[i] = enc[i].Byte[2];
//    }

    for (wAdd = StgController.wBaseAddress + CNT0_C;
                                 wAdd <= StgController.wBaseAddress + CNT6_C; wAdd +=4)
    {
        // we're going to be slick and do two chips at a time, that's why
        // the registers are arranged data, data, control, control.  You
        // can do two at a time, by using word operations, instead of
        // byte operations.  Not a big deal for initializing, but reading is
        // done pretty often.

        fOutPW(wAdd, 0x2020);   // master reset

        // Set Counter Command Register - Input Control, OL Load (P3),
        // and Enable Inputs A and B (INA/B).

        fOutPW(wAdd, 0x6868);

        // Set Counter Command Register - Output Control

        fOutPW(wAdd, 0x8080);

        // Set Counter Command Register - Quadrature

        fOutPW(wAdd, 0xc3c3);

        fOutPW(wAdd, 0x0404);  //reset counter to zero
    }

    //  Figure out how many axes are on the card

    for (wA = StgController.wBaseAddress + CNT0_D; wA <= StgController.wBaseAddress + CNT6_D; wA +=4)
    {
        unsigned short const wTestPat = 0x5aa5;

        // reset address pointer

        fOutPW(wA + 2, 0x0101);

        // write a pattern to the preset register

        fOutPW(wA, wTestPat);
        fOutPW(wA, wTestPat);
        fOutPW(wA, wTestPat);

        // transfer the preset register to the count register

        fOutPW(wA + 2, 0x0909);

        // transfer counter to output latch

        fOutPW(wA + 2, 0x0202);

        // read the output latch and see if it matches

        if (fInPW(wA) != wTestPat)
            break;
        if (fInPW(wA) != wTestPat)
            break;
        if (fInPW(wA) != wTestPat)
            break;

        // now replace the values that you saved previously, in case the
        // encoder was battery backed up

        fOutP(wA, enc[StgController.wAxesInSys].Byte[0]);
        fOutP(wA, enc[StgController.wAxesInSys].Byte[1]);
        fOutP(wA, enc[StgController.wAxesInSys].Byte[2]);

        fOutP(wA + 1, enc[StgController.wAxesInSys + 1].Byte[0]);
        fOutP(wA + 1, enc[StgController.wAxesInSys + 1].Byte[1]);
        fOutP(wA + 1, enc[StgController.wAxesInSys + 1].Byte[2]);

        // transfer the preset register to the count register

        fOutPW(wA + 2, 0x0909);

        // transfer counter to output latch  debug

        fOutPW(wA + 2, 0x0202);  // debug

        StgController.wAxesInSys += 2;

        // write zeros to preset register, we don't want to do a master reset
        // (MRST), because then we would need to re-initialize the counter

//        fOutPW(wA, 0);
//        fOutPW(wA, 0);
//        fOutPW(wA, 0);

        // reset counter, BRW and CRY and address pointer (RADR)

//        fOutPW(wA + 2, 0x0505);
    }
};

/***************************************************************************/
/*                                                                         */
/*                             EncReadAll                                  */
/*                                                                         */
/***************************************************************************/
void EncReadAll(LONGBYTE *lbEncPtr)
{
    WORDBYTE wbTransfer;
//    static unsigned char byOldByte2[MAX_AXIS];
//    static unsigned char byEncHighByte[MAX_AXIS];
    short i;
	int add;
	LONGBYTE lbEnc[8];

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        for (i = 0; i < 8; i++)
        {
            lbEnc[i].Long = StgController.lSimEnc[i];
        }
        return;
    }

    // Disable interrupts here?  No, the timer will latch new data in the
    // hardware anyway.  Maybe we should stop the timer?  In an interrupt
    // service routine, you're synchronized with the timer; so the readings
    // will never change while you're reading them.  If you're polling, you
    // would first latch the encoder counts with the EncoderLatch() function.
    // But, the timer could latch the counts again, in the middle of the read.
    // A critical section will help in some extreme cases.

    // reset counter internal addr ptr to point to first byte
    for (add = StgController.wBaseAddress + CNT0_C; add <= StgController.wBaseAddress + CNT6_C; add +=4)
        fOutPW(add, 0x0101);

    for (i = 0; i < 3; i++)            // 24 bits means get 3 bytes each
    {
        wbTransfer.Word = fInPW(StgController.wBaseAddress + CNT0_D);

        lbEnc[0].Byte[i] = wbTransfer.Byte.high;
        lbEnc[1].Byte[i] = wbTransfer.Byte.low;

        wbTransfer.Word = fInPW(StgController.wBaseAddress + CNT2_D);

        lbEnc[2].Byte[i] = wbTransfer.Byte.high;
        lbEnc[3].Byte[i] = wbTransfer.Byte.low;

        wbTransfer.Word = fInPW(StgController.wBaseAddress + CNT4_D);

        lbEnc[4].Byte[i] = wbTransfer.Byte.high;
        lbEnc[5].Byte[i] = wbTransfer.Byte.low;

        wbTransfer.Word = fInPW(StgController.wBaseAddress + CNT6_D);

        lbEnc[6].Byte[i] = wbTransfer.Byte.high;
        lbEnc[7].Byte[i] = wbTransfer.Byte.low;
    }

    // maintain the high byte, to extend the counter to 32 bits
    //
    // base decisions to increment or decrement the high byte
    // on the highest 2 bits of the 24 bit value.  To get the
    // highest 2 bits, use 0xc0 as a mask on byte [2] (the third
    // byte).

    for (i = 0; i < MAX_AXIS; i++)
    {
        // check for -1 to 0 transition

        if (    ( (StgController.byOldByte2[i]    & 0xc0) == 0xc0 ) // 11xxxxxx
             && ( (lbEnc[i].Byte[2] & 0xc0) == 0 )    // 00xxxxxx
           )
           StgController.byEncHighByte[i]++;

        // check for 0 to -1 transition

        if (    ( (StgController.byOldByte2[i]    & 0xc0) == 0 )    // 00xxxxxx
             && ( (lbEnc[i].Byte[2] & 0xc0) == 0xc0 ) // 11xxxxxx
           )
           StgController.byEncHighByte[i]--;

        lbEnc[i].Byte[3] = StgController.byEncHighByte[i];
        StgController.byOldByte2[i] = lbEnc[i].Byte[2];    // current byte 2 becomes old one
    }
	for (i = 0; i < 8; i++)
		*(lbEncPtr+i) = lbEnc[i];
};

/***************************************************************************/
/*                                                                         */
/*                            SetEncoderCounts                             */
/*                                                                         */
/***************************************************************************/
void SetEncoderCounts(unsigned short nAxis, long lCounts)
{
    unsigned short wAddress;
    char *ByteUnion = (char *)&lCounts;  // get pointer to lCounts, so you
                                         // can take it apart byte by byte

    wAddress = StgController.wBaseAddress + CNT0_D;
    wAddress += (nAxis & 0x6) << 1; // shift to multiply by 2
                                    // pairs of data regs seperated by pairs
                                    // of control regs, skip over control.
    wAddress += nAxis & 1;
    fOutP(wAddress, ByteUnion[0]);
    fOutP(wAddress, ByteUnion[1]);
    fOutP(wAddress, ByteUnion[2]);

    // transfer the preset register to the count register
    fOutP(wAddress + 2, 0x09);

    // set things for the part that extends the 24 bit counter
    // to 32 bits.
    StgController.byEncHighByte[nAxis] = ByteUnion[3];
    StgController.byOldByte2[nAxis] = ByteUnion[2];
};

/***************************************************************************/
/*                                                                         */
/*                            EncoderLatch                                 */
/*                                                                         */
/***************************************************************************/
void EncoderLatch(void)
{
	unsigned short wAdd;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

   // normally you'll have the timer latch the data in hardware, but
   // if the timer isn't running, we need to latch it ourselves.

   for (wAdd = StgController.wBaseAddress + CNT0_C; wAdd <= StgController.wBaseAddress + CNT6_C; wAdd +=4)
       fOutPW(wAdd, 0x0202);
};

/***************************************************************************/
/*                                                                         */
/*                          EncoderResetAddr                               */
/*                                                                         */
/***************************************************************************/
void EncoderResetAddr(void)
{
	unsigned short wAdd;

    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

   // This function resets all the counter's internal address pointers to point
   // to the first byte in the 3 byte sequence

   for (wAdd = StgController.wBaseAddress + CNT0_C; wAdd <= StgController.wBaseAddress + CNT6_C; wAdd +=4)
       fOutPW(wAdd, 0x0101);
};

/***************************************************************************/
/*                                                                         */
/*                          SelectIndexAxis                                */
/*                       SelectIndexOrExtLatch                             */
/*                                                                         */
/***************************************************************************/
void SelectIndexAxis(unsigned char byAxis)
{
    // routine for Model 1

    // overloaded function.  Use this if you don't need to set polarity

    SelectIndexAxis2(byAxis, StgController.byIndexPulsePolarity);
};

void SelectIndexAxis2(unsigned char byAxis, unsigned char byPol)
{
    // routine for Model 1

    //
    // initialize stuff to poll index pulse
    //
    unsigned char byIntc;

    StgController.byIndexPollAxis = byAxis;           // save axis to check later
    StgController.byIndexPulsePolarity = byPol;       // save polarity as new default
    byAxis &= 0x6;                      // ignore low bit, we check 2 axes at a time
    byAxis <<= 3;                       // shift into position for IXS1, IXS0
    byIntc = fInP(StgController.wBaseAddress + INTC); // get a copy of INTC, we'll change
                                        // some bits in it, not all
    byIntc &= ~(IXLVL | IXS1 | IXS0);   // zero bits for axis and polarity
    byIntc |= byAxis;                   // put axes address in INTC
    if (byPol != 0)                     // is index pulse active high?
        byIntc |= IXLVL;
    fOutP(StgController.wBaseAddress + INTC, byIntc);
    ResetIndexLatch();

    // The latched index pulse should be low now.  If it's not, either something's
    // wrong, or we happened to initialize it while the index pulse was active.
};

void SelectIndexOrExtLatch(unsigned char bySelectBits)
{
    // routine for Model 2

    fOutP(StgController.wBaseAddress + SELDI, bySelectBits);
};

void EnableCounterLatchOnIndexOrExt(unsigned char bySelectBits)
{
    // routine for Model 2
    fOutP(StgController.wBaseAddress + IDLEN, bySelectBits);
};

/***************************************************************************/
/*                                                                         */
/*                          ResetIndexLatch(es)                            */
/*                                                                         */
/***************************************************************************/
void ResetIndexLatch()
{
    // routine for Model 1

    fInP(StgController.wBaseAddress + ODDRST);        //lint !e534 reset index pulse latch for ODD axis
    fInP(StgController.wBaseAddress + BRDTST);        //lint !e534 reset index pulse latch for EVEN axis
};

void ResetIndexLatches(unsigned char byLatchBits)
{
    // routine for Model 2
    fOutP(StgController.wBaseAddress + IDL, byLatchBits);
};

/***************************************************************************/
/*                                                                         */
/*                        (Get)IndexPulseLatch(es)                         */
/*                                                                         */
/***************************************************************************/
unsigned short IndexPulseLatch(void)
{
    // routine for Model 1 board

    // poll the latched index pulse of the axis that was previously set up

    // unsigned char byIRR, byAxisMask;

    // byIRR = CurrentIRR();
    // byAxisMask = (byIndexPollAxis & 1) ? LIXODD : LIXEVN;  // even or odd axis?
    // if (byIRR & byAxisMask)                          // check latched index pulse
    //     return 1;
    // return 0;

    //
    // a faster, but messier way
    //
    if (StgController.wModel == MODEL1)
    {
        fOutP(StgController.wBaseAddress + OCW3, 0x0a);           // IRR on next read

        return (   fInP(StgController.wBaseAddress + IRRreg)
                 & ( (StgController.byIndexPollAxis & 1) ? LIXODD : LIXEVN ) // mask for even or odd
               );
    }
    else  // MODEL 2
        return 0;
};

unsigned char GetIndexLatches()
{
    // routine for Model 2 board

    return fInP(StgController.wBaseAddress + IDL);
};

unsigned char GetSELDI()
{
    return fInP(StgController.wBaseAddress + SELDI);
};

unsigned char GetIDLEN()
{
    return fInP(StgController.wBaseAddress + IDLEN);
};

unsigned char GetCNTRL0()
{
    return fInP(StgController.wBaseAddress + CNTRL0);
};

unsigned char GetCNTRL1()
{
    return fInP(StgController.wBaseAddress + CNTRL1);
};

/***************************************************************************/
/*                                                                         */
/*                            IndexPulse                                   */
/*                                                                         */
/***************************************************************************/
short IndexPulse(void)
{
    // poll for the index pulse of the axis that was previously set up.
    // Normally you would look at the latched pulse.  This function will
    // probably only get used during testing.
    
    unsigned char byIRR, byAxisMask;

    byIRR = CurrentIRR();
    byAxisMask = (StgController.byIndexPollAxis & 1) ? IXODD : IXEVN;  // even or odd axis?

    // The raw index pulse isn't inverted by the hardware if the index pulse is
    // low active (only the latched pulse is).  For consistancy, we'll invert
    // the pulse in software.

    if (StgController.byIndexPulsePolarity == 0)                       // if pulse is low true
        byIRR ^= byAxisMask;                             // flip bit

    if (byIRR & byAxisMask)                              // check index pulse
        return 1;
    return 0;
};

/***************************************************************************/
/*                                                                         */
/*                             CurrentIRR                                  */
/*                                                                         */
/***************************************************************************/
unsigned char CurrentIRR(void)
{
    fOutP(StgController.wBaseAddress + OCW3, 0x0a);           // IRR on next read
    return fInP(StgController.wBaseAddress + IRRreg);
};

/***************************************************************************/
/*                                                                         */
/*                        SelectInterruptPeriod                            */
/*                                                                         */
/***************************************************************************/
void SelectInterruptPeriod(long lPeriodSelect)
{
   if (StgController.wNoBoardFlag == NO_BOARD)
   {
       return;
   }

   if (lPeriodSelect != MAX_PERIOD)
   {
       fOutP(StgController.wBaseAddress + TMRCMD, 0x56);   // timer 1, read/load LSB (MSB is 0)
                                             // mode 3 (square wave)
       fOutP(StgController.wBaseAddress + TIMER_1, 0xb4);  // 0xb4 = 180 -> 25 uSec period
   }
   else
   {
       fOutP(StgController.wBaseAddress + TMRCMD, 0x76);   // timer 1, read/load LSB then MSB
                                             // mode 3 (square wave)
       fOutP(StgController.wBaseAddress + TIMER_1, 0xff);  // LSB
       fOutP(StgController.wBaseAddress + TIMER_1, 0xff);  // MSB
   }

   switch (lPeriodSelect)
   {
        case _500_MICROSECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x14);   // 0x14 = 20 = .5 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);  
            break;
        case _1_MILLISECOND:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x28);   // 0x28 = 40 = 1 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);
            break;
        case _2_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x50);   // 0x50 = 80 = 2 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);
            break;
        case _3_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x78);   // 0x78 = 120 = 3 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);  
            break;
        case _4_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0xA0);   // 0xA0 = 160 = 4 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);
            break;
        case _5_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0xC8);   // 0xC8 = 200 = 5 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x00);  
            break;
        case _10_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x90);   // 0x0190 = 400 = 10 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x01);  
            break;
        case _100_MILLISECONDS:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0xA0);   // 0x0FA0 = 4000 = 100 mS
            fOutP(StgController.wBaseAddress + TIMER_0, 0x0F);
            break;
        case _1_SECOND:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0x40);   // 0x9C40 = 40000 = 1 S
            fOutP(StgController.wBaseAddress + TIMER_0, 0x9c);  
            break;
        case MAX_PERIOD:
            fOutP(StgController.wBaseAddress + TMRCMD, 0x34);    // timer 0, read/load LSB followed by
                                                   // MSB, mode 2 (real-time interrupt)
            fOutP(StgController.wBaseAddress + TIMER_0, 0xff);   // LSB
            fOutP(StgController.wBaseAddress + TIMER_0, 0xff);   // MSB
            break;
        default:
            // wrong input? then don't change it
            break;
   }
};

/***************************************************************************/
/*                                                                         */
/*                             StopTimer                                   */
/*                                                                         */
/***************************************************************************/
void StopTimer()
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    // stop the timer by putting it into one shot mode, it will never get
    // a trigger

    fOutP(StgController.wBaseAddress + TMRCMD, 0x02);    // timer 0, mode 1
};

/***************************************************************************/
/*                                                                         */
/*                           Timer2 functions                              */
/*                                                                         */
/***************************************************************************/
void Timer2Delay(unsigned short counts)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    StartTimer2TerminalCount(counts);

    while (PollTimer2());
};

void StartTimer2TerminalCount(unsigned short count)
{
	char *pByte;

   if (StgController.wNoBoardFlag == NO_BOARD)
   {
       return;
   }

   //*pByte = (char *)&count;
   pByte = (char *)&count;
   fOutP(StgController.wBaseAddress + TMRCMD, 0xb0);       // timer 2, read/load LSB followed
                                             // by MSB, mode 0 (terminal count)
   fOutP(StgController.wBaseAddress + TIMER_2, *pByte++);  // LSB (little endian)
   fOutP(StgController.wBaseAddress + TIMER_2, *pByte);    // MSB
};

void StartTimer2RTI(unsigned short count)
{
   char *pByte;

	if (StgController.wNoBoardFlag == NO_BOARD)
   {
       return;
   }

   //*pByte = (char *)&count;
   pByte = (char *)&count;
   fOutP(StgController.wBaseAddress + TMRCMD, 0xb4);       // timer 2, read/load LSB followed
                                             // by MSB, mode 2 (real time int).
   fOutP(StgController.wBaseAddress + TIMER_2, *pByte++);  // LSB (little endian)
   fOutP(StgController.wBaseAddress + TIMER_2, *pByte);    // MSB
};

unsigned short ReadTimer2TerminalCount(void)
{
    unsigned short count;
    char *pByte;
	
	//*pByte = (char *)&count;
	pByte = (char *)&count;
    fOutP(StgController.wBaseAddress + TMRCMD, 0x80);       // timer 2, latch
    *pByte++ = fInP(StgController.wBaseAddress + TIMER_2);  // LSB
    *pByte   = fInP(StgController.wBaseAddress + TIMER_2);  // MSB
    return count;
};

short PollTimer2(void)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return 0;
    }

    if (StgController.wModel == MODEL1)
        return !(CurrentIRR() & TP2);  // mask selects bit for TP2
    else   // MODEL 2
    {
        unsigned char byRegCntrl1, byNewCntrl1;

        byRegCntrl1 = fInP(StgController.wBaseAddress + CNTRL1);
        if (byRegCntrl1 & CNTRL1_INT_T2)
        {
            // If it's set, we want to reset the latch, by writing a zero
            // to CNTRL1_INT_T2.

            // When we write to CNTRL1, we don't want to change SLAVE, IEN_G2
            // IEN_T2, or IEN_T0 -- the lower 4 bits.  So, we start with

            byNewCntrl1 = byRegCntrl1 & 0x0f;     // (0000xxxx)

            // We don't want to reset WDTOUT, INT_G2, or INT_T0--we only want
            // to reset ...T2. (1101xxxx)

            byNewCntrl1 |= CNTRL1_WDTOUT | CNTRL1_INT_G2 | CNTRL1_INT_T0;

            fOutP(StgController.wBaseAddress + CNTRL1, byNewCntrl1);  // reset bit

            return 1;  // true
        }
    }
    return 0;      // false
};

void MaskTimer2Interrupt()
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }

    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + OCW1, CurrentIRR() | TP2);
    else   // Model 2
        // we want to save the state of the slave mode, and set the
        // high nibble bits high, so you don't reset any latches.
        // bit pattern: 1111x000  where x is don't change
        fOutP(StgController.wBaseAddress + CNTRL1,
            (fInP(StgController.wBaseAddress + CNTRL1) & CNTRL1_NOT_SLAVE) | 0xf0);
};

void UnMaskTimer2Interrupt()
{
    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + OCW1, CurrentIRR() & ~TP2);
    else   // Model 2
    {
        // we want to save the state of the slave mode, and set the
        // high nibble bits high, so you don't reset any latches.
        // bit pattern: 1111x010 where x is don't change
        fOutP(StgController.wBaseAddress + CNTRL1,
            (fInP(StgController.wBaseAddress + CNTRL1) & CNTRL1_NOT_SLAVE) | CNTRL1_IEN_T2);
    }
};

/***************************************************************************/
/*                                                                         */
/*                           StartInterrupts                               */
/*                                                                         */
/***************************************************************************/
void StartInterrupts(void)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }
    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + OCW1, ~0x04);   // enable interrupt for timer 0
    else  // MODEL2
        // we want to save the state of the slave mode, and set the
        // high nibble bits high, so you don't reset any latches.
        // 1111x001, where x means don't change
    {
        fOutP(StgController.wBaseAddress + CNTRL1, CNTRL1_IEN_T0 | CNTRL1_NOT_SLAVE);
    }
};

/***************************************************************************/
/*                                                                         */
/*                           StopInterrupts                                */
/*                                                                         */
/***************************************************************************/
void StopInterrupts(void)
{
    if (StgController.wNoBoardFlag == NO_BOARD)
    {
        return;
    }
    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + OCW1, 0xff);     // disable all interrupts
    else  // MODEL2
        // we want to save the state of the slave mode, and set the
        // high nibble bits high, so you don't reset any latches.
        // disable all interrupts, since only one can be enabled at
        // a time (currently).  If more than one was enabled, it's
        // an error (currently).
        // 1111x000, where x means not changed.
        fOutP(StgController.wBaseAddress + CNTRL1,
            (fInP(StgController.wBaseAddress + CNTRL1) & CNTRL1_NOT_SLAVE) | 0xf0);
};

/***************************************************************************/
/*                                                                         */
/*                             BaseFind                                    */
/*                                                                         */
/***************************************************************************/

// find the base address of the Servo To Go board

unsigned short BaseFind(void)
{
   short i;
   unsigned short io_add;

   for (i = 15; i >= 0; i--)                    // search all possible addresses
   {
       io_add = i * 0x20 + 0x200;
       if ( BrdtstOK(io_add) )
        return io_add;
   }
   return(0);
};

/***************************************************************************/
/*                                                                         */
/*                             BrdtstOK                                    */
/*                                                                         */
/***************************************************************************/

// check the board test register, figure out board model

unsigned short BrdtstOK(unsigned short BaseAddress)
{
	unsigned short BrdtstAddress;
    unsigned short SerSeq, HighNibble;
	int j;

    BrdtstAddress = BaseAddress + BRDTST;

    SerSeq = 0;
    for (j = 7; j >= 0; j--)
    {
        HighNibble = fInP(BrdtstAddress) >> 4;
        if (HighNibble & 8)     // is SER set
        {
           // shift bit to position specifed by Q2, Q1, Q0
           // which are the lower three bits.  Put bit in SerSeq.
           SerSeq |= 1 << (HighNibble & 7);
        }
    }
    if (SerSeq == 0x75)        // SER sequence is 01110101
    {
        StgController.wModel = MODEL1;
        return 1;              //true
    }
    if (SerSeq == 0x74)        // SER sequence is 01110100
    {
        StgController.wModel = MODEL2;
        return 1;              // true
    }
    StgController.wModel = MODEL_NO_ID;
    return 0;  // false
};

/***************************************************************************/
/*                                                                         */
/*                             Initialize                                  */
/*                                                                         */
/***************************************************************************/
void Initialize(unsigned short wRequestedIrq)
{
  /*
   * First find the the base I/O address of the board.
   *
   * only do this in the DOS example.  It's dangerous under 95, and can't be
   * done under NT
   */
   //wBaseAddress = BaseFind();
   //if (wBaseAddress == 0)
   //{
   //    wNoBoardFlag = NO_BOARD;
   //}
   //wNoBoardFlag = BOARD_PRESENT;
   
  /*
   * Initialize the interrupt controller
   */
   if (StgController.wModel == MODEL1)
   {
   fOutP(StgController.wBaseAddress + MIO_2, 0x92);  // initialize INTC as output reg.
                                       // sets port D to input since we have
                                       // to set it to something.
   SetIrq(wRequestedIrq);              // selects the IRQ in INTC. Now, if a stray
                                       // interrupt is issued (see below) it will
                                       // go to an interrupt that isn't enabled on
                                       // the motherboard yet (if your system is
                                       // set up correctly).
   fOutP( StgController.wBaseAddress + ICW1, 0x1a ); // initialize 82C59 as single chip,
                                       // level triggered
   fOutP( StgController.wBaseAddress + ICW2, 0x00 ); // icw2 - not used, must write
                                       // could issue stray interrupt here - danger!
   fOutP( StgController.wBaseAddress + OCW1, 0xff);  // mask off all interrupt sources (the
                                       // interrupt on the motherboard isn't
                                       // enabled yet, you do that when you install
                                       // your interrupt handler.).
   }
   else   // must be a Model 2
   {
   fOutP(StgController.wBaseAddress + MIO_2, 0x8b);  // initialize CNTRL0 as output reg.
                                       // BRDTST to input.
                                       // sets port D, high and low, to input
                                       // since we have to set it to something.
   SetIrq(wRequestedIrq);              // selects the IRQ in CNTRL0. Now, if a stray
                                       // interrupt is issued (see below) it will
                                       // go to an interrupt that isn't enabled on
                                       // the motherboard yet (if your system is
                                       // set up correctly).
   }
};

/***************************************************************************/
/*                                                                         */
/*                              SetIrq                                     */
/*                                                                         */
/***************************************************************************/
void SetIrq(unsigned short wRequestedIrq)
{
    unsigned char byIntReg;

    if (StgController.wNoBoardFlag == NO_BOARD)
        return;

    StgController.wIrq = wRequestedIrq;  // assume it's OK for now, check later

    if (StgController.wModel == MODEL1)
        byIntReg = 0x80;       // initial value for the high bits in the register
                               // sets auto zero off
    else   // MODEL2
        byIntReg = 0x88;       // cal high too, not calibrating ADC

    // now put low bits into byIntReg to select irq

    switch (wRequestedIrq)
    {
        case 3: break;      // add zero

        case 5: byIntReg |= 4;
                break;

        case 7: byIntReg |= 2;
                break;

        case 9: byIntReg |= 6;
                break;

        case 10: byIntReg |= 5;
                 break;

        case 11: byIntReg |= 7;
                 break;

        case 12: byIntReg |= 3;
                 break;

        case 15: byIntReg |= 1;
                 break;

        default: StgController.wIrq = 5;      // ERROR, requested irq not valid, use 5
                 byIntReg |= 4; // There is no safe value, leaving zero
                                // here would select IRQ 3 which is worse
                                // than 5 because IRQ 3 is usually for COM 2
                 break;
    }

    if (StgController.wModel == MODEL1)
        fOutP(StgController.wBaseAddress + INTC, byIntReg);  // set irq
    else   // MODEL2
        fOutP(StgController.wBaseAddress + CNTRL0, byIntReg);
};

BOOL AddressInRange(long a)
{
    if ( (     ( (a >= StgController.wBaseAddress)         & (a < StgController.wBaseAddress + 0x20 ) )
            || ( (a >= StgController.wBaseAddress + 0x400) & (a < StgController.wBaseAddress + 0x420) )
         )
         && (StgController.wBaseAddress != 0)
       )
       return 1;	//true
    return 0;		//false
};