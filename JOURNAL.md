---
title: "LoRa ESP32 Pager"
author: "sosenteam"
description: "A P2P bidirectional pager using ESP32 and LoRa."
created_at: "2025-07-11"
---


## 6/27/2025 (5 Hours)

First day working on this project!! I started by spending two-ish hours reading the specs on LoRa and learning the protocal.
[Amazing Tutorial for LoRa](https://www.circuitstate.com/tutorials/interfacing-ra-01-ra-02-sx1278-lora-modules-with-esp32-using-arduino/) -
[Module Spec Sheet](https://docs.ai-thinker.com/en/lora/man) -
[API Spec Sheet](https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md)

Afterwords I built the first prototype on a breadboard and got everything wired up.
Next, I messed around with the Arduino library for a while until I was able to send a message from one esp32 and receive it on my RTLSDR v4. Once I was able to send messages, I then built and wired an identical second prototype and got it to receive messages. After way too much tweaking, I was finally able to use a button to send a message from one to the other!

Picture of the protoypes (aren't they adorable):

![LoRa Testing](https://github.com/user-attachments/assets/54128d92-2d68-40e6-afdd-670e13e11bd6)

## 6/28/2025 (2 Hours)

More research on how to display a UI! I picked out two SSD1306 modules (pictured above) I had on hand and decided to use them as my displays. I didn't want to manually code the entire UI so I started researching a less code-y solution. I discovered LVGL and Squareline Studio and starting setting them up, followed some Demo projects, read documentation etc.

## 6/29/2025 (2 Hours)

Started designing UI in Squareline Studio, got a first draft of the menu scren and started working on character selection with an encoder. I learned pretty quickly that Squareline studio is built for different projects, and it was also not very intuative to me.

<img width="456" height="152" alt="image" src="https://github.com/user-attachments/assets/8d1b8fa6-2468-4608-be59-e837a97ea3e8" />

## 7/01/2025 (1 Hour)

Continued work on the UI, focusiing on the read section (where incoming messages wil appear). Struggled a bit with getting the style how I wanted (not supposed to have blue), but overall happy with result.

<img width="422" height="158" alt="image" src="https://github.com/user-attachments/assets/6663e2a1-3f23-4b84-a33a-7b7cea52d726" />

## 7/04/2025 (2 Hours)

More UI Work! Got a finished version of the UI, with a send screen! Also has 'working' buttons, meaning the back buttons and main menu buttons now bring you to their respective pages. Exported to Arduino IDE!

<img width="575" height="153" alt="image" src="https://github.com/user-attachments/assets/0ead2f3e-71db-4314-8979-9fdd4a08e880" />

## 7/05/2025 (1 Hour)

Disaster Struck! LVGL code is not built for the Arduino IDE (prefers the espressif IDE), and the libraries for Arduino are built for ESPI_TFT, which doesn't support my display.
Picture of what Squareline studio gave me:

<img width="161" height="445" alt="image" src="https://github.com/user-attachments/assets/7e6f7cf8-6eaa-4584-9b8f-6e0fe1f58666" />

#### 5 day skip from lack of motavation ):

## 7/10/2025 (3 Hours)

More reasearch done! I've decided to use the MUI library from the u8g2 library, because I've used u8g2 before for projects, and MUI has the encoder code setup!!!
I've also spent a while testing MUI and making and testing examples. Also added encoder to one prototype!

![LoRa Update](https://github.com/user-attachments/assets/e16f3dec-3267-40ea-9338-ab2806a378e1)

## 7/11/2025 (2 Hours)

Lots more testing, Struggling with getting the screen to update quickly and also getting the encoder to have faster recognition/acceleration.

## 7/12/2025 (3 Hours)

Resolution!!! I figured out that in order to make the screen refresh faster, I needed to use hardware I2C instead of software I2C. I had to change a single character in my code from a S to a H. (So frustrating).
Also got a good demo for character selection, 12 characters, typing is 100x faster but still not quite perfect. I would like to get rid of Caps if I can. 

![PXL_20250712_212104544 RAW-01 MP COVER](https://github.com/user-attachments/assets/9394bd9c-6b05-4e2a-a8a8-f9819dd4c039)

## 7/13/2025 (3 Hours)

Started work in KiCAD, lots of watching tutorials, and finding out how to use the editor. Started adding components to my schematic, such as ESP32, voltage regulator, etc.

## 7/14/2025 (3 Hours)

Lots more work in KiCAD, also lots of reading documentation/spec sheets. Started the power supply section, also picked out the ESP32-S3-WROOM-1 because it doesn't need a seperated UART>USB connector.

<img width="557" height="312" alt="image" src="https://github.com/user-attachments/assets/c53c31e5-06e2-4493-8eb3-894919bf03aa" />

## 7/15/2025 (4.5 Hours)

So much more KiCAD, got USB and ESP32 and button sections of pcb done, started research into possible battery charging chips/boards (so scary).

<img width="1137" height="645" alt="image" src="https://github.com/user-attachments/assets/948d31fb-7095-4134-8fec-aa9c8bd8dec8" />

 Also started figuring out placement for the board even though it's not great (not finished ofc).

<img width="714" height="517" alt="image" src="https://github.com/user-attachments/assets/4569437f-5b2d-4c6a-b3b0-21f478357dd0" />


