#include "nvic.h"
#include <stdbool.h>
/*
 *  1. setup group priority settings - optional
 *  2. Setup priority level of interupt
 *  3. Enable interrupt
 *  4. configure interrupt at mcu peripheral
 *  5. setup handle functions
 */

NVIC_CheckType NVIC_SoftwareInterrupt(uint32_t IRQn){

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        SWTRIG_REG = IRQn;
        RetVal = NVIC_OK;
    }

    return RetVal;

}
void NVIC_SetPriorityGrouping (NVIC_PRIORITY_LEVELS PriorityGroup)
{

    /*Set Priority Group*/

    uint32_t RegVal = 0x00000000;
    RegVal = (((uint32_t)VECTKEY<<16) | (uint32_t)PriorityGroup << 8);
    APINT_REG |= RegVal;

}
void NVIC_GetPriorityGrouping(NVIC_PRIORITY_LEVELS *PriorityGrouping){

    uint32_t RegVal = APINT_REG;

    *PriorityGrouping = (NVIC_PRIORITY_LEVELS)((uint32_t)(RegVal>>8 & 0x00000007));

}
NVIC_CheckType NVIC_EnableIRQ(uint8_t IRQn)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        EN_INT(IRQn);
        RetVal = NVIC_OK;
    }

    return RetVal;
}

NVIC_CheckType NVIC_DisableIRQ(uint8_t IRQn)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        DIS_INT(IRQn);
        RetVal = NVIC_OK;
    }

    return RetVal;
}

NVIC_CheckType NVIC_SetPendingIRQ(uint8_t IRQn)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        PEND_INT(IRQn);
        RetVal = NVIC_OK;
    }

    return RetVal;

}

NVIC_CheckType NVIC_GetPendingIRQ(uint8_t IRQn, uint32_t *State)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        *State = (PEND_REG(IRQn) >> ((IRQn) % 32) & 1);
        RetVal = NVIC_OK;
    }

    return RetVal;

}

NVIC_CheckType NVIC_ClearPendingIRQ(uint8_t IRQn)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        UNPEND_INT(IRQn);
        RetVal = NVIC_OK;
    }

    return RetVal;

}

NVIC_CheckType NVIC_GetActive(uint8_t IRQn, uint32_t *State)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        *State = IS_INT_ACTIVE(IRQn);
        RetVal = NVIC_OK;
    }

    return RetVal;

}

NVIC_CheckType NVIC_SetPriority(uint8_t IRQn, uint32_t priority)
{

    NVIC_CheckType RetVal;

    if (IRQn > MAX_INT_NUM || priority > MAX_PRIORITY)
    {
        RetVal = NVIC_NOK;
    }
    else
    {
        SET_INT_PRI(IRQn, priority);
        RetVal = NVIC_OK;
    }

    return RetVal;

}

NVIC_CheckType NVIC_GetPriority(uint8_t IRQn, uint32_t *priority){

    NVIC_CheckType RetVal;

       if (IRQn > MAX_INT_NUM)
       {
           RetVal = NVIC_NOK;
       }
       else
       {
           *priority = (PRI_REG(IRQn) >> (IRQn % 4) & 0x00000007);
           RetVal = NVIC_OK;
       }

       return RetVal;

}
