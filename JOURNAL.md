---
title: "GripCtrl"
author: "Adrian"
description: "A dustproof remote control for robotics or industrial applications!"
created_at: "2025-07-10"
---

# JOURNAL.md

**Total time spent: 48 hours**

## 7/31 Final Day

Today is the final day of work! I need to finish the CAD and add some basic firmware.


This is the design I came up with for the receiver: It's a small box with another ESP32 and RF module. It's designed to be attached to what you want to control.
<img width="889" height="601" alt="Receiver" src="https://github.com/user-attachments/assets/0515c1f3-ae5c-4f1f-a51b-4aa252f627ef" />

After placing all the components and making sure I got the right hole diameters, I have created the receiver. It uses another ESP32 for the microcontroller along with another NRF module and a piezo. There are holes for jumpers along the top. It's designed to be powered by 3 or 5V from whatever project it's attached to.

<img width="789" height="771" alt="Almost done" src="https://github.com/user-attachments/assets/be3cf453-5b35-4ee2-a8b4-1375d1c6ac69" />

The design process for the receiver was relatively straightforward compared to the controller. I did mount the RF module upside down at a 45 degree angle so that I could maintain the same overall dimensions for the box (50 x 100 x 35mm, not including mounting tabs).

> The receiver requires four M3x6 screws and four M3x14 or M3x16 screws. (4 to secure the ESP32, 4 to secure the lid) All 8 of these screws need their own M3 heat-set inserts.
>
> <img width="742" height="507" alt="Screws Crossection" src="https://github.com/user-attachments/assets/d6ef2e2c-1349-41c8-abe3-ba7ea67ef19e" />

One of the remaining issues was the placement of the joysticks. Before resolving that I went and I perfected the Joystick model I found online to use more accurate dimensions. I also added a joint in Fusion to approximate how it would move.
<img width="996" height="656" alt="Joystick" src="https://github.com/user-attachments/assets/18f97658-d3d7-4ddf-be59-6c39930ee110" />

I finalized the cutouts in the top for the joysticks. They should allow at least 80 degrees of freedom. To make sure they fit, the joysticks themselves are at 45 degree angles relative to the controller. The cutouts were made by revolving a profile around the Joystick's vertical axis. This profile was an approximation based on a 40 degree and 0 degree projection of the joystick.
<img width="1015" height="563" alt="Joystick Cutouts" src="https://github.com/user-attachments/assets/693f0769-42b7-40ef-a513-4511a8b4c20a" />

The cad up until this point has taken 6 hours. Next up is mounting the joysticks:

<img width="500" alt="Joystick Mount Sketch" src="https://github.com/user-attachments/assets/e0c5ae7f-ba88-483b-ac7b-15b7351fe965" />

Across all the components mounted inside, there are 18 M3x6 screws required and 8 3d printed spacers.
<img width="998" height="641" alt="Screws" src="https://github.com/user-attachments/assets/5977b471-23e0-4af0-8383-984ff36e6cab" />

Now to do firmware, BOM, and README!

<img width="400" alt="Final Receiver" src="https://github.com/user-attachments/assets/07ab6793-1447-4cb4-be44-22fe02b31bc1" />
<img width="400" alt="Final Controller" src="https://github.com/user-attachments/assets/be6645ac-3571-4f31-9928-49139e312e8c" />


**Time spent: 8 hrs**

## 7/30 CAD

The goal for today is to create the BOM and finish the CAD. I started off by putting all the links I had collected into the `bom.csv`. There were two items that I had not found specific details for yet: The Buck Converter and the Push Buttons.

Starting off the CAD design for the controller, I found a tutorial to make a generic controller in Fusion first using the Forms feature. Here's my progress through the tutorial series:

<img width="1086" height="661" alt="CAD v1" src="https://github.com/user-attachments/assets/6694ea3a-21d6-4c88-befd-fde2a114d146" />
<img width="1200" height="757" alt="CAD v2" src="https://github.com/user-attachments/assets/666a1ca0-8907-430b-a5cb-9ecc2add6318" />

A quick update: This is much harder than expected. Even with the reference images shown in the screenshot above, it's hard to get the form to match the shape just how I want it to once there's overlapping points.

> Finally an acceptable form:
> 
> <img width="1139" height="780" alt="CAD v3" src="https://github.com/user-attachments/assets/a5e2006a-cba5-4d67-b81a-8a8000d24ca5" />
>
> This form still needs many modifications to the shape becuase there are a lot of faces that are unaligned to how I'd want them to be.
>
> An hour later I have arrived at the following form. I now need to hollow it out and place correctly sized cavities for all the components.
> <img width="1210" height="637" alt="CAD v4" src="https://github.com/user-attachments/assets/82adfe6c-31c3-4372-8e57-06063a0f9afe" />

Fusion 360 refused to hollow out the bottom half of the controller for over 45 minutes. After loads of searching for help online, I discovered the fix for the issue accidentally when I was looking at the case: Since the bottom half of the form was too complex for fusion to inset, it gave me a single surface when I tried to inset the bottom case by the intended wall thickness. Unbeknownst to me, there was a tiny hole in the surface which I was trying to use as a cutting tool. It was patching this hole in the surface tab which finally allowed me to hollow out the bottom.

Because there's so little space inside the controller, I need to place the components carefully inside. When placing the ESP32 and the OLED into the controller, I realized that they were both too tall to fit in with normal headers. For this reason I decided to switch the headers of the components that couldn't fit to 90 degee headers.

<img width="982" height="600" alt="Angled Headers" src="https://github.com/user-attachments/assets/e1f7d2dc-fa57-4e5f-b54a-22073ca3623f" />

> Cross section illustrating the space issue:
> 
> <img width="1016" height="508" alt="Cross section illustrating the space issue" src="https://github.com/user-attachments/assets/2460e28b-63e7-45b4-ae2a-149e4d3e6257" />


Remaining Components to Add/Position:
- 2nd Joystick
- Action Buttons
- D-Pad Buttons
- E-Stop
- Action Switches
- NRF24L01
- Buzzer
- Battery

At this current stage I have the joysticks mounted at 120 degree angles. This is not ideal, but if I can't find a bettery way to fit them in, I'll just fix the rotated X and Y in the firmware. Since the E-Stop is a little too tall, I'm extending the underside to fit it better. This will also help with making more space inside the controller.
<img width="1140" height="722" alt="Extending the Underside for E-Stop" src="https://github.com/user-attachments/assets/603985bb-396a-4ffe-b382-198d3e64843e" />

After many hours of work rearanging the components and fitting them into place, I have arrived at this design. The battery and battery holder will attach on the outside. (there is a slot on the underside for the wires to go in) The only remaining steps for the CAD are to finish the joystick cutouts, add hardware (screws, heated inserts), and make the receiver case. After the CAD the remaining work is on the firmware, BOM (halfway done), and README.

<img width="500" alt="Pov A of CAD v5 EOD" src="https://github.com/user-attachments/assets/86d4eb32-fee5-4fd3-b790-0c7e9fcd2af6" />
<img width="500" alt="Pov B of CAD v5" EOD src="https://github.com/user-attachments/assets/42be5248-3e95-448e-a358-8f8a06ba081b" />

**Time spent: 16 hrs**

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

<img width="300" alt="Pin Counts" src="https://github.com/user-attachments/assets/56f3de8f-8cac-46ff-821f-372fe91df69b" />

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
