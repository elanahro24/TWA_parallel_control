#ifndef _IRQ_DEFS_H_
#define _IRQ_DEFS_H_

typedef struct IrqDataStruct
{
    short         IRQ;
    unsigned char IntMap;         // Offset of CPU interrupt vector
    unsigned char Mb_Mask;        // Motherboard mask
    unsigned char Mb_MaskReg;     // Address of motherboard mask register
    unsigned char Mb_ControlReg;  // Address of motherboard control register
    unsigned char SpecificEOI;
};


#endif