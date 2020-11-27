/*

Module:  getpinmap_ttgo_tbeam_lora32_v11.cpp

Function:
        Arduino-LMIC C++ HAL pinmap for TTGO T-Beam ESP32 OLED V1.1

Copyright & License:
        See accompanying LICENSE file.

Author:
        Daniel Tedenljung, info@tedenljungconsulting.com   November 2020

*/

#include <arduino_lmic_hal_boards.h>
#include <Arduino.h>

#include "../lmic/oslmic.h"

#define LORA_DIO0 26

namespace Arduino_LMIC {

class HalConfiguration_ttgo_tbeam_lora32_v11 : public HalConfiguration_t
	{
public:
	enum DIGITAL_PINS : uint8_t
		{
		PIN_SX1276_NSS = 18,
		PIN_SX1276_NRESET = 23,
		PIN_SX1276_DIO0 = LORA_DIO0,
		PIN_SX1276_DIO1 = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_DIO2 = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_ANT_SWITCH_RX = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_ANT_SWITCH_TX_BOOST = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_ANT_SWITCH_TX_RFO = HalPinmap_t::UNUSED_PIN,
		PIN_VDD_BOOST_ENABLE = HalPinmap_t::UNUSED_PIN,
		};

	virtual void begin(void) override
		{
		digitalWrite(PIN_SX1276_NSS, 1);
		pinMode(PIN_SX1276_NSS, OUTPUT);
		}

	// virtual void end(void) override

	// virtual ostime_t setModuleActive(bool state) override

	};

static HalConfiguration_ttgo_lora32_v1 myConfig;

static const HalPinmap_t myPinmap =
        {
        .nss = HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_NSS,
        .rxtx = HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_ANT_SWITCH_RX,
        .rst = HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_NRESET,

        .dio = {HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_DIO0,
				HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_DIO1,
				HalConfiguration_ttgo_tbeam_lora32_v11::PIN_SX1276_DIO2,
               },
        .rxtx_rx_active = 0,
        .rssi_cal = 10,
        .spi_freq = 8000000,     /* 8MHz */
        .pConfig = &myConfig
        };

const HalPinmap_t * GetPinmap_ttgo_tbeam_lora32_v11 (void)
	{
	return &myPinmap;
	}

}; // namespace Arduino_LMIC
