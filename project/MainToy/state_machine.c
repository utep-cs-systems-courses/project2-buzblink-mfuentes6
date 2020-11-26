#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char dimmer;
char dim_state = 0;
char dimmerOne = 0;

char toggle_red()
{
  static char state = 0;
  switch(state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green()
{
  char changed = 0;
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state_advance()
{
  char changed = 0;
  static enum{R = 0, G = 1} color = G;
  switch(color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  leds_changed = changed;
  led_update();
}


void buzzer_advance()
{
  static char second_count = 0;
  switch(second_count){
  case 0: buzzer_set_period(1000); second_count = 1; break;
  case 1: buzzer_set_period(5000); second_count = 2; break;
  case 2: buzzer_set_period(3000); second_count = 3; break;
  case 3: buzzer_set_period(7000); second_count = 4; break;
  default: second_count = 0;
  }

}


void dim_advance()
{
  
  switch(dimmerOne){
  case 0: red_on = 1; leds_changed = 1; led_update(); break;
  case 1: dim25(); break;
  case 2: dim50(); break;
  case 3: dim75(); break;
  default: break;
  }
}

void speed_selection(){

  switch(dimmerOne){
  case 0: dimmerOne = 1; break;
  case 1: dimmerOne = 2; break;
  case 2: dimmerOne = 3; break;
  case 3: dimmerOne = 0; break;
  default: dimmerOne = 0; break;
  }
  //dimmerOne++;
}
void dim25(){
  switch(dim_state){
  case 0: red_on = 0; break;
  case 1: red_on = 0; break;
  case 2: red_on = 0; break;
  case 3: red_on = 1; break;
  default: dim_state = 0; break;

  }
  leds_changed = 1;
  led_update();
  

}


void dim50(){
  switch(dim_state){
  case 0: red_on = 0; break;
  case 1: red_on = 1; break;
  case 2: red_on = 0; break;
  case 3: red_on = 1; break;
  default: dim_state = 0; break;
  }
  leds_changed = 1;
  led_update();


}


void dim75(){
  switch(dim_state){
  case 0: red_on = 1; break;
  case 1: red_on = 1; break;
  case 2: red_on = 1; break;
  case 3: red_on = 0; break;
  default: dim_state = 0; break;
  }
  leds_changed = 1;
  led_update();
}
