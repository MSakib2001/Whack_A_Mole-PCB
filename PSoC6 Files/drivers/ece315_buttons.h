/**
 * @file ece315_buttons.h
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __ECE315_BUTTONS_H__
#define __ECE315_BUTTONS_H__

#include "cyhal.h"
#include "cy_pdl.h"
#include "cybsp.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ece315_pins.h"

#define TIMER_BUTTON_TICKS 100

extern volatile bool ALERT_BUTTON_PRESSED; 

/* Initializes the Push Button on the ECE315 Board
 * An TCPWM Interrupt will be used to detect when
 * the button has been pressed.  The timer interrupt
 * will occur every 20mS
 */
void ece315_button_init(void);


#endif