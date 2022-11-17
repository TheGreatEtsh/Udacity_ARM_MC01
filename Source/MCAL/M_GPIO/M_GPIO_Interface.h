/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      File:  			M_GPIO_Interface.h
 *      \date			15/11/2022
 *  	\brief			The main include file to interface with GPIO peripheral
 *      \email 			ahmedhesham606@icloud.com
 *		\author			Ahmad Hesham
 *		\description
 *********************************************************************************************************************/
#ifndef M_GPIO_INTERFACE_H
#define M_GPIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StandardTypes.h"
#include "L_BitMath.h"
#include "M_GPIO_Configurations.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ENABLE_PORT		1
#define DISABLE_PORT	0

#define PA0				10
#define PA1				11
#define PA2				12
#define PA3				13
#define PA4				14
#define PA5				15
#define PA6				16
#define PA7				17

#define PB0				20
#define PB1				21
#define PB2				22
#define PB3				23
#define PB4				24
#define PB5				25
#define PB6				26
#define PB7				27

#define PC0				30
#define PC1				31
#define PC2				32
#define PC3				33
#define PC4				34
#define PC5				35
#define PC6				36
#define PC7				37

#define PD0				40
#define PD1				41
#define PD2				42
#define PD3				43
#define PD4				44
#define PD5				45
#define PD6				46
#define PD7				47

#define PE0				50
#define PE1				51
#define PE2				52
#define PE3				53
#define PE4				54
#define PE5				55
#define PE6				56
#define PE7				57

#define PF0				60
#define PF1				61
#define PF2				62
#define PF3				63
#define PF4				64
#define PF5				65
#define PF6				66
#define PF7				67


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*
 * Choose DIO, or Alternative Function Select check data sheet page 1351
 */
typedef enum {
	DIO = 0,
	U0Rx = 1,
	U0Tx = 1,
	PB0_U1Rx = 1,
	PB1_U1Tx = 1,
	TCK_SWCLK = 1,
	TMS_SWDIO = 1,
	TDI = 1,
	TDO_SWO = 1,
	U4Rx = 1,
	U4Tx = 1,
	U3Rx = 1,
	U3Tx = 1,
	SSI3CLK = 1,
	SSI3Fss = 1,
	SSI3Rx = 1,
	SSI3Tx = 1,
	U6Rx = 1,
	U6Tx = 1,
	U2Rx = 1,
	U2Tx = 1,
	U7Rx = 1,
	U7Tx = 1,
	U5Rx = 1,
	U5Tx = 1,
	U1RTS = 1,
	U1CTS = 1,
	SSI0CLK = 2,
	SSI0Fss = 2,
	SSI0Rx = 2,
	SSI0Tx = 2,
	SSI2CLK = 2,
	SSI2Fss = 2,
	SSI2Rx = 2,
	SSI2Tx = 2,
	PC4_U1Rx = 2,
	PC5_U1Tx = 2,
	SSI1CLK = 2,
	SSI1Fss = 2,
	SSI1Rx = 2,
	SSI1Tx = 2,
	/*PF1_SSI1CLK	= 2,
	PF2_SSI1Fss	= 2,
	PF3_SSI1Rx	= 2,
	PF4_SSI1Tx	= 2,*/
	I2C1SCL = 3,
	I2C1SDA = 3,
	I2C0SCL = 3,
	I2C0SDA = 3,
	I2C3SCL = 3,
	I2C3SDA = 3,
	I2C2SCL = 3,
	I2C2SDA = 3,
	CAN0Rx = 3,
	CAN0Tx = 3,
	M0FAULT0 = 4,
	M0PWM5 = 4,
	M0PWM4 = 4,
	M0PWM7 = 4,
	M0PWM6 = 4,
	M0PWM3 = 4,
	M0PWM2 = 4,
	M0PWM1 = 4,
	M0PWM0 = 4,
	M1FAULT0 = 5,
	M1PWM5 = 5,
	M1PWM4 = 5,
	M1PWM7 = 5,
	M1PWM6 = 5,
	M1PWM3 = 5,
	M1PWM2 = 5,
	M1PWM1 = 5,
	M1PWM0 = 5,
	IDX0 = 6,
	PhA0 = 6,
	PhB0 = 6,
	IDX1 = 6,
	PhA1 = 6,
	PhB1 = 6,
	T2CCP0 = 7,
	T2CCP1 = 7,
	T3CCP0 = 7,
	T3CCP1 = 7,
	T1CCP0 = 7,
	T1CCP1 = 7,
	T0CCP0 = 7,
	T0CCP1 = 7,
	T4CCP0 = 7,
	T4CCP1 = 7,
	T5CCP0 = 7,
	T5CCP1 = 7,
	WT2CCP0 = 7,
	WT2CCP1 = 7,
	WT3CCP0 = 7,
	WT3CCP1 = 7,
	WT1CCP0 = 7,
	WT1CCP1 = 7,
	WT0CCP0 = 7,
	WT0CCP1 = 7,
	WT4CCP0 = 7,
	WT4CCP1 = 7,
	WT5CCP0 = 7,
	WT5CCP1 = 7,
	USB0EPEN = 8,
	NMI = 8,
	PE4_CAN0 = 8,
	PE5_CAN0 = 8,
	USB0PFLT = 8,
	PC4_U1RT = 8,
	PC5_U1CT = 8,
	PB4_CAN0 = 8,
	PB5_CAN0 = 8,
	CAN1Rx = 8,
	CAN1Tx = 8,
	C0o = 9,
	C1o = 9,
	TRD1 = 14,
	TRD0 = 14,
	TRCLK = 14
}Port_PinModeType;

/*
 * GPIO_INPUT OR GPIO_OUTPUT 
 */
typedef enum {
	GPIO_INPUT = 0,
	GPIO_OUTPUT
}Port_PinDirection;  

/*
 * GPIO_LOW OR GPIO_HIGH
 */
typedef enum {
	GPIO_LOW = 0,
	GPIO_HIGH
}Port_Pinlevel;

/*
 * GPIO_PULLDOWN, GPIO_PULLUP OR GPIO_OPENDRAIN
 */
typedef enum  {
	GPIO_PULLDOWN = 1,
	GPIO_PULLUP,
	GPIO_OPENDRAIN
}Port_PinInternalAttach;

/*
 * GPIO_2mA, GPIO_4mA OR GPIO_8mA
 */
typedef enum {
	GPIO_2mA = 2,
	GPIO_4mA = 4,
	GPIO_8mA = 8
}Port_PinOutputCurrent;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
/**
 * @brief This function is used to initialize a specific pin make sure to enable clock's gate to its port from the Configurations file
 * @options:	1- PinName: PA0, PA1,... Follow this way		
 *				2- PinModeType: DIO, or alternative function Select check data sheet page 1351
 *				3- PinDirection: GPIO_INPUT, or GPIO_OUTPUT 	
 *				4- PinInternalAttach: GPIO_PULLDOWN,  GPIO_PULLUP, or GPIO_OPENDRAIN, or 0
 *				5- PinOutputCurrent: GPIO_2mA, GPIO_4mA, or GPIO_8mA
 * @param au8_PinName, PinModeType, PinDirection, PinInternalAttach, PinOutputCurrent
 */
void M_GPIO_pinInit(u8_t au8_PinName, Port_PinModeType PinModeType, Port_PinDirection PinDirection, Port_PinInternalAttach PinInternalAttach, Port_PinOutputCurrent PinOutputCurrent);

void M_GPIO_pinWrite(u8_t au8_pinName, Port_Pinlevel PinLevel);

u8_t M_GPIO_pinRead(u8_t au8_pinName);

#endif  /* M_GPIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: M_GPIO_Interface.h
 *********************************************************************************************************************/
