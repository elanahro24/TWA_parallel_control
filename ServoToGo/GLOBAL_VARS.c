
#ifndef _GLOBAL_C_
#define _GLOBAL_C_


#include "C:\ServoToGo\stgdefs.h"
#include "C:\ServoToGo\irq_defs.h"
#include "C:\ServoToGo\stgmembs.h"

struct IrqDataStruct IrqData;
struct ServoToGo StgController;

main(void)
{
	int i;

	StgController.wModel = MODEL2;
	StgController.wSaveDirs = 0;
	StgController.wNoBoardFlag = NO_BOARD;
	for (i = 0; i < MAX_AXIS; i++)
	{
		StgController.lPulseCount[i] = 0;
	}
}
#endif