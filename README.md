# LoRa-ESP32-Pager

This is a ESP-32 and SX1262 based pager, It contains full battery charging and management as well as an input keypad and encoder. It uses a 0.96" Oled (SSD1306).
There isn't any case because I wanted it to be a PCB only handheld (like the sprig), but I may laser cut a back when I get access to a laser cutter again (2 months).
The firmware is based on meshatastic, and hopefully will be able to use other meshtastic nodes to forward/mesh messages. 

I decided to build this because I felt like me and my friend group were too dependant on our phones, so I wanted to make a way to communicate that didn't involve phones. Also hopefully will be able to fully replace phones at school, which is aligned with my school possibly banning phones this upcoming year. The other main reason I wanted to start this project is because I wanted to learn more about radio and LoRa technology. This was also my first experience building my own PCBs, so I chose this over other projects because It would allow me to work with them.

<img width="1203" height="798" alt="image" src="https://github.com/user-attachments/assets/48713f0c-3e93-41fe-8bb6-70c9c57ef321" />
<img width="1101" height="850" alt="image" src="https://github.com/user-attachments/assets/91bf227f-9625-4c74-bed2-948023388047" />
<img width="1180" height="818" alt="image" src="https://github.com/user-attachments/assets/2c91af8b-da0e-4af6-9ae1-d270b931783a" />




|Name                   |Use                  |Qty|Total Price|Link                                                                               |
|-----------------------|---------------------|---|-----------|-----------------------------------------------------------------------------------|
|Oled Screen            |Screen               |5  |$9.80      |https://www.aliexpress.us/item/3256808552064563.html                               |
|Battery                |Battery              |5  |$23        |https://www.aliexpress.us/item/3256808031709894.html                               |
|                       |                     |   |           |                                                                                   |
|Ra-01SH                |LoRa                 |5  |16.9       |https://www.aliexpress.us/item/3256802374880132.html                               |
|MCP73871-2CCI/ML       |Battery Management   |5  |8.7        |https://www.aliexpress.us/item/3256809154370435.html                               |
|ESP32-S3-WROOM-1       |ESP32                |5  |20.6       |https://www.aliexpress.us/item/3256808569536766.html                               |
|TPS63001DRCR           |5v to 3v3            |5  |5.17       |https://www.aliexpress.us/item/3256806783602774.html (63001)                       |
|EC11E1834403           |Rotary Encoder       |5  |4.14       |https://www.aliexpress.us/item/2251832760130101.html                               |
|TYPE-C 16PIN 2MD(073)  |Usb Plug             |5  |2.69       |https://www.aliexpress.us/item/3256805314003507.html                               |
|All Resistors          |R100Ω                |   |4.74       |https://www.aliexpress.us/item/3256806810055728.html (Buy 2-3)                     |
|Inductor 0805 2.2uH    |Inductor for TPS63   |5  |1.45       |https://www.aliexpress.us/item/3256802926211468.html (2.2uH)                       |
|Leds                   |Battery Charge Leds  |10 |3.6        |https://www.aliexpress.us/item/2251832152971926.html                               |
|Diode 1N5819W          |Diode for Usb Power  |5  |0.23       |https://www.digikey.com/en/products/detail/tdk-corporation/MLP2012H2R2MT0S1/4327857|
|Ph2.0 Battery Connector|Battery Charger      |5  |1.45       |https://www.aliexpress.us/item/3256807255498839.html                               |
|PTS815SJM250SMTRLFS    |Reset and Boot Button|10 |1.15       |https://www.digikey.com/en/products/detail/c-k/PTS815SJM250SMTRLFS/9947846         |
|6x6 Tact Switch        |Keypad Buttons       |3  |1.29       |https://www.aliexpress.us/item/3256802301084670.html                               |
|Capacitor Set          |Decoupling           |1  |8.2        |https://www.aliexpress.us/item/3256807290577536.html (Buy 2-3)                     |
|Diode LESD             |ESD protection diodes|3  |3.34       |https://www.aliexpress.us/item/3256806903277344.html                               |
|Antenna                |Ra-01SH antenna      |5  |8.44       |https://www.aliexpress.us/item/3256805050972049.html                               |
|PCB                    |PCBs                 |5  |5          |                                                                                   |
|Ali Express Shipping   |                     |   |27         |                                                                                   |
|PCB Way Shipping       |                     |   |15         |                                                                                   |
|Digikey Shipping       |                     |   |7          |                                                                                   |
|                       |                     |   |$178.89    |                                                                                   |
