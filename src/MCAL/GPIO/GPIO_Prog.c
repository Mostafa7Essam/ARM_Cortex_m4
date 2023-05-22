#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GPIO_Cfg.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


 /*
 This function initializes an output pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be initialized (0-15)
 - copy_u8PinMode: The mode of the pin (GPIO_MODE_OUTPUT_PUSH_PULL or GPIO_MODE_OUTPUT_OPEN_DRAIN)
 - copy_u8PinSpeed: The speed of the pin (GPIO_OUTPUT_SPEED_LOW, GPIO_OUTPUT_SPEED_MEDIUM, or GPIO_OUTPUT_SPEED_HIGH)
 */
void GPIO_voidInitOutputPin(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinMode, u8 copy_u8PinSpeed)
{
switch(copy_u8PortID)
{
case GPIO_PORTA :
	/*set direction of bin to be output*/
	GPIOA ->MODER &=(~(0b11<<(copy_u8PinID*2)));
	GPIOA ->MODER |=((0b01<<(copy_u8PinID*2)));
	/*set the speed of the pin*/
	GPIOA ->OSPEEDR &= ~(0b11<<(copy_u8PinID*2));
	GPIOA ->OSPEEDR |= (copy_u8PinSpeed << (copy_u8PinID * 2));

	/*set the type of the pin*/
	WRT_BIT(GPIOA->OTYPER,copy_u8PinID,copy_u8PinMode) ;
	break;
case GPIO_PORTB :
	/*set direction of bin to be output*/
	GPIOB ->MODER &=~((0b11<<(copy_u8PinID*2)));
	GPIOB ->MODER |=((0b01<<(copy_u8PinID*2)));
	/*set the speed of the pin*/
	GPIOB ->OSPEEDR &= ~(0b11<<(copy_u8PinID*2));
	GPIOB ->OSPEEDR |= (copy_u8PinSpeed << (copy_u8PinID * 2));

	/*set the type of the pin*/
	WRT_BIT(GPIOA->OTYPER,copy_u8PinID,copy_u8PinMode) ;
	break;
case GPIO_PORTC :
	/*set direction of bin to be output*/
	GPIOC ->MODER &=~((0b11<<(copy_u8PinID*2)));
	GPIOC ->MODER |=((0b01<<(copy_u8PinID*2)));
	/*set the speed of the pin*/
	GPIOC ->OSPEEDR &= ~(0b11<<(copy_u8PinID*2));
	GPIOC ->OSPEEDR |= (copy_u8PinSpeed << (copy_u8PinID * 2));

	/*set the type of the pin*/
	WRT_BIT(GPIOA->OTYPER,copy_u8PinID,copy_u8PinMode) ;
	break;
}
}

/*
This function initializes an input pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be initialized (0-15)
 - copy_u8PullMode: The pull-up or pull-down resistor configuration for the pin (GPIO_PULL_UP or GPIO_PULL_DOWN)
 */

void GPIO_voidInitInputPin(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PullMode)
{
	switch(copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:

			/*Set Direction of Pin to be Input using (Bit Masking)*/
			/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
			 * So The Mask Will Do the Job*/
			GPIOA->MODER &= (~(0b11 << (copy_u8PinID*2)));             //Clear Pin Bits

			/*Set Mode of Input Pin using (Bit Masking)*/
			GPIOA->PUPDR &= (~(0b11 << (copy_u8PinID*2))) ;  		   //Clear Pin Bits
			GPIOA->PUPDR |= (copy_u8PullMode << (copy_u8PinID*2)); 	   //Set Type as Configured

			break;
		case GPIO_PORTB:

			/*Set Direction of Pin to be Input using (Bit Masking)*/
			/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
			 * So The Mask Will Do the Job*/
			GPIOB->MODER &= (~(0b11 << (copy_u8PinID*2)));      	   //Clear Pin Bits

			/*Set Mode of Input Pin using (Bit Masking)*/
			GPIOB->PUPDR &= (~(0b11 << (copy_u8PinID*2))) ;  		   //Clear Pin Bits
			GPIOB->PUPDR |= (copy_u8PullMode << (copy_u8PinID*2)); 	   //Set Type as Configured

			break;
		case GPIO_PORTC:

			/*Set Direction of Pin to be Input using (Bit Masking)*/
			/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
			 * So The Mask Will Do the Job*/
			GPIOC->MODER &= (~(0b11 << (copy_u8PinID*2)));      	   //Clear Pin Bits

			/*Set Mode of Input Pin using (Bit Masking)*/
			GPIOC->PUPDR &= (~(0b11 << (copy_u8PinID*2))) ;  		   //Clear Pin Bits
			GPIOC->PUPDR |= (copy_u8PullMode << (copy_u8PinID*2)); 	   //Set Type as Configured

			break;
	}
}
/*
 This function sets the value of an output pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be set (0-15)
 - copy_u8Value: The value to set the pin to (GPIO_HIGH or GPIO_LOW)
 */
void GPIO_voidSetOutPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Value)
{
switch (copy_u8PortID)
{
  case GPIO_PORTA:
	  WRT_BIT(GPIOA->ODR,copy_u8PinID,copy_u8Value);
	  break;
  case GPIO_PORTB:
	  WRT_BIT(GPIOB->ODR,copy_u8PinID,copy_u8Value);
	  break;
  case GPIO_PORTC:

	  WRT_BIT(GPIOC->ODR,copy_u8PinID,copy_u8Value);
	  break;
}
}
/*
 This function reads the value of an input pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be read (0-15)
 Returns: The current value of the pin (GPIO_HIGH or GPIO_LOW)
 */
u8 GPIO_u8GetInputPinValue(u8 copy_u8PortID, u8 copy_u8PinID)
{
	u8 local;
switch(copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			local=(GET_BIT(GPIOA->IDR,copy_u8PinID));
			return local;

			break;
		case GPIO_PORTB:
            local=(GET_BIT(GPIOB->IDR,copy_u8PinID));

			return local;

			break;
		case GPIO_PORTC:
			local= (GET_BIT(GPIOC->IDR,copy_u8PinID));

			return local;

			break;
	}
}

