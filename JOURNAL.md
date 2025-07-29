---
title: "GripCtrl"
author: "Adrian"
description: "A dustproof remote control for robotics or industrial applications!"
created_at: "2025-07-10"
---

# JOURNAL.md

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
