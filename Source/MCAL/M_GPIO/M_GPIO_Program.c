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
* \Parameters		: void   
* \Return value		: void  
*					                  
*******************************************************************************/
void M_GPIO_init(Pin_ConfigType* ConfigPtr)
{
	RCGCGPIO |= (u32_t) CLK_GTE_CTRL_VALUE;		/*Assign GPIO's clock gate configurations to RCGCGPIO register*/
	u32_t au32_PortNumber = 0;
	u32_t au32_PinNumber = 0;

	au32_PortNumber = (u32_t)(ConfigPtr->au8_PinName) / 10;
	au32_PinNumber  = (u32_t)(ConfigPtr->au8_PinName) % 10;

	switch ((ConfigPtr->PinDirection))
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
		
		switch (ConfigPtr->PinInternalAttach)
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
		case 1: SET_BIT(GPIODIRA, au32_PinNumber);	 if ((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRA, au32_PinNumber);  	break;
		case 2:	SET_BIT(GPIODIRB, au32_PinNumber);	 if	((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRB, au32_PinNumber);  	break;
		case 3:	SET_BIT(GPIODIRC, au32_PinNumber);	 if	((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRC, au32_PinNumber);  	break;
		case 4:	SET_BIT(GPIODIRD, au32_PinNumber);	 if	((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRD, au32_PinNumber);  	break;
		case 5:	SET_BIT(GPIODIRE, au32_PinNumber);	 if	((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRE, au32_PinNumber);  	break;
		case 6:	SET_BIT(GPIODIRF, au32_PinNumber);	 if	((ConfigPtr->PinInternalAttach) == GPIO_OPENDRAIN) SET_BIT(GPIOODRF, au32_PinNumber);		break;

		default: /*DO NOTHING*/	break;
		}

		switch (ConfigPtr->PinOutputCurrent)
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
	
	switch (ConfigPtr->PinModeType)
	{
	case DIO:
		switch (au32_PortNumber)
		{
		case 1:	SET_BIT(GPIODENA, au32_PinNumber);	CLR_BIT(GPIOAFSELA, au32_PinNumber);		break;		/*Enabling digital Input/Output functionality, Disabling alternative function slecetion*/
		case 2:	SET_BIT(GPIODENB, au32_PinNumber);	CLR_BIT(GPIOAFSELB, au32_PinNumber);		break;
		case 3:	SET_BIT(GPIODENC, au32_PinNumber);	CLR_BIT(GPIOAFSELC, au32_PinNumber);		break;
		case 4:	SET_BIT(GPIODEND, au32_PinNumber);	CLR_BIT(GPIOAFSELD, au32_PinNumber);		break;	
		case 5:	SET_BIT(GPIODENE, au32_PinNumber);	CLR_BIT(GPIOAFSELE, au32_PinNumber);		break;
		case 6:	SET_BIT(GPIODENF, au32_PinNumber);	CLR_BIT(GPIOAFSELF, au32_PinNumber);		break;

		default:							/*DO NOTHING*/									break;
		}
	default:
		switch (au32_PortNumber)
		{
		case 1:	CLR_BIT(GPIODENA, au32_PinNumber);	SET_BIT(GPIOAFSELA, au32_PinNumber);			/*Disabling digital Input/Output functionality, Enabling alternative function slecetion*/
			(GPIOPCTLA &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLA |= (ConfigPtr->PinModeType << (4 * au32_PinNumber))); 	break;			/*Assigning port ctrl value to the register to choose the alternative functionality*/
		case 2:	CLR_BIT(GPIODENB, au32_PinNumber);	SET_BIT(GPIOAFSELB, au32_PinNumber);	
			(GPIOPCTLB &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLB |= (ConfigPtr->PinModeType << (4 * au32_PinNumber)));		break;
		case 3:	CLR_BIT(GPIODENC, au32_PinNumber);	SET_BIT(GPIOAFSELC, au32_PinNumber);	
			(GPIOPCTLC &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLC |= (ConfigPtr->PinModeType << (4 * au32_PinNumber)));		break;
		case 4:	CLR_BIT(GPIODEND, au32_PinNumber);	SET_BIT(GPIOAFSELD, au32_PinNumber);	
			(GPIOPCTLD &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLD |= (ConfigPtr->PinModeType << (4 * au32_PinNumber)));		break;
		case 5:	CLR_BIT(GPIODENE, au32_PinNumber);	SET_BIT(GPIOAFSELE, au32_PinNumber);	
			(GPIOPCTLE &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLE |= (ConfigPtr->PinModeType << (4 * au32_PinNumber)));		break;
		case 6:	CLR_BIT(GPIODENF, au32_PinNumber);	SET_BIT(GPIOAFSELF, au32_PinNumber);	
			(GPIOPCTLF &= (~(15 << (4 * au32_PinNumber)))); (GPIOPCTLF |= (ConfigPtr->PinModeType << (4 * au32_PinNumber)));		break;
		
		default:											/*DO NOTHING*/														break;
		}
		break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: M_GPIO_Program.c
 *********************************************************************************************************************/
