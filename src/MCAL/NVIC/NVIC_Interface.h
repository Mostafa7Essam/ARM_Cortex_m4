/*
 * NVIC_Interface.h
 *
 *  Created on: May 22, 2023
 *      Author: GRAPHICS
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#define GROUP4_SUB0         (0)//SUPPORT 16 GROUP
#define GROUP3_SUB1         (4)//SUPPORT 8 GROUPSAND 2 SUB
#define GROUP2_SUB2         (5)//SUPPORT 4 GROUPSAND 4 SUB
#define GROUP1_SUB3         (6)//SUPPORT 2 GROUPSAND 6 SUB
#define GROUP0_SUB4         (7)//SUPPORT 0 GROUPSAND 16 SUB


/*this function init the nvic and set the priorities*/

void NVIC_voidInit(void);
/****/
void NVIC_voidSetSWpriority(u8 copy_u8SWpriority,u8 copy_u8IntID);

/*
 * Enable a specific interrupt
 * @param copy_u8IntId: the interrupt number to enable
 */
void NVIC_voidEnableInterrupt(u8 copy_u8IntId);

/*
 * Disable a specific interrupt
 * @param copy_u8IntId: the interrupt number to disable
 */
void NVIC_voidDisableInterrupt(u8 copy_u8IntId);

/*
 * Set the pending flag for a specific interrupt
 * @param copy_u8IntId: the interrupt number to set the pending flag for
 */
void NVIC_voidSetPendingFlag(u8 copy_u8IntId);

/*
 * Clear the pending flag for a specific interrupt
 * @param copy_u8IntId: the interrupt number to clear the pending flag for
 */
void NVIC_voidClearPendingFlag(u8 copy_u8IntId);

/*
 * Read the active flag for a specific interrupt
 * @param copy_u8IntId: the interrupt number to read the active flag for
 * @return: 1 if the active flag is set, 0 if it is not set
 */
u8 NVIC_u8ReadActiveFlag(u8 copy_u8IntId);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
