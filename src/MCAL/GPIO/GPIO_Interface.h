#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/*GPIO interface macros*/

#define GPIO_PORTA                    1
#define GPIO_PORTB                    2
#define GPIO_PORTC                    3

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
#define GPIO_OUTPUT_LOW               2

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

void GPIO_voidGetInputPinValue(u8 copy_u8PortID, u8 copy_u8PinID);
