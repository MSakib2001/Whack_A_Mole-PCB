/**
 * @file ece315_buttons.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ece315_buttons.h"

/*****************************************************************************/
/*  Function Declaration                                                     */
/*****************************************************************************/
void Handler_Timer_Button(void *handler_arg, cyhal_timer_event_t event);

/*****************************************************************************/
/*  Global Variables                                                         */
/*****************************************************************************/

volatile bool ALERT_BUTTON_PRESSED = false; 

/* Timer object used */
cyhal_timer_t timer_button_obj;
cyhal_timer_cfg_t timer_button_cfg;

/*****************************************************************************/
/*  Interrupt Handlers                                                       */
/*****************************************************************************/

/**
 * @brief
 *  Function used as Timer Handler for Button Detection
 */
void Handler_Timer_Button(void *handler_arg, cyhal_timer_event_t event)
{
    static bool prev_button = false;
    bool current_button = !cyhal_gpio_read(PIN_BTN);

    if(current_button && !prev_button)
    {
        ALERT_BUTTON_PRESSED = true;
    }

    prev_button = current_button;

}

void ece315_button_init(void)
{
    cy_rslt_t rslt;

   rslt =  cyhal_gpio_init(PIN_BTN, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE, false);
   CY_ASSERT(rslt == CY_RET_SUCCESS);

   timer_init(&timer_button_obj, &timer_button_cfg, TIMER_BUTTON_TICKS,Handler_Timer_Button); 

}
