#include <ch.h>
#include <hal.h>
#include <chprintf.h>

/*
static const SerialConfig sdcfg = {
    .speed  = 9600,
    .cr1    = 0,
    .cr2    = 0,
    .cr3    = 0
};
*/
PWMConfig pwm1conf = {
    .frequency = 500000,
    .period    = 10000,
    .callback  = NULL,
    .channels  = {
                  {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
                  {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
                  {.mode = PWM_OUTPUT_ACTIVE_HIGH,    .callback = NULL}, // Channel 3 is working CH1 = PA10
                  {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL}
                  },
    .cr2        = 0,
    .dier       = 0
};

int main(void)
{

    chSysInit();
    halInit();


   /* sdStart( &SD2, &sdcfg );

        palSetPadMode( GPIOD, 5, PAL_MODE_ALTERNATE(8) );    // TX
        palSetPadMode( GPIOD, 6, PAL_MODE_ALTERNATE(8) );    // RX
*/
    palSetLineMode( PAL_LINE( GPIOA, 10 ),  PAL_MODE_ALTERNATE(1) );
    pwmStart( &PWMD1, &pwm1conf );
    pwmEnableChannel( &PWMD1, 2, 5000 );

    while (true)
    {


    //chprintf(((BaseSequentialStream *)&SD2), "Znach: %d\n\r", znach );
    //chThdSleepMilliseconds(100);
    }
}
