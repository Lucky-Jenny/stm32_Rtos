/**
 *  @file  WdgM_Cfg.h
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

#ifndef BSW_WDGM_CFG_H
#define	BSW_WDGM_CFG_H

#ifdef	__cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "typedefs.h"

/*==================[external constants]====================================*/
/*==================[macros]================================================*/
#define WDGM_TASK_PERIOD         5U
#define WDGM_EXECUTE_TIMEOUT     2000U
#define WDGM_TIGGER_CONDITION    1000U

#define WDGM_TASK_NOT_READY      0U
#define WDGM_TASK_READY          1U
#define WDGM_TASK_TIMEOUT        2U

/*==================[type definitions]======================================*/
typedef enum
{
	WdgM_RteH_Task = 0u,
	WdgM_RteL_Task,

    WDGM_TASK_NUM,
} WdgM_TaskIndexType;

typedef enum
{
    DO_NOTHING = 0,
    POWER_RESET,
} WdgM_ActionType;

typedef void (*Wdog_CallBack)(void);
typedef void (*Wdog_Sequence)(void);

typedef struct
{
    uint16      timeout;          /*the task timeout, ms*/
    uint16      waitDelay;
    uint8       action;           /*the action when the task timeout occurs */
    Wdog_CallBack timeoutCallback;  /*the callback function when the task gets stuck */
} WdgM_TaskConfigType;

/*==================[external function declarations]========================*/
/*==================[external data]=========================================*/
extern const WdgM_TaskConfigType WdgM_TaskConfig[WDGM_TASK_NUM];

#ifdef	__cplusplus
}
#endif

#endif	/* BSW_WDGM_CFG_H */

/*==================[end of file]===========================================*/
