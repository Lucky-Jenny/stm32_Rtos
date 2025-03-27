/**
 * @file    Os_Cyclic.h
 * @version 1.0.0
 *
 * @brief    
 * @details This file contains types and enums for OS.
 *
 * @author  Shawn Liu
 * @date    2025.03.25
 *   
 */

#ifndef OS_CYCLIC_H_
#define OS_CYCLIC_H_

#ifdef __cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include <string.h>
#include <stdlib.h>
#include "FreeRTOS.h"
/*==================[external constants]====================================*/
/*==================[macros]================================================*/
/*==================[type definitions]======================================*/
typedef struct
{
uint16_t  Period;
uint16_t  Delay;
}tRteCyclicTime;

typedef void (*tRunnable)(void);

/*==================[external function declarations]========================*/
extern void Os_Cyclic_HighPriTask(void);
extern void Os_Cyclic_LowPriTask(void);
/*==================[external data]=========================================*/

#ifdef  __cplusplus
}
#endif

#endif  /* OS_CYCLIC_H_ */
