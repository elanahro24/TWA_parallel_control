#ifndef _STGMEMBS_H_
#define _STGMEMBS_H_

#include "stgdefs.h"

//extern struct ServoToGo StgController;

extern void Initialize(unsigned short wRequestedIrq);
extern void SetIrq(unsigned short wRequestedIrq);
extern unsigned short BaseFind(void);
extern unsigned short BrdtstOK(unsigned short wBaseAddress);
extern void SetDDir(unsigned short nSwDir);
extern void MotSim(void);
extern void ServoToGo_Constructor(void);
extern void ServoToGo_Constructor2(unsigned short wRequestedIrq);
extern void ServoToGo_Destructor(void);
extern void Stg_Init(unsigned short wRequestedIrq, unsigned short wAdd);
extern void DioDirection2(unsigned short nPortBits, unsigned short nDirection);
extern void DioDirection(const unsigned short nSwDir);
extern void SetDDir(unsigned short nSwDir);
extern void RawDO(unsigned long lOutBits);
extern void RawDO2(unsigned char byData, short nPort);
extern void RawDO3(unsigned char byBitNumber, unsigned char bySet0or1, unsigned short nPort);
extern short PortBits2Index(short nPort);
extern void DigitalOut2(unsigned char byData, short nPortBits);
extern void DigitalOut3(unsigned char byBitNumber, unsigned char bySet0or1, unsigned short nPortBits);
extern unsigned long RawDI();
extern unsigned char RawDI2(unsigned char byBitNumber, short nPort);
extern unsigned char RawDI1(short nPort);
extern unsigned long RawDI2b(long lPort, long lBitNumber);
extern void RawDAC(unsigned short nAxis, long lCounts);
extern void StartADC(unsigned short wAxis);
extern void AutoZeroAdc(void);
extern void DontAutoZeroAdc(void);
extern void CalADC(void);
extern short SpinReadADC(unsigned short wAxis);
extern long ReadADC(unsigned short wAxis, short *counts);
extern void EncoderInit(void);
extern void EncReadAll(LONGBYTE *lbEnc);
extern void SetEncoderCounts(unsigned short nAxis, long lCounts);
extern void EncoderLatch(void);
extern void EncoderResetAddr(void);
extern void SelectIndexAxis(unsigned char byAxis);
extern void SelectIndexAxis2(unsigned char byAxis, unsigned char byPol);
extern void SelectIndexOrExtLatch(unsigned char bySelectBits);
extern void ResetIndexLatch();
extern void ResetIndexLatches(unsigned char byLatchBits);
extern unsigned short IndexPulseLatch(void);
extern unsigned char GetIndexLatches();
extern unsigned char GetSELDI();
extern unsigned char GetIDLEN();
extern unsigned char GetCNTRL0();
extern unsigned char GetCNTRL1();
extern short IndexPulse(void);
extern unsigned char CurrentIRR(void);
extern void SelectInterruptPeriod(long lPeriodSelect);
extern void StopTimer();
extern void Timer2Delay(unsigned short counts);
extern void StartTimer2TerminalCount(unsigned short count);
extern void StartTimer2RTI(unsigned short count);
extern unsigned short ReadTimer2TerminalCount(void);
extern short PollTimer2(void);
extern void MaskTimer2Interrupt();
extern void UnMaskTimer2Interrupt();
extern void StartInterrupts(void);
extern void StopInterrupts(void);
extern unsigned short BaseFind(void);
extern unsigned short BrdtstOK(unsigned short BaseAddress);
extern void Initialize(unsigned short wRequestedIrq);
extern void SetIrq(unsigned short wRequestedIrq);
extern BOOL AddressInRange(long a);

#endif