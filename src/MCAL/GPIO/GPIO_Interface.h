#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/*GPIO interface macros*/

#define GPIO_PORTA                    0
#define GPIO_PORTB                    1
#define GPIO_PORTC                    2

/*OUTPUT PIN MODE*/

#define GPIO_PUSH_PULL                0
#define GPIO_OPEN_DRAIN               1

/*OUTPUT PIN SPEED */

#define GPIO_LOW_SPEED                0
#define GPIO_MED_SPEED                1
#define GPIO_HIGH_SPEED               2
#define GPIO_VERY_HIGH_SPEED          3

/*OUTPUT PIN VALUE*/

#define GPIO_OUTPUT_HIGH              1
#define GPIO_OUTPUT_LOW               0

/*Port's Pins*/
#define GPIO_PIN0                     0
#define GPIO_PIN1 	                  1
#define GPIO_PIN2 	                  2
#define GPIO_PIN3 	                  3
#define GPIO_PIN4 	                  4
#define GPIO_PIN5 	                  5
#define GPIO_PIN6 	                  6
#define GPIO_PIN7 	                  7
#define GPIO_PIN8 	                  8
#define GPIO_PIN9 	                  9
#define GPIO_PIN10	                  10
#define GPIO_PIN11	                  11
#define GPIO_PIN12	                  12
#define GPIO_PIN13	                  13
#define GPIO_PIN14	                  14
#define GPIO_PIN15	                  15

/*Input Pin Modes*/
#define GPIO_INPUT_FLOAT		0
#define GPIO_INPUT_PULL_UP		1
#define GPIO_INPUT_PULL_DOWN	2

/**FUNCTIONS **/
 /*
 This function initializes an output pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be initialized (0-15)
 - copy_u8PinMode: The mode of the pin (GPIO_MODE_OUTPUT_PUSH_PULL or GPIO_MODE_OUTPUT_OPEN_DRAIN)
 - copy_u8PinSpeed: The speed of the pin (GPIO_OUTPUT_SPEED_LOW, GPIO_OUTPUT_SPEED_MEDIUM, or GPIO_OUTPUT_SPEED_HIGH)
 */

void GPIO_voidInitOutputPin(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinMode, u8 copy_u8PinSpeed);

 /*
 This function initializes an input pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be initialized (0-15)
 - copy_u8PullMode: The pull-up or pull-down resistor configuration for the pin (GPIO_PULL_UP or GPIO_PULL_DOWN)
 */

void GPIO_voidInitInputPin(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PullMode);

/*
 This function sets the value of an output pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be set (0-15)
 - copy_u8Value: The value to set the pin to (GPIO_HIGH or GPIO_LOW)
 */

void GPIO_voidSetOutPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Value);

/*
 This function reads the value of an input pin on the GPIO port
 Parameters:
 - copy_u8PortID: The ID of the GPIO port to which the pin belongs (A-B-C)
 - copy_u8PinID: The ID of the pin to be read (0-15)
 Returns: The current value of the pin (GPIO_HIGH or GPIO_LOW)
 */

u8 GPIO_u8GetInputPinValue(u8 copy_u8PortID, u8 copy_u8PinID);

