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



#include "platform.h"

uint8_t VL53L_RdByte(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_value)
{
	return p_platform->rd_byte_func(p_platform->reference_, RegisterAdress, p_value);
}

uint8_t VL53L_WrByte(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t value)
{
	return p_platform->wr_byte_func(p_platform->reference_, RegisterAdress, value);
}

uint8_t VL53L_WrMulti(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
	return p_platform->wr_bytes_func(p_platform->reference_, RegisterAdress, p_values, size);
}

uint8_t VL53L_RdMulti(
		VL53L_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
	return p_platform->rd_bytes_func(p_platform->reference_, RegisterAdress, p_values, size);
}

uint8_t VL53L_Reset_Sensor(
		VL53L_Platform *p_platform)
{
	return 0;
}

void VL53L_SwapBuffer(
		uint8_t 		*buffer,
		uint16_t 	 	 size)
{
	uint32_t i, tmp;
	
	/* Example of possible implementation using <string.h> */
	for(i = 0; i < size; i = i + 4) 
	{
		tmp = (
		  buffer[i]<<24)
		|(buffer[i+1]<<16)
		|(buffer[i+2]<<8)
		|(buffer[i+3]);
		
		memcpy(&(buffer[i]), &tmp, 4);
	}
}	

uint8_t VL53L_WaitMs(
		VL53L_Platform *p_platform,
		uint32_t TimeMs)
{
	p_platform->delay_func(TimeMs);
	return 0;
}
