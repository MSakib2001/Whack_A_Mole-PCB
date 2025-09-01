/**
 * @file ece315_pins.h
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ECE315_PINS_H__
#define __ECE315_PINS_H__

/* If you are using your own board, you will need to
 * change the define below to be:
 *  #undef ECE315_STAFF_BOARD
 * 
 * You will then need to define each of the following MACROs to 
 * match the pins you used when designing your version of the board
 */
#undef ECE315_STAFF_BOARD

#ifdef ECE315_STAFF_BOARD

/* UART - Down Stream*/
#define PIN_UART_DOWN_RX    P1_0
#define PIN_UART_DOWN_TX    P1_1

/* UART - Up Stream*/
#define PIN_UART_UP_RX      P0_4
#define PIN_UART_UP_TX      P0_5

/* LEDs - Green*/
#define PIN_LED_G1          P4_3
#define PIN_LED_G2          P4_2
#define PIN_LED_G3          P4_1
#define PIN_LED_G4          P4_0

/* LEDs - Red*/
#define PIN_LED_R1          P1_6
#define PIN_LED_R2          P1_5
#define PIN_LED_R3          P1_4
#define PIN_LED_R4          P1_3

/* LEDs - Yellow*/
#define PIN_LED_Y1          P3_0
#define PIN_LED_Y2          P2_7
#define PIN_LED_Y3          P2_1
#define PIN_LED_Y4          P2_0

/*Buzzer*/
#define PIN_BUZZER          P3_4

/*Button*/
#define PIN_BTN             P0_2

#else

/* Define each of the following pins based on the pins you 
 * selected for your version of the ECE315 board
 */

/* UART - Down Stream*/
#define PIN_UART_DOWN_RX    P4_0
#define PIN_UART_DOWN_TX    P4_1

/* UART - Up Stream*/
#define PIN_UART_UP_RX      P3_0
#define PIN_UART_UP_TX      P3_1

/* LEDs - Green*/
#define PIN_LED_G1          P1_1
#define PIN_LED_G2          P1_2
#define PIN_LED_G3          P1_3
#define PIN_LED_G4          P1_4

/* LEDs - Red*/
#define PIN_LED_R1          P0_0
#define PIN_LED_R2          P0_1
#define PIN_LED_R3          P0_2
#define PIN_LED_R4          P0_3

/* LEDs - Yellow*/
#define PIN_LED_Y1          P0_5
#define PIN_LED_Y2          P0_6
#define PIN_LED_Y3          P0_7
#define PIN_LED_Y4          P1_0

/*Buzzer*/
#define PIN_BUZZER          P3_4

/*Button*/
#define PIN_BTN             P1_7

#endif

#endif
