
#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_
#include "../../LIB/STD_TYPES.h"
/*
 * Struct representing the Nested Vectored Interrupt Controller (NVIC) of an ARM Cortex-M microcontroller
 */
typedef struct{
	u32 ISER[8];         // Interrupt Set-Enable Registers
    u32 RESERVED1[24];   // Reserved fields
    u32 ICER[8];         // Interrupt Clear-Enable Registers
    u32 RESERVED2[24];   // Reserved fields
    u32 ISPR[32];        // Interrupt Set-Pending Registers
    u32 ICPR[32];        // Interrupt Clear-Pending Registers
	u32 IABR[64];        // Interrupt Active Bit Registers
	u8  IPR[240];
}NVIC_t;

/*
 * Macro defining the base address of the NVIC
 * This allows for easier access to NVIC registers
 */
#define NVIC                  ((volatile NVIC_t*)(0xE000E100))
#define SCB_AIRCR             (*(volatile u32*)(0xE000ED0C))
#define VECT_KEY              (0x0F5A0000)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
