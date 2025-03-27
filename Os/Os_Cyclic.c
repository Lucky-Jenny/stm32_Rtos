/**
 * @file    Os_Cyclic.c
 * @version 1.0.0
 *
 * @brief    
 * @details This file defines all types of runnable functions.
 *
 * @author  Shawn Liu
 * @date    2025.03.25
 *   
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "Os_Cyclic.h"
#include "Os_Task.h"

#define  RTE_MAC_CYCLIC_DECL_INIT
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_DECL_INIT

#define  RTE_MAC_CYCLIC_DECL_FUNC
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_DECL_FUNC

#define  RTE_MAC_CYCLIC_FPTR_INIT
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_FPTR_INIT

#define  RTE_MAC_CYCLIC_FPTR_H
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_FPTR_H

#define  RTE_MAC_CYCLIC_FPTR_L
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_FPTR_L

#define  RTE_MAC_CYCLIC_TIME_CFG_H
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_CFG_H

#define  RTE_MAC_CYCLIC_TIME_CFG_L
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_CFG_L

#define  RTE_MAC_CYCLIC_TIME_ID_H
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_ID_H

#define  RTE_MAC_CYCLIC_TIME_ID_L
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_ID_L

#define  RTE_MAC_CYCLIC_TIME_VAL_H
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_VAL_H

#define  RTE_MAC_CYCLIC_TIME_VAL_L
#include "Os_Cyclic_Cfg.h"
#undef   RTE_MAC_CYCLIC_TIME_VAL_L

/*==================[internal constants]====================================*/
/*==================[internal macros]=======================================*/
/*==================[internal type definitions]=============================*/
/*==================[internal function declarations]========================*/
/*==================[internal data]=========================================*/
static uint16_t Rte_unTimeH = 0U;
static uint16_t Rte_unTimeL = 0U;
static uint16_t idx_Marker  = 0U;
/*==================[external function definitions]=========================*/

/**
 * @brief Rte High proirity cyclicly task function
 * 
 * @param[in] void
 * 
 * @return void
 */
void Os_Cyclic_HighPriTask(void)
{
    uint16_t hIndex = 0U;

    /*check all high-priority cyclic runnables for timeout*/
    for(hIndex = 0U; hIndex < RteCyc_IdCount_H; hIndex++)
    {
        if((int16_t)(Rte_CycTimeout_H[hIndex] - Rte_unTimeH) <= 0)
        {
            /*calc next timeout value*/
            Rte_CycTimeout_H[hIndex] += RTE_CycTime_H[hIndex].Period;

            /*call cyclic runnable*/
            RTE_CycFunc_H[hIndex]();
        }
    }

    Rte_unTimeH++;
}

/**
 * @brief Rte low proirity cyclicly task function
 * 
 * @param[in] void
 * 
 * @return void
 */
 
 void Os_Cyclic_LowPriTask(void)
 {
    uint16_t lIndex = idx_Marker;

    do
    {
        /*check cyclic runnable for timeout*/
        if((int16_t)(Rte_CycTimeout_L[lIndex] - Rte_unTimeL) <= 0)
        {
            /*timeout found -> calc next timeout value*/
            Rte_CycTimeout_L[lIndex] += RTE_CycTime_L[lIndex].Period;

            /*call cyclic runnable*/
            RTE_CycFunc_L[lIndex]();

            /*next timeout search will start at next channel (round-robin)*/
            idx_Marker = lIndex + 1;

            if(idx_Marker >= RteCyc_IdCount_L)
            {
                idx_Marker = 0U;
            }

            /*exit loop after first found timeout*/
            break;
        }
        else
        {
            if(++lIndex >= RteCyc_IdCount_L)
            {
                lIndex = 0;
            }
        }
    }while(lIndex != idx_Marker);

    Rte_unTimeL++;
}

#ifdef __cplusplus
}
#endif
