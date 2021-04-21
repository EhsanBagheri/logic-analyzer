#pragma once
#ifdef ESP32
#include "Arduino.h"

// processor specific settings
#define MAX_CAPTURE_SIZE 100000
#define SERIAL_SPEED 921600
#define SERIAL_TIMEOUT 50
#define MAX_FREQ 2940052
#define MAX_FREQ_THRESHOLD 869900
#define START_PIN 16
#define PIN_COUNT sizeof(PinBitArray)*8


namespace logic_analyzer {


/// Define the datatype for PinBitArray: usually it is a uint8_t, but we could use uint16_t or uint32_t as well.
typedef uint8_t PinBitArray;

/**
 * @brief ESP32 specific implementation Logic for the PinReader
 * @author Phil Schatzmann
 * @copyright GPLv3
 * 
 */
class PinReader {
    public:
        PinReader(int startPin){
          this->start_pin = startPin;
        }

        /// reads all pins and provides the result as bitmask
        inline PinBitArray readAll() {
          uint32_t input = REG_READ(GPIO_IN_REG) >> start_pin;
          return input;
        }

    private:
        int start_pin;
};


} // namespace

#endif

