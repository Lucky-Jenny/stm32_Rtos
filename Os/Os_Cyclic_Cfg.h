/**
 * @file    Os_Cyclic_Cfg.h
 * @version 1.0.0
 *
 * @brief    
 * @details This file contains all Configurations for OS Tasks.
 *
 * @author  Shawn Liu
 * @date    2025.03.25
 *   
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include <string.h>
#include <stdlib.h>
#include "Rte_Mac.h"
/*==================[external constants]====================================*/
/*==================[macros]================================================*/
/*==================[type definitions]======================================*/
BEGIN_RTE_CYCLIC_MAP
RTE_L_CYCLIC(Task_Init,     Task_5msTask,            5U,    0U)
RTE_L_CYCLIC(Task_Init,     Task_10msTask,          10U,    0U)
RTE_L_CYCLIC(Task_Init,     Task_20msTask,          20U,    0U)
RTE_H_CYCLIC(Task_Init,     Task_50msTask,          50U,    0U)
RTE_H_CYCLIC(Task_Init,     Task_100msTask,        100U,    0U)
RTE_H_CYCLIC(Task_Init,     Task_500msTask,        500U,    0U)
//RTE_H_CYCLIC(PrCan_Init,    PrCan_Task,             10U,    0U)
//RTE_H_CYCLIC(OTA_Init,      OTA_Task,                1U,    0U)
END_RTE_CYCLIC_MAP
/*==================[external function declarations]========================*/
/*==================[external data]=========================================*/

#ifdef  __cplusplus
}
#endif
