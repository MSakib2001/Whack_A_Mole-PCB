/**
 * @file ece315_leds.h
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __ECE315_LEDS_H__
#define __ECE315_LEDS_H__
#include "cyhal.h"
#include "cy_pdl.h"
#include "cybsp.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ece315_pins.h"

#define TIMER_LED_TICKS_MS_250  12000000
#define LED_ON              1
#define LED_OFF             0

extern volatile bool ALERT_LEDS_ON;
extern volatile bool ALERT_LEDS_OFF;

void ece315_leds_init(void);
void ece315_leds_all_on(void) ;
void ece315_leds_all_off(void) ;

#endif
