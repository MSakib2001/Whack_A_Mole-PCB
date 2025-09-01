/**
 * @file ece315_buzzer.h
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __ECE315_BUZZER_H__
#define __ECE315_BUZZER_H__

#include "cyhal.h"
#include "cy_pdl.h"
#include "cybsp.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ece315_pins.h"

/* Initialize the buzzer to the desired frequency */
void ece315_buzzer_init(uint16_t hz) ;

void ece315_buzzer_start(void);

void ece315_buzzer_stop(void);

#endif
