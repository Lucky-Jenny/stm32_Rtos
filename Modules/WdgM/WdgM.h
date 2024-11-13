/**
 *  @file  WdgM.h
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

#ifndef BSW_WDGM_H
#define	BSW_WDGM_H

#ifdef	__cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "WdgM_Cfg.h"

/*==================[external constants]====================================*/
/*==================[macros]================================================*/
/*==================[type definitions]======================================*/
typedef enum
{
    WDGM_NORMAL = 0,
    WDGM_EVENT_TIMEOUT,
    WDGM_EVENT_INTERRUPT,
    WDGM_RESET_EXECUTING,
}WdgM_StatusType;

typedef struct
{
    uint16              count;          /*the counter for WdgM */
    uint8               status;         /*the status of the WdgM */
    WdgM_ActionType     action;         /*the watchdog action to task timeout event occurred */
} WdgM_StateType;

typedef struct 
{
    uint8               status;         /*the state of the task */
    uint16              count;          /*the counter for the task */
}WdgM_TaskStatusType;


/*==================[external function declarations]========================*/
extern void WdgM_MainFunction(void);
extern void WdgM_TaskCheckAlive(WdgM_TaskIndexType task);
extern void WdgM_TimeoutCallback(WdgM_TaskStatusType* TaskStatus);

/*==================[external data]=========================================*/

#ifdef	__cplusplus
}
#endif

#endif	/* BSW_WDGM_H */

/*==================[end of file]===========================================*/
