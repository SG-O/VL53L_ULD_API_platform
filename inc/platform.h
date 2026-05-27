/**
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


#ifndef _PLATFORM_H_
#define _PLATFORM_H_
#pragma once

#include <stdint.h>
#include <string.h>

#include "platform_vl53l5cx.h"
#include "platform_vl53l7cx.h"
#include "platform_vl53l8cx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  uint16_t address;
  void* reference_;
  uint8_t (*rd_byte_func)(void *reference, uint16_t register_address, uint8_t *p_value);
  uint8_t (*wr_byte_func)(void *reference, uint16_t register_address, uint8_t value);
  uint8_t (*rd_bytes_func)(void *reference, uint16_t register_address, uint8_t *p_values, uint32_t size);
  uint8_t (*wr_bytes_func)(void *reference, uint16_t register_address, const uint8_t *p_values, uint32_t size);
  void (*delay_func)(uint32_t ms);
} VL53L_Platform;

/**
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @param (uint16_t) Address : I2C location of value to read.
 * @param (uint8_t) *p_values : Pointer of value to read.
 * @return (uint8_t) status : 0 if OK
 */

uint8_t VL53L_RdByte(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_value);

/**
 * @brief Mandatory function used to write one single byte.
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @param (uint16_t) Address : I2C location of value to read.
 * @param (uint8_t) value : Pointer of value to write.
 * @return (uint8_t) status : 0 if OK
 */

uint8_t VL53L_WrByte(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t value);

/**
 * @brief Mandatory function used to read multiples bytes.
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @param (uint16_t) Address : I2C location of values to read.
 * @param (uint8_t) *p_values : Buffer of bytes to read.
 * @param (uint32_t) size : Size of *p_values buffer.
 * @return (uint8_t) status : 0 if OK
 */

uint8_t VL53L_RdMulti(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size);

/**
 * @brief Mandatory function used to write multiples bytes.
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @param (uint16_t) Address : I2C location of values to write.
 * @param (uint8_t) *p_values : Buffer of bytes to write.
 * @param (uint32_t) size : Size of *p_values buffer.
 * @return (uint8_t) status : 0 if OK
 */

uint8_t VL53L_WrMulti(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size);

/**
 * @brief Optional function, only used to perform an hardware reset of the
 * sensor. This function is not used in the API, but it can be used by the host.
 * This function is not mandatory to fill if user don't want to reset the
 * sensor.
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @return (uint8_t) status : 0 if OK
 */

uint8_t VL53L_Reset_Sensor(
		VL53L_Platform *p_platform);

/**
 * @brief Mandatory function, used to swap a buffer. The buffer size is always a
 * multiple of 4 (4, 8, 12, 16, ...).
 * @param (uint8_t*) buffer : Buffer to swap, generally uint32_t
 * @param (uint16_t) size : Buffer size to swap
 */

void VL53L_SwapBuffer(
		uint8_t 		*buffer,
		uint16_t 	 	 size);
/**
 * @brief Mandatory function, used to wait during an amount of time. It must be
 * filled as it's used into the API.
 * @param (VL53L_Platform*) p_platform : Pointer of VL53L platform
 * structure.
 * @param (uint32_t) TimeMs : Time to wait in ms.
 * @return (uint8_t) status : 0 if wait is finished.
 */

uint8_t VL53L_WaitMs(
		VL53L_Platform *p_platform,
		uint32_t TimeMs);

#ifdef __cplusplus
};
#endif

#endif	// _PLATFORM_H_
