/**
 *  @file  WdgM_Cfg.c
 *
 *  @brief
 *     A brief description (one line).
 *
 *  @details
 *     [Optional] A detailed description of the function, purpose
 *     and usage of this file (more lines).
 *
 *  @author   Shuwen.Ou
 *  @version  1.0
 *  @date     2024.08.06
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2024 - 2025 ingeek shanghai, Inc.
 */

#ifdef  __cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "WdgM_Cfg.h"
#include "WdgM.h"
#include "libPrintf.h"

/*==================[internal constants]====================================*/
/*==================[internal macros]=======================================*/
/*==================[internal type definitions]=============================*/
/*==================[internal function declarations]========================*/
/*==================[internal data]=========================================*/
const WdgM_TaskConfigType WdgM_TaskConfig[WDGM_TASK_NUM] =
{
    [WdgM_RteH_Task] = {
        .timeout = 50,
        .waitDelay = 1500,
        .action = POWER_RESET,
        .timeoutCallback = NULL,
    },
    [WdgM_RteL_Task] = {
        .timeout = 50,
        .waitDelay = 1500,
        .action = POWER_RESET,
        .timeoutCallback = NULL,
    },
};

/*==================[external function definitions]=========================*/
void WdgM_TimeoutCallback(WdgM_TaskStatusType *TaskStatus)
{
    for (uint8 i = 0; i < WDGM_TASK_NUM; i++)
    {
        LIB_LEVEL_PRINTF(DEBUG_LEVEL_ERR, "WdgM_Timeout occur, Task %d: %d\n", i, TaskStatus[i].status);
    }
}
/*==================[internal function definitions]=========================*/

#ifdef  __cplusplus
}
#endif

/*==================[end of file]===========================================*/
