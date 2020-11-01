#include <msp.430.h>
#include "libTimer.h"
#include "buzzer.h"

static int period = 4000;
static int rate = 200;


#define MIN_PERIOD 100
#define MAX_PERIOD 8000

void buzzer_init()
{
  timerAUpmode();
  p2SEL2 &= ~(BIT6 | BIT7);
  p2SEL &= ~BIT7;
  p2SEL |= BIT6;
  p2DIR = BIT6;

  buzzer_execute_frequency();
  

}

void buzzer_execute_frequency()
{
  period += rate;
  if((rate > 0 && (period > MAX_PERIOD)) || (rate > 0 && (period < MIN_PERIOD)))
    {
      rate = rate + 200;
      period += (rate << 1);
    }
  buzzer_set_period(period);
}

void stop_buzzer(){
  buzzer_set_period(0);
}

void resume_buzzer(){
  buzzer_set_period(period);
}


void buzzer_set_period(short cycles)
{
  CCRO = cycles;
  CCR1 = cycles >> 1;
}
