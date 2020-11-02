#include <msp430.h>
#include state_machine.h
#include buzzer.h




void
__interupt_vec(WDT_VECTOR)WDT(){

  static char blink_count = 0;
  if(++blink_count == speed){
    buzzer_set_period(speed);
    state_advance();
    blink_count = 0;

}
