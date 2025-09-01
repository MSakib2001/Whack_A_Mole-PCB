/**
 * @file ece315_buzzer.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ece315_buzzer.h"

cyhal_pwm_t pwm_buzzer_obj;

/* Initialize the buzzer to the desired frequency */
void ece315_buzzer_init(uint16_t hz)
{

	cy_rslt_t rslt;

    // Initialize PWM on the supplied pin and assign a new clock
    rslt = cyhal_pwm_init(&pwm_buzzer_obj, PIN_BUZZER, NULL);
    CY_ASSERT(rslt == CY_RET_SUCCESS);

    // Set a duty cycle of 50% 
    rslt = cyhal_pwm_set_duty_cycle(&pwm_buzzer_obj, 50, hz);
    CY_ASSERT(rslt == CY_RET_SUCCESS);


	return rslt;

}

void ece315_buzzer_start(void)
{
	cy_rslt_t rslt;
    /* (Re-)start the PWM output */
    rslt = cyhal_pwm_start(&pwm_buzzer_obj);
    CY_ASSERT(rslt == CY_RET_SUCCESS);
    
}

void ece315_buzzer_stop(void)
{
	cy_rslt_t rslt;
    /* Stop the PWM output */
    rslt = cyhal_pwm_stop(&pwm_buzzer_obj);
    CY_ASSERT(rslt == CY_RET_SUCCESS);

}