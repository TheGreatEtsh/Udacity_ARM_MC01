typedef struct {
	u8_t							au8_PinName;				/*PA0, PA1,... Follow this way*/
	Port_PinModeType				PinModeType;				/*DIO, or Alternative Function Select check data sheet page 1351*/
	Port_PinDirection				PinDirection;				/*GPIO_INPUT OR GPIO_OUTPUT*/
	Port_PinInternalAttach			PinInternalAttach;			/*GPIO_PULLDOWN,  GPIO_PULLUP OR GPIO_OPENDRAIN*/
	Port_PinOutputCurrent			PinOutputCurrent;			/*GPIO_2mA, GPIO_4mA OR GPIO_8mA*/
}Pin_ConfigType;