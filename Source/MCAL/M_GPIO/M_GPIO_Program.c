/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      File:  			M_GPIO_Program.c
 *      \date			15/11/2022
 *  	\brief			Consist of Functions' Implementations
 *      \email 			ahmedhesham606@icloud.com
 *		\author			Ahmad Hesham
 *		\description
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "M_GPIO_Interface.h"
#include "M_GPIO_Private.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL DATA
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
*********************************************************************************************************************/


/******************************************************************************
* \Syntax			: void M_GPIO_init(AnyType parameterName)
* \Description		: initialize the GPIO
*
* \Reentrancy		: Non Reentrant
* \Parameters		: u8_t au8_PinName, Port_PinModeType PinModeType, Port_PinDirection PinDirection, Port_PinInternalAttach PinInternalAttach, Port_PinOutputCurrent PinOutputCurrent
* \Return value		: void  
*					                  
*******************************************************************************/
void M_GPIO_pinInit(u8_t au8_PinName, Port_PinModeType PinModeType, Port_PinDirection PinDirection, Port_PinInternalAttach PinInternalAttach, Port_PinOutputCurrent PinOutputCurrent)
{
	/*Assign GPIO's clock gate configurations to RCGCGPIO register*/
	RCGCGPIO |= (u32_t) CLK_GTE_CTRL_VALUE;		

	u32_t au32_PortNumber = 0;
	u32_t au32_PinNumber = 0;

	au32_PortNumber = (u32_t)(au8_PinName) / 10;
	au32_PinNumber  = (u32_t)(au8_PinName) % 10;

	/*Assigning pin direction, Output Current, and Pin Internal Attach*/
	switch (PinDirection)
	{
	case GPIO_INPUT:
		switch (au32_PortNumber)
		{
		case 1: CLR_BIT(GPIODIRA,au32_PinNumber);		break;
		case 2:	CLR_BIT(GPIODIRB,au32_PinNumber);		break;
		case 3:	CLR_BIT(GPIODIRC,au32_PinNumber);		break;
		case 4:	CLR_BIT(GPIODIRD,au32_PinNumber);		break;
		case 5:	CLR_BIT(GPIODIRE,au32_PinNumber);		break;
		case 6:	CLR_BIT(GPIODIRF,au32_PinNumber);		break;
		default:			/*DO NOTHING*/								break;
		}
		
		switch (PinInternalAttach)
		{
		case GPIO_PULLUP: 
			switch (au32_PortNumber)
			{
			case 1: CLR_BIT(GPIOPURA, au32_PinNumber);		break;
			case 2:	CLR_BIT(GPIOPURB, au32_PinNumber);		break;
			case 3:	CLR_BIT(GPIOPURC, au32_PinNumber);		break;
			case 4:	CLR_BIT(GPIOPURD, au32_PinNumber);		break;
			case 5:	CLR_BIT(GPIOPURE, au32_PinNumber);		break;
			case 6:	CLR_BIT(GPIOPURF, au32_PinNumber);		break;
			default:			/*DO NOTHING*/			break;
			}
			break;

		case GPIO_PULLDOWN: 
			switch (au32_PortNumber)
			{
			case 1: CLR_BIT(GPIOPDRA, au32_PinNumber);		break;
			case 2:	CLR_BIT(GPIOPDRB, au32_PinNumber);		break;
			case 3:	CLR_BIT(GPIOPDRC, au32_PinNumber);		break;
			case 4:	CLR_BIT(GPIOPDRD, au32_PinNumber);		break;
			case 5:	CLR_BIT(GPIOPDRE, au32_PinNumber);		break;
			case 6:	CLR_BIT(GPIOPDRF, au32_PinNumber);		break;

			default:			/*DO NOTHING*/			break;
			}
			break;

		default:			/*DO NOTHING*/			break;
		}
		break;

	case GPIO_OUTPUT:
		switch (au32_PortNumber)
		{
		case 1: SET_BIT(GPIODIRA, au32_PinNumber);	 if (PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRA, au32_PinNumber);  	break;
		case 2:	SET_BIT(GPIODIRB, au32_PinNumber);	 if	(PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRB, au32_PinNumber);  	break;
		case 3:	SET_BIT(GPIODIRC, au32_PinNumber);	 if	(PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRC, au32_PinNumber);  	break;
		case 4:	SET_BIT(GPIODIRD, au32_PinNumber);	 if	(PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRD, au32_PinNumber);  	break;
		case 5:	SET_BIT(GPIODIRE, au32_PinNumber);	 if	(PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRE, au32_PinNumber);  	break;
		case 6:	SET_BIT(GPIODIRF, au32_PinNumber);	 if	(PinInternalAttach == GPIO_OPENDRAIN) SET_BIT(GPIOODRF, au32_PinNumber);	break;

		default: /*DO NOTHING*/	break;
		}

		switch (PinOutputCurrent)
		{
		case GPIO_2mA:
			switch (au32_PortNumber)
			{
			case 1: SET_BIT(GPIODR2RA,au32_PinNumber);		break;
			case 2:	SET_BIT(GPIODR2RB,au32_PinNumber);		break;
			case 3:	SET_BIT(GPIODR2RC,au32_PinNumber);		break;
			case 4:	SET_BIT(GPIODR2RD,au32_PinNumber);		break;
			case 5:	SET_BIT(GPIODR2RE,au32_PinNumber);		break;
			case 6:	SET_BIT(GPIODR2RF,au32_PinNumber);		break;

			default:			/*DO NOTHING*/				break;
			}
			break;
		
		case GPIO_4mA:
			switch (au32_PortNumber)
			{
			case 1: SET_BIT(GPIODR4RA, au32_PinNumber);		break;
			case 2:	SET_BIT(GPIODR4RB, au32_PinNumber);		break;
			case 3:	SET_BIT(GPIODR4RC, au32_PinNumber);		break;
			case 4:	SET_BIT(GPIODR4RD, au32_PinNumber);		break;
			case 5:	SET_BIT(GPIODR4RE, au32_PinNumber);		break;
			case 6:	SET_BIT(GPIODR4RF, au32_PinNumber);		break;

			default:			/*DO NOTHING*/				break;
			}
			break;

		case GPIO_8mA:
			switch (au32_PortNumber)
			{
			case 1: SET_BIT(GPIODR8RA, au32_PinNumber);		break;
			case 2:	SET_BIT(GPIODR8RB, au32_PinNumber);		break;
			case 3:	SET_BIT(GPIODR8RC, au32_PinNumber);		break;
			case 4:	SET_BIT(GPIODR8RD, au32_PinNumber);		break;
			case 5:	SET_BIT(GPIODR8RE, au32_PinNumber);		break;
			case 6:	SET_BIT(GPIODR8RF, au32_PinNumber);		break;

			default:			/*DO NOTHING*/				break;
			}
			break;

		default:
			break;
		}
		break;
		default:
		break;
	}
	
	/*Assigning whether the pin is working digital or Alternative function*/
	switch (PinModeType)
	{
	case DIO:
		switch (au32_PortNumber)
		{
		/*Enabling digital Input/Output functionality, Disabling alternative function slecetion*/
		case 1:	SET_BIT(GPIODENA, au32_PinNumber);	CLR_BIT(GPIOAFSELA, au32_PinNumber);		break;		
		case 2:	SET_BIT(GPIODENB, au32_PinNumber);	CLR_BIT(GPIOAFSELB, au32_PinNumber);		break;
		case 3:	SET_BIT(GPIODENC, au32_PinNumber);	CLR_BIT(GPIOAFSELC, au32_PinNumber);		break;
		case 4:	SET_BIT(GPIODEND, au32_PinNumber);	CLR_BIT(GPIOAFSELD, au32_PinNumber);		break;	
		case 5:	SET_BIT(GPIODENE, au32_PinNumber);	CLR_BIT(GPIOAFSELE, au32_PinNumber);		break;
		case 6:	SET_BIT(GPIODENF, au32_PinNumber);	CLR_BIT(GPIOAFSELF, au32_PinNumber);		break;

		default:							/*DO NOTHING*/									break;
		}
		break;
	default:
		switch (au32_PortNumber)
		{
		/*Disabling digital Input/Output functionality, Enabling alternative function slecetion*/
		case 1:	CLR_BIT(GPIODENA, au32_PinNumber);	SET_BIT(GPIOAFSELA, au32_PinNumber);			

			/*Assigning port ctrl value to the register to choose the alternative functionality*/
			(GPIOPCTLA &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLA |= ((u32_t)PinModeType << (4 * au32_PinNumber))); 	break;

		case 2:	CLR_BIT(GPIODENB, au32_PinNumber);	SET_BIT(GPIOAFSELB, au32_PinNumber);	
			(GPIOPCTLB &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLB |= ((u32_t)PinModeType << (4 * au32_PinNumber)));		break;
		case 3:	CLR_BIT(GPIODENC, au32_PinNumber);	SET_BIT(GPIOAFSELC, au32_PinNumber);	
			(GPIOPCTLC &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLC |= ((u32_t)PinModeType << (4 * au32_PinNumber)));		break;
		case 4:	CLR_BIT(GPIODEND, au32_PinNumber);	SET_BIT(GPIOAFSELD, au32_PinNumber);	
			(GPIOPCTLD &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLD |= ((u32_t)PinModeType << (4 * au32_PinNumber)));		break;
		case 5:	CLR_BIT(GPIODENE, au32_PinNumber);	SET_BIT(GPIOAFSELE, au32_PinNumber);	
			(GPIOPCTLE &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLE |= ((u32_t)PinModeType << (4 * au32_PinNumber)));		break;
		case 6:	CLR_BIT(GPIODENF, au32_PinNumber);	SET_BIT(GPIOAFSELF, au32_PinNumber);	
			(GPIOPCTLF &= (~((u32_t)15 << (4 * au32_PinNumber)))); (GPIOPCTLF |= ((u32_t)PinModeType << (4 * au32_PinNumber)));		break;
		
		default:											/*DO NOTHING*/												break;
		}
		break;
	}

}

void M_GPIO_pinWrite(u8_t au8_pinName, Port_Pinlevel PinLevel)
{
	u8_t au8_PortNumber = 0;
	u8_t au8_PinNumber = 0;

	au8_PortNumber = (au8_pinName) / 10;
	au8_PinNumber = (au8_pinName) % 10;

	switch (PinLevel)
	{
	case GPIO_HIGH:
		switch (au8_PortNumber)
		{
		case 1: SET_BIT(GPIODATAA, au8_PinNumber);		break;
		case 2:	SET_BIT(GPIODATAB, au8_PinNumber);		break;
		case 3:	SET_BIT(GPIODATAC, au8_PinNumber);		break;
		case 4:	SET_BIT(GPIODATAD, au8_PinNumber);		break;
		case 5:	SET_BIT(GPIODATAE, au8_PinNumber);		break;
		case 6:	SET_BIT(GPIODATAF, au8_PinNumber);		break;
		
		default:
			break;
		}
		break;
	case GPIO_LOW:
		switch (au8_PortNumber)
		{
		case 1: CLR_BIT(GPIODATAA, au8_PinNumber);		break;
		case 2:	CLR_BIT(GPIODATAB, au8_PinNumber);		break;
		case 3:	CLR_BIT(GPIODATAC, au8_PinNumber);		break;
		case 4:	CLR_BIT(GPIODATAD, au8_PinNumber);		break;
		case 5:	CLR_BIT(GPIODATAE, au8_PinNumber);		break;
		case 6:	CLR_BIT(GPIODATAF, au8_PinNumber);		break;

		default:
			break;
		}
		break;
	default:
		break;
	}

}

u8_t M_GPIO_pinRead(u8_t au8_pinName)
{
	u32_t au8_PortNumber = 0;
	u32_t au8_PinNumber = 0;
	u8_t au8_pinRead = 0;

	au8_PortNumber = (au8_pinName) / 10;
	au8_PinNumber = (au8_pinName) % 10;

	switch (au8_PortNumber)
	{
	case 1: au8_pinRead = GET_BIT(GPIODATAA, au8_PinNumber);		break;
	case 2:	au8_pinRead = GET_BIT(GPIODATAB, au8_PinNumber);		break;
	case 3:	au8_pinRead = GET_BIT(GPIODATAC, au8_PinNumber);		break;
	case 4:	au8_pinRead = GET_BIT(GPIODATAD, au8_PinNumber);		break;
	case 5:	au8_pinRead = GET_BIT(GPIODATAE, au8_PinNumber);		break;
	case 6:	au8_pinRead = GET_BIT(GPIODATAF, au8_PinNumber);		break;

	default:					/*DO NOTHING*/						break;
	}

	return au8_pinRead;
}


/**********************************************************************************************************************
 *  END OF FILE: M_GPIO_Program.c
 *********************************************************************************************************************/
