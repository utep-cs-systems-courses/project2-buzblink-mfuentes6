In this project to run it you will need to be in the project file. The command
make all will run all the files. Make load will load it on to the msp430 and
make clean will clena up any unwanted files.

In switches.c there are 4 cases for the four buttons and they all do similar
but different things. The spped variable changes the timing in which the leds
are turned on and off. The note is used to change the pitch of the buzzer. led
is updated and buzzer is set to each corresponding values. Button 3 will turn
off the buzzer setting buzzer to 0.

The leds are driven by the wacth dog timer which has the speed value to check
when to state advance between the green and red led. Which results in the
lights appearing to dim and brigten as well.
