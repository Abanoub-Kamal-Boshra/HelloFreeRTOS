
#include "../../../LIB/BITMATH.h"
#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/DEFINTATION.h"

#include "../../../MCAL/ADC/Header/ADC_interface.h"
#include "../Header/TEMP.h"


void Temp_VoidInit(void)
{
	ADC_init();
}

U16 Temp_voidGetTemperature(U8 TEMP_Channel)
{

  U16 local_DigitalReading;
  U16 local_AnalogReading;
  U16 Temperature ;
  local_DigitalReading= ADC_Read(TEMP_Channel);
  local_AnalogReading = ((U32) local_DigitalReading * 5000UL)/1024;
  Temperature = local_AnalogReading / 10 ;
  return Temperature ;
}
