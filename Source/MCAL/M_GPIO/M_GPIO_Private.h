/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \File:  		M_GPIO_Private.h
 *  \date		    15/11/2022
 *	\brief			Consist of Private data of GPIO peripheral
 *  \email 			ahmedhesham606@icloud.com
 *	\author			Ahmad Hesham
 *	\description	Addresses of registers
 *********************************************************************************************************************/
#ifndef M_GPIO_PRIVATE_H
#define M_GPIO_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIOPORTA_APB_BASE_ADDRESS		0X40004000
#define GPIOPORTB_APB_BASE_ADDRESS		0X40005000
#define GPIOPORTC_APB_BASE_ADDRESS		0X40006000
#define GPIOPORTD_APB_BASE_ADDRESS		0X40007000
#define GPIOPORTE_APB_BASE_ADDRESS		0X40024000
#define GPIOPORTF_APB_BASE_ADDRESS		0X40025000

#define GPIOPORTA_AHB_BASE_ADDRESS		0X40058000
#define GPIOPORTB_AHB_BASE_ADDRESS		0X40059000
#define GPIOPORTC_AHB_BASE_ADDRESS		0X4005A000
#define GPIOPORTD_AHB_BASE_ADDRESS		0X4005B000
#define GPIOPORTE_AHB_BASE_ADDRESS		0X4005C000
#define GPIOPORTF_AHB_BASE_ADDRESS		0X4005D000

#define SYS_CTRL_BASE_ADDRESS			0X400FE000

#define RCGCGPIO		(*((volatile u32_t*) (SYS_CTRL_BASE_ADDRESS+0x608)))

#define GPIODATAA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x0)))
#define GPIODATAB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x0)))
#define GPIODATAC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x0)))
#define GPIODATAD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x0)))
#define GPIODATAE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x0)))
#define GPIODATAF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x0)))

#define GPIODIRA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x400)))
#define GPIODIRB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x400)))
#define GPIODIRC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x400)))
#define GPIODIRD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x400)))
#define GPIODIRE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x400)))
#define GPIODIRF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x400)))

#define GPIOAFSELA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x420)))
#define GPIOAFSELB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x420)))
#define GPIOAFSELC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x420)))
#define GPIOAFSELD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x420)))
#define GPIOAFSELE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x420)))
#define GPIOAFSELF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x420)))

#define GPIODENA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x51C)))
#define GPIODENB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x51C)))
#define GPIODENC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x51C)))
#define GPIODEND		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x51C)))
#define GPIODENE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x51C)))
#define GPIODENF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x51C)))

#define GPIOPCTLA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x52C)))
#define GPIOPCTLB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x52C)))
#define GPIOPCTLC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x52C)))
#define GPIOPCTLD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x52C)))
#define GPIOPCTLE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x52C)))
#define GPIOPCTLF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x52C)))

#define GPIODR2RA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x500)))
#define GPIODR2RB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x500)))
#define GPIODR2RC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x500)))
#define GPIODR2RD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x500)))
#define GPIODR2RE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x500)))
#define GPIODR2RF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x500)))
 
#define GPIODR4RA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x504)))
#define GPIODR4RB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x504)))
#define GPIODR4RC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x504)))
#define GPIODR4RD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x504)))
#define GPIODR4RE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x504)))
#define GPIODR4RF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x504)))

#define GPIODR8RA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x508)))
#define GPIODR8RB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x508)))
#define GPIODR8RC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x508)))
#define GPIODR8RD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x508)))
#define GPIODR8RE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x508)))
#define GPIODR8RF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x508)))

#define GPIOODRA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x50C)))
#define GPIOODRB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x50C)))
#define GPIOODRC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x50C)))
#define GPIOODRD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x50C)))
#define GPIOODRE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x50C)))
#define GPIOODRF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x50C)))

#define GPIOPURA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x510)))
#define GPIOPURB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x510)))
#define GPIOPURC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x510)))
#define GPIOPURD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x510)))
#define GPIOPURE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x510)))
#define GPIOPURF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x510)))

#define GPIOPDRA		(*((volatile u32_t*) (GPIOPORTA_APB_BASE_ADDRESS+0x514)))
#define GPIOPDRB		(*((volatile u32_t*) (GPIOPORTB_APB_BASE_ADDRESS+0x514)))
#define GPIOPDRC		(*((volatile u32_t*) (GPIOPORTC_APB_BASE_ADDRESS+0x514)))
#define GPIOPDRD		(*((volatile u32_t*) (GPIOPORTD_APB_BASE_ADDRESS+0x514)))
#define GPIOPDRE		(*((volatile u32_t*) (GPIOPORTE_APB_BASE_ADDRESS+0x514)))
#define GPIOPDRF		(*((volatile u32_t*) (GPIOPORTF_APB_BASE_ADDRESS+0x514)))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define CLK_GTE_CTRL_VALUE BIT_CONC(0,0,PORTF_CLK_GTE_CTRL,PORTE_CLK_GTE_CTRL,PORTD_CLK_GTE_CTRL,PORTC_CLK_GTE_CTRL,PORTB_CLK_GTE_CTRL,PORTA_CLK_GTE_CTRL)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* M_GPIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: M_GPIO_Private.h
 *********************************************************************************************************************/
