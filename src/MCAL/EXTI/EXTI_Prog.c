#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_Cfg.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"


void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void))
{
    SET_BIT(EXIT->IMR , Copy_u8IntId);
}

void EXTI_voidDisableInt(u8 Copy_u8IntId)
{
    CLR_BIT(EXIT->IMR , Copy_u8IntId);

}

void EXTI_voidSetSenceSignal(u8 Copy_u8SenceSignal,u8 Copy_u8IntId)
{
    switch (Copy_u8SenceSignal)
    {
    case FALLING_EDGE:

        SET_BIT( EXIT->RTSR ,Copy_u8IntId);

        break;

    default:
        break;
    }

}
