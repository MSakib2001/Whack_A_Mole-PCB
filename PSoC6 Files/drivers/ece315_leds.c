/**
 * @file ece315_leds.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief
 * @version 0.1
 * @date 2023-10-20
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "ece315_leds.h"

volatile bool ALERT_LEDS_ON = false;
volatile bool ALERT_LEDS_OFF = false;

/* Timer object used */
cyhal_timer_t timer_led_obj;
cyhal_timer_cfg_t timer_led_cfg;

/*****************************************************************************/
/*  Interrupt Handlers                                                       */
/*****************************************************************************/

/**
 * @brief
 *  Function used as Timer Handler for Button Detection
 */
void Handler_Timer_Led(void *handler_arg, cyhal_timer_event_t event)
{
    static uint8_t count = 0;

    count = (count+1)%2;

    if(count == 0)
    {
        ALERT_LEDS_ON = true;
    }

    if(count == 1)
    {
        ALERT_LEDS_OFF = true;
    }
}

/* Initialize the LEDs */
void ece315_leds_init(void)
{
    cy_rslt_t rslt;

    rslt = cyhal_gpio_init(PIN_LED_G1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_G2, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_G3, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_G4, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_R1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_R2, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_R3, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_R4, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_Y1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_Y2, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_Y3, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    rslt = cyhal_gpio_init(PIN_LED_Y4, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

     timer_init(&timer_led_obj, &timer_led_cfg, TIMER_LED_TICKS_MS_250, Handler_Timer_Led); 

}

void ece315_leds_all_on(void)
{
    cyhal_gpio_write(PIN_LED_G1, LED_ON);
    cyhal_gpio_write(PIN_LED_G2, LED_ON);
    cyhal_gpio_write(PIN_LED_G3, LED_ON);
    cyhal_gpio_write(PIN_LED_G4, LED_ON);
    cyhal_gpio_write(PIN_LED_Y1, LED_ON);
    cyhal_gpio_write(PIN_LED_Y2, LED_ON);
    cyhal_gpio_write(PIN_LED_Y3, LED_ON);
    cyhal_gpio_write(PIN_LED_Y4, LED_ON);
    cyhal_gpio_write(PIN_LED_R1, LED_ON);
    cyhal_gpio_write(PIN_LED_R2, LED_ON);
    cyhal_gpio_write(PIN_LED_R3, LED_ON);
    cyhal_gpio_write(PIN_LED_R4, LED_ON);
}

void ece315_leds_all_off(void)
{
    cyhal_gpio_write(PIN_LED_G1, LED_OFF);
    cyhal_gpio_write(PIN_LED_G2, LED_OFF);
    cyhal_gpio_write(PIN_LED_G3, LED_OFF);
    cyhal_gpio_write(PIN_LED_G4, LED_OFF);
    cyhal_gpio_write(PIN_LED_Y1, LED_OFF);
    cyhal_gpio_write(PIN_LED_Y2, LED_OFF);
    cyhal_gpio_write(PIN_LED_Y3, LED_OFF);
    cyhal_gpio_write(PIN_LED_Y4, LED_OFF);
    cyhal_gpio_write(PIN_LED_R1, LED_OFF);
    cyhal_gpio_write(PIN_LED_R2, LED_OFF);
    cyhal_gpio_write(PIN_LED_R3, LED_OFF);
    cyhal_gpio_write(PIN_LED_R4, LED_OFF);
}