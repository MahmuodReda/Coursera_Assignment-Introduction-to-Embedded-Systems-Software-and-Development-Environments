/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief file contains declertions of functions.
 *
 * This file is all you need to understand every function used in this program.
 * contains declertions of functions and comment block to show every parameter
 * and the return type if any.
 *
 * @author Esraa khaled
 * @date 2 Jun 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


#if defined (VERBOSE)

#define PORNOT  1

#else

#define PORNOT  1

#endif

void sort_array(unsigned char * arr , unsigned int arr_length); 

/**
 * @brief sorts an array from largest to smallest.
 *
 * Given a pointer to an array and the length of the same array,
 * this function sorts the array from largest to smallest.
 * The zero index holds the largest, and (n-1) index holds the smallest.
 * note that this function uses the find_maximum function as a part of
 * it's algorithm.
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return There is no return to this function.
 */

unsigned char find_maximum(unsigned char * arr, unsigned int arr_length);

/**
 * @brief return the maximum element in a 1D-array
 *
 * Given a pointer to an array and the length of the same array, 
 * this function loops in the whole array and search for the
 * largest element then return it.
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return the largest element in form of unsigned char data.
 */

unsigned char find_minimum(unsigned char * arr, unsigned int arr_length);

/**
 * @brief return the minimum element in a 1D-array
 *
 * Given a pointer to an array and the length of the same array, 
 * this function loops in the whole array and search for the
 * smallest element then return it.
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return the smallest element in form of unsigned char data.
 */

unsigned char find_mean(unsigned char * arr, unsigned int arr_length);

/**
 * @brief return the mean of 1D-array
 *
 * Given a pointer to an array and the length of the same array, 
 * this function loops in the whole array and add the elements 
 * then calculate the mean and round it down to the nearest integer
 * and return the mean.
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return the mean of array in form of unsigned char data.
 */

unsigned char find_median(unsigned char * arr, unsigned int arr_length);

/**
 * @brief return the median of 1D-array
 *
 * Given a pointer to an array and the length of the same array, 
 * this function sort tha array using sort_array() 
 * function then return the median.
 * 
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return the median of array in form of unsigned char data.
 */

void print_array(unsigned char * arr, unsigned int arr_length);

/**
 * @brief prints the elements of 1D-array.
 *
 * Given a pointer to an array and the length of the same array, 
 * this function print the elements by order.
 * 
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return There is no return type
 */

void print_statistics(unsigned char * arr, unsigned int arr_length);

/**
 * @brief prints the elements of 1D-array.
 *
 * Given a pointer to an array and the length of the same array, 
 * this function print prints the statistics of an array including
 * minimum, maximum, mean, and median.
 * note that this function is using other functions.
 *
 * @param arr The pointer to unsigned n-elements array.
 * @param arr_length  the n(length) of the array sent.
 *
 * @return There is no return type
 */

#endif /* __STATS_H__ */
