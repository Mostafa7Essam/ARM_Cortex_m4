/*
 * GPIO_Private.h
 *
 *  Created on: May 11, 2023
 *      Author: GRAPHICS
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

typedef struct
{
	u32 MODER  ; // to set the mode of any pin
	u32 OTYPER ; // to set the type of output pins (pp/od)
	u32 OSPEEDR; // to set the speed of output pins
	u32 PUPDR  ; // to set whether  pull up or pull down input
	u32 IDR    ; // to get the value of the input pin
	u32 ODR    ; // to set the output value

}GPIO_REG_T;

/*pointer to struct */

#define GPIOA                   ((volatile GPIO_REG_T*)(0x40020000))
#define GPIOB                   ((volatile GPIO_REG_T*)(0x40020400))
#define GPIOC                   ((volatile GPIO_REG_T*)(0x40020800))

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
