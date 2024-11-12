/**
 * @file data.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Esraa Khaled
 * @date june 6 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include "memory.h"
#include <math.h>
#include "course1.h"


/**
 * @brief Integer-to-ASCII 
 *
 * Convert data from a standard integer type into an ASCII string.
 *
 * @param data is the number you wish to convert as a signed 32-bit integer.
 * @param ptr pointer to where the converted characters will be copied
 * @param base the base from 2 -16
 *
 * @return the length of the converted data.
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer 
 *
 * Convert data from an ASCII represented string into an integer type.
 *
 * @param data is the character string you wish to convert.
 * @param ptr pointer to where the converted characters will be copied
 * @param base the base from 2 -16
 *
 * @return the length of the converted data.
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);






#endif
