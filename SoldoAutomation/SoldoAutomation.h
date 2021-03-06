// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _SoldoAutomation_H_
#define _SoldoAutomation_H_
#include "Arduino.h"
//add your includes for the project SoldoAutomation here
#include "SoldoSensors.h"
#include "SoldoLCDImplementation.h"
#include "SoldoIR.h"
#include "time/DS1302Time.h"
#include "SoldoEthernet.h"


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project SoldoAutomation here




//Do not add code below this line
#endif /* _SoldoAutomation_H_ */
