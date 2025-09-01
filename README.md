## Overview
This project replicates the classic "Whack-a-Mole" game using a custom-designed PCB and a PSoC6 microcontroller. Built as part of ECE 315 (Introductory Microprocessor Laboratory) under instructor Joe Krachey, the system integrates real-time interaction with LEDs, pushbuttons, and a buzzer, simulating game logic and timing control on hardware.
## Demo

![Whack-a-Mole PCB1](315_PCB1.png)
![Whack-a-Mole PCB2](315_PCB2.png)


## Key Features

Custom PCB designed in Altium with clearly routed GPIO, power, and component overlays

Game implemented using embedded C on the PSoC6 platform, with FreeRTOS-style task logic

## Interactive gameplay

LEDs light up in round robbin fashion. Red LEDs are moles and Green LEDs are safe, and user must press the button quickly when RED LEDs light up to score. The game speeds up with each score.

Audio feedback via piezo buzzer and real-time reaction timing using internal timers.

## Technologies:
PSoC6, Embedded C, GPIO, Altium Designer, PCB Design, Real-Time Systems
