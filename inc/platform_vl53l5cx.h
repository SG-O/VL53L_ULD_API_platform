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


#ifndef _PLATFORM_VL53L5CX_H_
#define _PLATFORM_VL53L5CX_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define VL53L5CX_Platform VL53L_Platform

/*
 * @brief The macro below is used to define the number of target per zone sent
 * through I2C. This value can be changed by user, in order to tune I2C
 * transaction, and also the total memory size (a lower number of target per
 * zone means a lower RAM). The value must be between 1 and 4.
 */

#ifndef VL53L5CX_NB_TARGET_PER_ZONE
#define VL53L5CX_NB_TARGET_PER_ZONE		1U
#endif

/*
 * @brief The macro below can be used to avoid data conversion into the driver.
 * By default there is a conversion between firmware and user data. Using this macro
 * allows to use the firmware format instead of user format. The firmware format allows
 * an increased precision.
 */

// #define 	VL53L5CX_USE_RAW_FORMAT

/*
 * @brief All macro below are used to configure the sensor output. User can
 * define some macros if he wants to disable selected output, in order to reduce
 * I2C access.
 */

#define VL53L5CX_DISABLE_AMBIENT_PER_SPAD
#define VL53L5CX_DISABLE_NB_SPADS_ENABLED
// #define VL53L5CX_DISABLE_NB_TARGET_DETECTED
#define VL53L5CX_DISABLE_SIGNAL_PER_SPAD
// #define VL53L5CX_DISABLE_RANGE_SIGMA_MM
// #define VL53L5CX_DISABLE_DISTANCE_MM
// #define VL53L5CX_DISABLE_REFLECTANCE_PERCENT
// #define VL53L5CX_DISABLE_TARGET_STATUS
#define VL53L5CX_DISABLE_MOTION_INDICATOR

#define VL53L5CX_RdByte      VL53L_RdByte
#define VL53L5CX_WrByte      VL53L_WrByte
#define VL53L5CX_RdMulti     VL53L_RdMulti
#define VL53L5CX_WrMulti     VL53L_WrMulti
#define VL53L5CX_Reset_Sensor VL53L_Reset_Sensor
#define VL53L5CX_SwapBuffer  VL53L_SwapBuffer
#define VL53L5CX_WaitMs      VL53L_WaitMs

#ifdef __cplusplus
};
#endif

#endif	// _PLATFORM_VL53L5CX_H_
