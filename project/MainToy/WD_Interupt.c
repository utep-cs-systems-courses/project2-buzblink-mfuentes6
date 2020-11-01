#include <msp.430.h>




void
__interupt_vec(WDT_VECTOR)WDT(){

  static char blink_count = 0;
  if(++blink_count == speed){
    buzzer_set_period(speed);
    led_update();
    blink_count = 0;

}
