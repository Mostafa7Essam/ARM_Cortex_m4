#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "NVIC_Cfg.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"




void NVIC_voidInit(void){
u32 local_u32registervalue;
/*SET configuration of system software priorities */
local_u32registervalue=VECT_KEY |(PRIORITY_CONFIG<<8);
/*assign the value in AIRCR register*/
SCB_AIRCR=local_u32registervalue;
}
void NVIC_voidSetSWpriority(u8 copy_u8SWpriority,u8 copy_u8IntID){
	/*Setting both group and sub priority into the hight 4 bits */
NVIC->IPR[copy_u8IntID]=copy_u8SWpriority<<4;
}
/*
 * Enable a specific interrupt
 *  copy_u8IntId: the interrupt number to enable
 */
void NVIC_voidEnableInterrupt(u8 copy_u8IntId)
{
NVIC->ISER[copy_u8IntId/32]=1<<(copy_u8IntId%32);
}

/*
 * Disable a specific interrupt
 *  copy_u8IntId: the interrupt number to disable
 */
void NVIC_voidDisableInterrupt(u8 copy_u8IntId){
	NVIC->ICER[copy_u8IntId/32]=1<<(copy_u8IntId%32);
}

/*
 * Set the pending flag for a specific interrupt
 *  copy_u8IntId: the interrupt number to set the pending flag for
 */
void NVIC_voidSetPendingFlag(u8 copy_u8IntId){
	NVIC->ISPR[copy_u8IntId/32]=1<<(copy_u8IntId%32);
}

/*
 * Clear the pending flag for a specific interrupt
 *  copy_u8IntId: the interrupt number to clear the pending flag for
 */
void NVIC_voidClearPendingFlag(u8 copy_u8IntId){
	NVIC->ICER[copy_u8IntId/32]=1<<(copy_u8IntId%32);
}

/*
 * Read the active flag for a specific interrupt
 *  copy_u8IntId: the interrupt number to read the active flag for
 * @return: 1 if the active flag is set, 0 if it is not set
 */
u8 NVIC_u8ReadActiveFlag(u8 copy_u8IntId){
u8 Local_u8ActiveFlag;
Local_u8ActiveFlag= NVIC->IABR[copy_u8IntId/32]>>(copy_u8IntId%32);
return Local_u8ActiveFlag;

}






