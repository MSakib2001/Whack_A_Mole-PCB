/**
 * @file main.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief
 * @version 0.1
 * @date 2023-10-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "drivers/ece315.h"

int main(void)
{
    bool buzzer_on = false;
    bool status_rx_upstream = false;
    bool status_rx_downstream = false;

    uint8_t upstream_msg[80];
    uint8_t downstream_msg[80];

    /* Enable global interrupts */
    __enable_irq();

    /* Enable the button*/
    ece315_button_init();

    /* Enable LEDs */
    ece315_leds_init();

    // Turn LEDS off
    ece315_leds_all_off();

    /* Initialize the Buzzer to operate at 2.5KHz */
    ece315_buzzer_init(2500);
      uint16_t LED[12] = {PIN_LED_G1, PIN_LED_R4, PIN_LED_R3, PIN_LED_R2, PIN_LED_R1,PIN_LED_Y4, PIN_LED_Y3,PIN_LED_Y2,PIN_LED_Y1,PIN_LED_G4,PIN_LED_G3, PIN_LED_G2};
      uint16_t count = 0;
      uint16_t Active_LED;
      uint16_t delay;
      
      //G1 - R4 - R1 - Y4- Y1 -G4 - G1 && (Active_LED = PIN_LED_G1) || (Active_LED = PIN_LED_G2) || (Active_LED = PIN_LED_G3) || (Active_LED = PIN_LED_G4)
    for (;;)
    {
        delay = 50;
        Active_LED = LED[count % 12];
        cyhal_gpio_write(Active_LED, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(Active_LED, LED_OFF);
        count++;


        if ((ALERT_BUTTON_PRESSED == true) )
        {
            ALERT_BUTTON_PRESSED = false;
            
            if((Active_LED == LED[0]) || (Active_LED == LED[9]) || (Active_LED == LED[10]) || (Active_LED == LED[11]))
            {
            buzzer_on = !buzzer_on;
            
            

            if (buzzer_on)
            {
                ece315_buzzer_start();
                cyhal_system_delay_ms(250);
                buzzer_on = !buzzer_on;
                ece315_buzzer_stop();
            }
            else
            {
                ece315_buzzer_stop();
            }
            cyhal_system_delay_ms(1000);
            delay = delay - 5;
           }else{
            ece315_leds_all_on();
            cyhal_system_delay_ms(1000);
            ece315_leds_all_off();
            return;

           } 
        }
        

        

      /*  if(ALERT_LEDS_OFF)
        {
            ALERT_LEDS_OFF = false;
            //ece315_leds_all_off();
           cyhal_gpio_write(Active_LED, LED_OFF);
           count++;
           
        }
        
        if(ALERT_LEDS_ON)
        {
            ALERT_LEDS_ON = false;
            //ece315_leds_all_on();
           cyhal_gpio_write(Active_LED, LED_ON);
           
        } */

    }
}

/* [] END OF FILE */
