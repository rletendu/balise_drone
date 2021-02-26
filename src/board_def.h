#ifndef BOARD_DEF_H
#define BOARD_DEF_H

#define T_BEAM_V07 1
#define T_BEAM_V10 2
#define ESP01 3

#define BOARD ESP01

//#define ENABLE_SSD1306
#define ENABLE_GPS
//#define ENABLE_LORA

#define SSD1306_ADDRESS 0x3c
#ifdef ENABLE_SSD1306
#include "SSD1306.h"
#include "OLEDDisplayUi.h"
#define SSD1306_OBJECT() (SSD1306 oled(SSD1306_ADDRESS, I2C_SDA, I2C_SCL); OLEDDisplayUi ui(&oled))

#else
#define SSD1306_OBJECT()
#endif

#ifdef ENABLE_LORA
#include <LoRa.h>

#define LORA_PERIOD 868

#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_SS 18
#define LORA_DI0 26
#define LORA_RST 23

#endif

//GPS模块
#ifdef ENABLE_GPS
#include <TinyGPS++.h>
#define UBLOX_GPS_OBJECT() TinyGPSPlus gps
#define GPS_BAUD_RATE 9600 // ou 19200 avec refresh rate à 5Hz (le GPS doit stocker la configuration dans ce cas)


#if (BOARD == T_BEAM_V07)
#define GPS_RX_PIN 12
#define GPS_TX_PIN 15
#define BUTTON_PIN 39
#define BUTTON_PIN_MASK GPIO_SEL_39
#elif (BOARD == T_BEAM_V10)
#define GPS_RX_PIN 34
#define GPS_TX_PIN 12
#define BUTTON_PIN 38
#define BUTTON_PIN_MASK GPIO_SEL_38
#elif (BOARD == ESP01)
#define GPS_RX_PIN 0       // Brancher le fil Tx du GPS
#define GPS_TX_PIN 2       // pas utilisé
#else
#error No board define
#endif

#else
UBLOX_GPS_OBJECT()
#endif

#ifdef ENABLE_LORA
#if LORA_PERIOD == 433
#define BAND 433E6
#elif LORA_PERIOD == 868
#define BAND 868E6
#elif LORA_PERIOD == 915
#define BAND 915E6
#else
#define BAND 433E6
#endif
#endif

#define I2C_SDA 21
#define I2C_SCL 22
#define PMU_IRQ 35
#define GPS_POWER_CTRL_CH 3
#define LORA_POWER_CTRL_CH 2

//#define ENABLE_BUZZER
#define BUZZER_PIN 4

#endif /*BOARD_DEF_H*/