#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


void main(void){
  configureClocks();
  led_init();
  switch_init();
  buzzer_init();
  //led_init();
  enableWDTInterrupts();
  or_sr(0x18);

}
