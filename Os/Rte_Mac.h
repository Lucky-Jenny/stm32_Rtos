/**
 * @file    Rte_Mac.h
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
/*==================[external constants]====================================*/
/*==================[macros]================================================*/
#ifdef BEGIN_RTE_CYCLIC_MAP
  #undef BEGIN_RTE_CYCLIC_MAP
#endif
  
#ifdef RTE_H_CYCLIC
  #undef RTE_H_CYCLIC
#endif
  
#ifdef RTE_L_CYCLIC
  #undef RTE_L_CYCLIC
#endif
  
#ifdef END_RTE_CYCLIC_MAP
  #undef END_RTE_CYCLIC_MAP
#endif

#if defined(RTE_MAC_CYCLIC_DECL_INIT)
  #define BEGIN_RTE_CYCLIC_MAP
  #define RTE_H_CYCLIC(init, func, time, delay) extern void init(void);
  #define RTE_L_CYCLIC(init, func, time, delay) extern void init(void);
  #define END_RTE_CYCLIC_MAP
  
#elif defined(RTE_MAC_CYCLIC_DECL_FUNC)
  #define BEGIN_RTE_CYCLIC_MAP
  #define RTE_H_CYCLIC(init, func, time, delay) extern void func(void);
  #define RTE_L_CYCLIC(init, func, time, delay) extern void func(void);
  #define END_RTE_CYCLIC_MAP
  
#elif defined(RTE_MAC_CYCLIC_FPTR_INIT)
  #define BEGIN_RTE_CYCLIC_MAP                  static const tRunnable RTE_CycFunc_Init[] = {
  #define RTE_H_CYCLIC(init, func, time, delay) init,
  #define RTE_L_CYCLIC(init, func, time, delay) init,
  #define END_RTE_CYCLIC_MAP                    (tRunnable)0 };
  
#elif defined(RTE_MAC_CYCLIC_FPTR_H)
  #define BEGIN_RTE_CYCLIC_MAP                  static const tRunnable RTE_CycFunc_H[] = {
  #define RTE_H_CYCLIC(init, func, time, delay) func,
  #define RTE_L_CYCLIC(init, func, time, delay)
  #define END_RTE_CYCLIC_MAP                    (tRunnable)0 };
  
#elif defined(RTE_MAC_CYCLIC_FPTR_L)
  #define BEGIN_RTE_CYCLIC_MAP                  static const tRunnable RTE_CycFunc_L[] = {
  #define RTE_H_CYCLIC(init, func, time, delay)
  #define RTE_L_CYCLIC(init, func, time, delay) func,
  #define END_RTE_CYCLIC_MAP                    (tRunnable)0 };
  
#elif defined(RTE_MAC_CYCLIC_TIME_CFG_H)
  #define BEGIN_RTE_CYCLIC_MAP                  static const tRteCyclicTime RTE_CycTime_H[] = {
  #define RTE_H_CYCLIC(init, func, time, delay) { time, delay },
  #define RTE_L_CYCLIC(init, func, time, delay)
  #define END_RTE_CYCLIC_MAP                    { 0 , 0 } };
  
#elif defined(RTE_MAC_CYCLIC_TIME_CFG_L)
  #define BEGIN_RTE_CYCLIC_MAP                  static const tRteCyclicTime RTE_CycTime_L[] = {
  #define RTE_H_CYCLIC(init, func, time, delay)
  #define RTE_L_CYCLIC(init, func, time, delay) { time, delay },
  #define END_RTE_CYCLIC_MAP                    { 0 , 0 } };
  
#elif defined(RTE_MAC_CYCLIC_TIME_ID_H)
  #define BEGIN_RTE_CYCLIC_MAP                  typedef enum {
  #define RTE_H_CYCLIC(init, func, time, delay) RteCyc_##func##_Id_H,
  #define RTE_L_CYCLIC(init, func, time, delay)
  #define END_RTE_CYCLIC_MAP                    RteCyc_IdCount_H } tRteCycId_H;
  
#elif defined(RTE_MAC_CYCLIC_TIME_ID_L)
  #define BEGIN_RTE_CYCLIC_MAP                  typedef enum {
  #define RTE_H_CYCLIC(init, func, time, delay)
  #define RTE_L_CYCLIC(init, func, time, delay) RteCyc_##func##_Id_L,
  #define END_RTE_CYCLIC_MAP                    RteCyc_IdCount_L } tRteCycId_L;
  
#elif defined(RTE_MAC_CYCLIC_TIME_VAL_H)
  #define BEGIN_RTE_CYCLIC_MAP                  static uint16_t Rte_CycTimeout_H[RteCyc_IdCount_H] = {0};
  #define RTE_H_CYCLIC(init, func, time, delay)
  #define RTE_L_CYCLIC(init, func, time, delay)
  #define END_RTE_CYCLIC_MAP
  
#elif defined(RTE_MAC_CYCLIC_TIME_VAL_L)
  #define BEGIN_RTE_CYCLIC_MAP                  static uint16_t Rte_CycTimeout_L[RteCyc_IdCount_L] = {0};
  #define RTE_H_CYCLIC(init, func, time, delay)
  #define RTE_L_CYCLIC(init, func, time, delay)
  #define END_RTE_CYCLIC_MAP

#else
#define BEGIN_RTE_CYCLIC_MAP
#define RTE_H_CYCLIC(init, func, time, delay)
#define RTE_L_CYCLIC(init, func, time, delay)
#define END_RTE_CYCLIC_MAP

#endif
/*==================[type definitions]======================================*/
/*==================[external function declarations]========================*/
/*==================[external data]=========================================*/

#ifdef  __cplusplus
}
#endif
