---
title: "GripCtrl"
author: "Adrian"
description: "A dustproof remote control for robotics or industrial applications!"
created_at: "2025-07-10"
---

# JOURNAL.md

## 7/29 Design Continuation

Over the past couple of weeks I slowly gotten to know the general plan, now I'm going to settle some design specifics like the locations of certain parts and where I can source them from.

<img width="1297" height="778" alt="GripCtrl Diagram v1" src="https://github.com/user-attachments/assets/b487f6b2-026e-4a64-bb47-4e1754811ee8" />

Here is the current list of parts that I'm planning:
- NRF24L01 PA + NLA
- 2x Analog Joystick
- ESP32 WROOM-32 (USB-C)
- 2x Mini Rocker Switch
- FF01 Low Profile E-Stop Button
- 9x Push Button (A, B, X, Y, Power, 4x D-pad)
- 2-Point Lanyard (to attach to loops on bottom of front face)
- 0.96" OLED Display (or similar size)
- 3V Piezo Buzzer

A lot of thought went into selecting the specific parts for this project. For the power button, I wanted to be able to turn the controller on and off without removing the battery, but a switch or toggle button could be accidentally triggered. To solve this issue, I decided to use a momentary push button which could interrupt the ESP32 from deep sleep and turn it on. I can use a software mechanism like holding the button down or navigating through a menu to add support for turning it back off. (deep sleep)

The D-Pad will be four push buttons in + shape, similarly to the letter function buttons.

Part of the time was spent on identifying an exact model for the FF01 button. I found this information in the [datasheet](https://www.mouser.com/datasheet/2/295/FF01_E_Stop_Switches-1855882.pdf). After narrowing down the potential options, I found one to fit into the controller (coincidentally and luckily the cheapest one): `FF0116BBCAEA01`. This works out to be the 30 mm SPST version with arrows.
<img width="792" height="318" alt="FF01 Datasheet" src="https://github.com/user-attachments/assets/c07c76e8-2963-4a37-bfe7-43082ffb43dd" />

> Some screenshots from the step file for the FF0116BBCAEA01.
> 
> <img width="200" alt="FF0116BBCAEA01 Back" src="https://github.com/user-attachments/assets/9457b0a5-1169-4adc-a78a-51db3b191b0c" />
> <img width="180" alt="FF0116BBCAEA01 Front" src="https://github.com/user-attachments/assets/f25e7793-4391-416a-8b42-848f3f6a09d1" />


**Hopefully this is the end of two days of continuous part research!**

I worked on the drawing from earlier today to include more details. I placed more specific shapes to signify the cutouts I'll need to make in the housing. Here's the latest version of the drawing:

<img width="1271" height="846" alt="GripCtrl Diagram v2" src="https://github.com/user-attachments/assets/a1cb4a74-ce99-43f5-a1e3-8537932e3466" />


So far my plan is to make the controller split into two parts- like a sandwich! With a single flat seam, I can screw the entire controller together and have the benefit of a flat face for printing. I'll start the CAD later though, for now I'm going to work on the wiring. 

I'm not sure yet if a single board PCB will fit inside nicely. One idea is to make a breakout PCB for the ESP32 Dev Board and connect wires inside of it to the board, but I'll start with a schematic for the entire controller.

<img width="1096" height="661" alt="Schematic" src="https://github.com/user-attachments/assets/f44e949d-54d9-423d-a2b5-e7fe7f42e79f" />

Finding the right footprints for the ESP32 and making custom ones for the Screen, Joysticks, E-Stop and Buzzer took up quite a bit of the time spent on this schematic. Aside from that though, I checked to find out which pins on the ESP32 would be sufficient for different things like the SPI bus to the screen and reading the inputs from the joysticks. The joysticks, for example, must be connected to either an ADC1 or ADC2 pin. Since ADC2 overlaps with the onboard Wi-Fi chip, I decided to connect them all on ADC1. All of the buttons on the controller are connected to GND and a GPIO pin (all of which have internal pullup resistors).

Another important consideration is how I'm going to power the board when it's not plugged in to a computer. My original plan was to use a 9V battery, but then I realized that I would need to include a step down to safely connect it to the ESP32. I did put some thought into using a 3.7V LiPo instead, but I soon realized that I would still need 5V to fully power the joystick potentiometers. So, as of writing, my current plan is to use a small buck converter that can go from 9 to 5V between a 9V battery and the VIN pin on the ESP32.

The next steps for tomorrow are to start working on the BOM in csv format and (put in all the links I've found so far). Then, start working on the CAD for the case.

**Time spent: 14 hrs** (I can't believe I started working before noon)

## 7/10-7/27 - Project Initialization

Here's what I want to make: A dustproof game-style remote control that can be fitted to control different robots and other projects. 🎮

I looked online at existing controllers to find parts and design ideas. I assembled a list of components to help me add the features I wanted to include on the controller, some of which are...

- NRF24L01 PA + NLA
- 2x Analog Joystick
- ESP32 WROOM-32 (USB-C)

These are the basic components that I will use. The ESP32 has additional bluetooth capabilities, but the main communication will be over the RF transceiver. 

Aside from the two joysticks, I want to include a D-Pad style button on the left and some extra utility buttons for input. I'll use simple push buttons for these inputs. As for the dust-proof capabilities of the controller, my plan is to get silicone button caps to seal into where the A, B, X, Y buttons would go. During my research, however, I discovered that standard ones are extremely hard to find if not in bulk. I spent an _embarassingly_ long time searching for possible options. A peice of cut rubber pressed in will probably work too. Potential silicone button pads (apparently sold for Gameboy repair):

<img width="345.75" height="327" src="https://github.com/user-attachments/assets/d380aef7-4739-4e9a-967a-0aac6eef29b8" />

Some silicone end caps that could be fitted onto tactile push buttons: https://www.aliexpress.us/item/2251832634401905.html
<img width="406" height="357" src="https://github.com/user-attachments/assets/8a665aa6-6f7f-405a-b887-511a763dadb5" />




In addition to the basic components described above, given the applications of controlling robots, it seems logical to include an emergency stop button. This will probably have to go at the bottom of the controller, because otherwise it would stick out. After searching for a while, the FF01 from NKK Switches seems like a good option for a low profile on the back of the button. Although I'm not targeting any level of official certification, the reliability of the e-stop button's actuation is a significant consideration that went into finding a quality one.

<img width="66" height="80" src="https://github.com/user-attachments/assets/70285ab8-e614-4514-b7c5-d7dee6672f33" />

For showing feedback to the user, I'll use a small OLED becuase it can show a wide range of information.


For a power button I will either use a switch or a toggle button on the top or front of the remote. (TBD)

With all of this information (and many links to parts saved in notes) collected, I drew out a simple diagram to help organize the controller in future revisions.

<img width="729" height="496" src="https://github.com/user-attachments/assets/70a6041b-142e-453d-9f7d-9415236dc64f" />


**Time spent: 10hrs**
