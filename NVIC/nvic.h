/*
 * nvic.h
 *
 *  Created on: Sep 15, 2019
 *      Author: MohamedBakr
 */
#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>
#include "M4MemMap.h"

typedef enum {NVIC_OK =0, NVIC_NOK} NVIC_CheckType;
typedef enum {
    G8_SUB1 = 0x4,
    G4_SUB2 = 0x5,
    G2_SUB4 = 0x6,
    G1_SUB8 = 0x7
}NVIC_PRIORITY_LEVELS;
#define MAX_INT_NUM 154
#define MAX_PRIORITY 7
#define VECTKEY 0x05FA

NVIC_CheckType NVIC_SoftwareInterrupt(uint32_t IRQn);
/**/
void NVIC_SetPriorityGrouping (NVIC_PRIORITY_LEVELS PriorityGroup);
/**/
void    NVIC_GetPriorityGrouping (NVIC_PRIORITY_LEVELS *PriorityGroup);
/**/
NVIC_CheckType    NVIC_EnableIRQ (uint8_t IRQn);
/**/
NVIC_CheckType    NVIC_GetEnableIRQ (uint8_t IRQn, uint32_t *State);
/**/
NVIC_CheckType    NVIC_DisableIRQ (uint8_t IRQn);
/**/
NVIC_CheckType    NVIC_GetPendingIRQ (uint8_t IRQn, uint32_t *State);
/**/
NVIC_CheckType    NVIC_SetPendingIRQ (uint8_t IRQn);
/**/
NVIC_CheckType    NVIC_ClearPendingIRQ (uint8_t IRQn);
/**/
NVIC_CheckType    NVIC_GetActive (uint8_t IRQn, uint32_t *State);
/**/
NVIC_CheckType    NVIC_SetPriority (uint8_t IRQn, uint32_t priority);
/**/
NVIC_CheckType NVIC_GetPriority(uint8_t IRQn, uint32_t *priority);

#endif /* NVIC_H_ */
