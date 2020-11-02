#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "buzzer.h"
#include "state_machine.h"


char speed;
short note;

static char switch_update_interrupt_sense(){
  char p2 = P2IN;
  P2IES |= (p2 & SWITCHES);
  P2IES &= (p2 | ~SWITCHES);
  return p2;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interupt_handler();
  led_update();
}

void switch_interupt_handler(){
  char p2 = switch_update_interrupt_sense();

  char B1 = (p2 & SW1) ? 0:1;
  char B2 = (p2 & SW2) ? 0:1;
  char B3 = (p2 & SW3) ? 0:1;
  char B4 = (p2 & SW4) ? 0:1;


  if(B1){
    note = 2000; //buzzer note
    speed = 200; //speed which leds are lit and unlit
    led_update();
    buzzer_set_period(note);
  }

  if(B2){
    note = 4000; 
    speed = 3;
    led_update();
    buzzer_set_period(note);
  }

  if(B3){// will turn off buzzer
    stop_buzzer();
    speed = 50;
    led_update();
  }

  if(B4){ //turns buzzer back on
    resume_buzzer(1000);
    speed = 1;
    led_update();
  }
}
