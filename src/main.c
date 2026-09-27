#include "sdk_project_config.h"
#include "peripherals_pwm_pal_1.h"

int main(void)
{
	CLOCK_DRV_Init(&clockMan1_InitConfig0);
PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);
PWM_Init(&pwm_pal_1_instance,&pwm_pal_1_configs);

    while(1)
    {
       for(int duty = 0; duty <= 1000; duty += 10)
        {
            PWM_UpdateDuty(&pwm_pal_1_instance,0,duty);
             OSIF_TimeDelay(10);
        }
        for(int duty = 1000; duty > 0; duty -= 10)
        {
            PWM_UpdateDuty(&pwm_pal_1_instance,0,duty);
            OSIF_TimeDelay(10);
        }
    }
}
