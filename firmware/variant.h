#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// #define HAS_SCREEN 0
// #define HAS_SDCARD
// #define SDCARD_USE_SPI1

#define USE_SSD1306

#define I2C_SDA 18 // 1 // I2C pins for this board
#define I2C_SCL 17 // 2

#define BUTTON_PIN 0 // This is the BOOT button
#define BUTTON_NEED_PULLUP

// #define USE_RF95 // RFM95/SX127x
// #define USE_SX1262
#define USE_SX1280

#define LORA_MISO 3
#define LORA_SCK 5
#define LORA_MOSI 6
#define LORA_CS 7

#define LORA_RESET 8
#define LORA_DIO1 16

#ifdef USE_SX1262
#define SX126X_CS LORA_CS // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 15
#define 
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN 4
#define SX126X_TXEN 9
#endif

