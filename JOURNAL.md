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

## 7/01/2025 (1 Hours)

Continued work on the UI, focusiing on the read section (where incoming messages wil appear). Struggled a bit with getting the style how I wanted (not supposed to have blue), but overall happy with result.

<img width="422" height="158" alt="image" src="https://github.com/user-attachments/assets/6663e2a1-3f23-4b84-a33a-7b7cea52d726" />

## 7/04/2025 (2 Hours)

More UI Work! Got a finished version of the UI, with a send screen! Also has 'working' buttons, meaning the back buttons and main menu buttons now bring you to their respective pages. Exported to Arduino IDE!

<img width="575" height="153" alt="image" src="https://github.com/user-attachments/assets/0ead2f3e-71db-4314-8979-9fdd4a08e880" />

## 7/05/2025 (1 Hours)

Disaster Struck! LVGL code is not built for the Arduino IDE (prefers the espressif IDE), and the libraries for Arduino are built for ESPI_TFT, which doesn't support my display.
Picture of what Squareline studio gave me:

<img width="161" height="445" alt="image" src="https://github.com/user-attachments/assets/7e6f7cf8-6eaa-4584-9b8f-6e0fe1f58666" />

#### 5 day skip from lack of motavation ):

## 7/10/2025 (3 Hours)



