/**
 * @file appdebug.hpp
 * @author garkuchenko Nick (github.nekdfl@gmail.com)
 * @brief c++ macros for debug. To use it type 
 * #DEBUG_TO_SERIAL 1 
 * before include this file.
 * for all arduino with serial port.
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef APPDEBUG_HPP
#define APPDEBUG_HPP

#include <Arduino.h>

#ifdef DEBUG_TO_SERIAL

#define debug_printf_ln(fmt, ...)                      \
     do                                                \
     {                                                 \
          if (DEBUG_TO_SERIAL)                         \
               Serial.printf("\r\nDebug: " fmt "\r\n", \
                             ##__VA_ARGS__);           \
     } while (0)
// ::printf((PGM_P)PSTR(fmt), ## __VA_ARGS__)

#define DEBUG_STDOUT(x) (Serial.println(x))
#else
#define debug_printf_ln(fmt, ...)

#define DEBUG_STDOUT(x)
#endif

#endif