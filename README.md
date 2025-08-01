# GripCtrl

### TL;DR It's a remote control system.
GripCtrl is a wireless controller based on the ESP32 DevKitC which can communicate with other devices easily (WiFi, Bluetooth, ESP-Now, RF via NRF24L01). With a built in UL 60947-5-5 emergency stop button, it's primarily designed for remotely controlling robots and other similar contraptions. When developing different projects, RF modules can be tedious and time consuming to wire up. GripCtrl was made to provide a simple way of remotely controlling projects, whether they're in development or production.

<img width="1000" alt="GripCtrl-render" src="https://github.com/user-attachments/assets/2b57aa78-8c80-44cb-a54d-193690f188d1" />
<img width="1000" alt="gripctrl-receiver-render" src="https://github.com/user-attachments/assets/c4249340-0fe5-4f7a-80ff-810bf49c034b" />


## Images

### Controller

<img width="400" alt="controller-front" src="https://github.com/user-attachments/assets/e148120e-aaa7-4703-983c-872702d9ebf7" />
<img width="500" alt="controller-front-transparent" src="https://github.com/user-attachments/assets/f5be1cf1-6e5c-4b2f-931d-f39de9b493c9" />
<img width="500" alt="controller-back-transparent" src="https://github.com/user-attachments/assets/e95ce75d-0df5-4ddf-8c7c-7d747084117e" />

### Receiver

<img width="500" alt="receiver-front" src="https://github.com/user-attachments/assets/1bbd97c4-230a-4f86-9d7f-dc6c5dfa1340" />
<img width="500" alt="receiver-front-transparent" src="https://github.com/user-attachments/assets/69ed2b78-3a6e-4b1b-9ca7-49d3ff9ecf19" />


## Wiring

GripCtrl currently has no PCB. The wiring is defined in the following schematic. The receiver's wiring is contained within the `Receiver Only` section of the schematic.

<img width="1248" height="862" alt="unified-wiring-diagram" src="https://github.com/user-attachments/assets/a390fbfa-182e-49fe-a0d1-c0baf2b58854" />


Refer to this image to find out which buttons go where:
<img width="1000" src="https://github.com/user-attachments/assets/65f4da9d-2132-4ded-a401-313ffcee1c0b" />




## BOM

|Name                                           |Description|Qty|Tot Price (USD)|Link                                                                                                                    |
|-----------------------------------------------|-----------|---|---------------|------------------------------------------------------------------------------------------------------------------------|
|NRF24L01 PA + NLA                              |           |2  |8.49           |https://www.amazon.com/gp/product/B00WG9HO6Q                                                                            |
|2x Analog Joystick                             |           |2  |1.76           |https://www.aliexpress.us/item/3256807375670744.html                                                                    |
|ESP32 WROOM-32 (USB-C)                         |           |2  |17.99          |https://amazon.com/gp/product/B0D6BH4K9B                                                                                |
|2x Mini Rocker Switch                          |           |2  |5.39           |https://business.walmart.com/ip/Mini-Rocker-Switch-2-PIN-ON-OFF-SPST-125VAC-6A-250VAC-3A-Red-KCD117S-2X-5X-10X/144502398|
|FF01 Low Profile E-Stop Button (FF0116BBCAEA01)|           |1  |38.89          |https://www.newark.com/nkk-switches/ff0116bbcaea01/e-stop-switch-spst-nc-0-5a-24vdc/dp/75AH8781                         |
|12 x 12 x 8mm Tactile Push Button              |           |9  |6.99           |https://www.amazon.com/Momentary-Pushbutton-Switches-Breadboard-Electronic/dp/B09R3ZPWJ7                                |
|2-Point Lanyard                                |           |1  |6.59           |https://www.amazon.com/dp/B0C4YJ5GHN                                                                                    |
|0.96" OLED Display                             |           |1  |10.79          |https://www.amazon.com/gp/product/B0F21YZ1TQ                                                                            |
|3V Piezo Buzzer                                |           |2  |5.29           |https://www.aliexpress.us/item/3256808592250091.html                                                                    |
|M3x6 SHCS                                      |           |26 |Order w/below  |https://us.store.bambulab.com/products/m3-socket-head-cap-machine-screws-shcs-1                                         |
|M3x14 SHCS                                     |(or M3x16) |4  |10.59          |https://us.store.bambulab.com/products/m3-socket-head-cap-machine-screws-shcs-1                                         |
|M3 Heat-Set Inserts                            |           |28 |12.49          |https://www.amazon.com/Yaocom-Inserts-Threaded-Printing-Components/dp/B0DG59PW2R                                        |
|Buck Converter (9V to 5V)                      |           |1  |5.87           |https://www.aliexpress.us/item/3256806137313905.html                                                                    |
|9V Battery[^1]                                 |           |1  |N/A            |N/A                                                                                                                     |
|9V Snap Connector[^1]                          |           |1  |N/A            |N/A                                                                                                                     |
[^1]: Not Included in Total Price

**Total Price: `$131.13`**
