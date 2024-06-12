/*
* Servo To Go controller
*
* Copyright (c) 2000 Servo To Go Inc.
* 8117 Groton Ln.
* Indianapolis, IN 46260
*
* Version 0.1 November 1995
*/

#ifndef _STGDEFS_H_
#define _STGDEFS_H_

//#ifndef BOOL
//#define BOOL int
//#endif

#include <windows.h>
#include "offsets.h"
#include "stg_comn.h"

// hardware direction bit definitions
#define A_DIR_BIT      0x10
#define B_DIR_BIT      0x02
#define C_LOW_DIR_BIT  0x01
#define C_HI_DIR_BIT   0x08
#define D_DIR_BIT      0x10
#define D_LOW_DIR_BIT  0x01
#define D_HI_DIR_BIT   0x08

/* parameters to the SelectInterruptPeriod Command */
#define _500_MICROSECONDS        500
#define _1_MILLISECOND           1000
#define _2_MILLISECONDS          2000
#define _3_MILLISECONDS          3000
#define _4_MILLISECONDS          4000
#define _5_MILLISECONDS          5000
#define _10_MILLISECONDS         10000
#define _100_MILLISECONDS        100000L
#define _1_SECOND                1000000L
#define MAX_PERIOD               -1L

#define NO_BOARD       1
#define BOARD_PRESENT  0

#define MODEL_NO_ID    0
#define MODEL1         1
#define MODEL2         2

typedef union
{
    unsigned long               all;
    struct {unsigned char  A, B, C, D;} port;
} IO32;

typedef union
{
    long           Long;
    unsigned char  Byte[4];
} LONGBYTE;

typedef union
{
    unsigned short                          Word;
    struct   {unsigned char    high, low;}  Byte;
} WORDBYTE;


typedef struct ServoToGo
{
	
    unsigned short	wBaseAddress;
    unsigned short	wIrq;
    unsigned short	wModel;
    unsigned short	wNoBoardFlag;
    unsigned short	wAxesInSys;
    unsigned short	wSaveDirs;
    unsigned char	byIndexPollAxis;
    unsigned char	byIndexPulsePolarity;
    long			lSimDac[MAX_AXIS];
    long			lSimEnc[MAX_AXIS];
	unsigned char	byOldByte2[MAX_AXIS];
    unsigned char	byEncHighByte[MAX_AXIS];
	long			lPulseCount[MAX_AXIS];
};

#endif   // _STGDEFS_H_
