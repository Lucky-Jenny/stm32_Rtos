/**
 *  @file  WdgM.c
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
 
#ifdef	__cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "WdgM.h"
#include "Wdg.h"
#include "libPrintf.h"

/*==================[internal constants]====================================*/
/*==================[internal macros]=======================================*/
/*==================[internal type definitions]=============================*/
/*==================[internal function declarations]========================*/
/*==================[internal data]=========================================*/
static WdgM_StateType WdgM_State = { 0 };
static WdgM_TaskStatusType WdgM_TaskStatus[WDGM_TASK_NUM]= { 0 };

/*==================[external function definitions]=========================*/
/**
 *  @b Description
 *  @n
 *      Wdog state process and this function should be called periodly.
 *
 *  @param[in]  void

 *  @param[out] void
 *
 *  @return  void
 *
 */
void WdgM_MainFunction(void)
{
    uint8 idx_task = 0U;

    if (WdgM_State.status == WDGM_NORMAL)
    {
        Wdg_SetTriggerCondition(WDGM_TIGGER_CONDITION);

        for (idx_task = 0U; idx_task < WDGM_TASK_NUM; idx_task++)
        {
            if (WdgM_TaskStatus[idx_task].status == WDGM_TASK_READY)
            {
                WdgM_TaskStatus[idx_task].count += WDGM_TASK_PERIOD;
                if (WdgM_TaskStatus[idx_task].count >= (WdgM_TaskConfig[idx_task].timeout + 
                    WdgM_TaskConfig[idx_task].waitDelay))
                {
                    WdgM_State.status = WDGM_EVENT_TIMEOUT;
                    WdgM_State.action = (WdgM_ActionType)WdgM_TaskConfig[idx_task].action;
                    WdgM_TaskStatus[idx_task].status = WDGM_TASK_TIMEOUT;
                }
            }
        }
    }
    else if(WdgM_State.status == WDGM_EVENT_TIMEOUT)
    {
        if(WdgM_State.action == POWER_RESET)
        {
            WdgM_TimeoutCallback(WdgM_TaskStatus);
            Wdg_SetTriggerCondition(0U);
            WdgM_State.status = WDGM_RESET_EXECUTING;
        }
        else if(WdgM_State.action == DO_NOTHING)
        {
            WdgM_State.status = WDGM_NORMAL;
        }
        else
        {
            /*do nothing*/
        }
    }
    else if(WdgM_State.status == WDGM_RESET_EXECUTING)
    {
        WdgM_State.count += WDGM_TASK_PERIOD;
        if(WdgM_State.count >= WDGM_EXECUTE_TIMEOUT)
        {
            /*never run here*/

        }
    }
    else
    {
        /*do nothing*/
    }
}

/**
 *  @b Description
 *  @n
 *      This function check WdgM state which shall be called periodly everytime task is ready.
 *
 *  @param[in]  task
 *              High Priority task / Low Priority task
 *  @param[out] void
 *
 *  @return  void
 *
 */
void WdgM_TaskCheckAlive(WdgM_TaskIndexType task)
{
    WdgM_TaskStatus[task].status = WDGM_TASK_READY;
    WdgM_TaskStatus[task].count = 0;
}

/*==================[internal function definitions]=========================*/
#ifdef	__cplusplus
}
#endif

/*==================[end of file]===========================================*/
