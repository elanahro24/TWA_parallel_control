//
// locdefs.h
//
// This file has some things specific to a given target application.
//

#ifndef _LOCDEFS_H_
#define _LOCDEFS_H_

//#define LINUX

#include "ms-or-bc.h"

#define STG_SUCCESS  0
#define STG_FAILURE  1

#define NUM_AXIS_IN_SYS     8
#define MAX_AXIS            8

//
// digital I/O port stuff
//
// begin to use the enumerated type, rather than the defines
//
typedef enum { A_dir = 0x01, B_dir = 0x02, C_lo_dir = 0x04,
               C_hi_dir = 0x08, C_dir = 0x0c, D_lo_dir = 0x10,
			   D_hiDir = 0x20, D_dir = 0x30 }   eDir_typ;
typedef enum { A_port, B_port, C_port, D_port } ePort_typ;
typedef enum { HomeSwitchFORWARD, HomeSwitchREVERSE } eHomeDir_typ;

#define STG_PORT_A        0x01
#define STG_PORT_B        0x02
#define STG_PORT_C_LO     0x04
#define STG_PORT_C_HI     0x08
#define STG_PORT_C        (STG_PORT_C_LO | STG_PORT_C_HI)
#define STG_PORT_D_LO     0x10
#define STG_PORT_D_HI     0x20
#define STG_PORT_D        (STG_PORT_D_LO | STG_PORT_D_HI)
#define STG_PORT_INPUT    0
#define STG_PORT_OUTPUT   1

#endif // _LOCDEFS_H_
