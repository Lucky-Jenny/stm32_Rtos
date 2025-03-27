/**
 * @file    Os_Task.h
 * @version 1.0.0
 *
 * @brief    
 * @details This file contains declarations of period Tasks.
 *
 * @author  Shawn Liu
 * @date    2025.03.25
 *   
 */

#ifndef OS_TASK_H_
#define OS_TASK_H_

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
typedef void (*TaskCallback)( void );
/*==================[external function declarations]========================*/
extern void Task_Init(void);
extern void Task_5msTask( void );
extern void Task_10msTask( void );
extern void Task_20msTask( void );
extern void Task_50msTask( void );
extern void Task_100msTask( void );
extern void Task_500msTask( void );
/*==================[external data]=========================================*/

#ifdef  __cplusplus
}
#endif

#endif  /* OS_TASK_H_ */
