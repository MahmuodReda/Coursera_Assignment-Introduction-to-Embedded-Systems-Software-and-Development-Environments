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
 * @file stats.c 
 * @brief This program analysis an array and print the analysis.
 *
 * This program performs functions on arrays, sorting, find the maximum element,
 * 
 *
 * @author Esraa Khaled
 * @date 2 Jun 2020
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)



/* Add other Implementation File Code Here */

/* This function sorts an array from largest to smallest. */
void sort_array(unsigned char * arr , unsigned int arr_length){
  int i,j;
  unsigned char Max,temp;
  for(i=0;i<arr_length;i++){
    Max = arr[i];
    for(j=i+1; j <arr_length;j++){
      if ( arr[j] > arr[i]){
        Max = arr[j];
        temp = arr[i];
        arr[i]= Max;
        arr[j]= temp;
      }
    }
    
  }
}

/* This function returns the maximum element in an 1D-array */
unsigned char find_maximum(unsigned char * arr, unsigned int arr_length){

  int i;
  unsigned char Maximum = arr[0];
  for(i=1;i<arr_length;i++){
    if(arr[i]>Maximum){
      Maximum = arr[i];
    }
    else {
    /* It's preferred to add else even with no code */
    }
  } 
  return Maximum; 
}

/* This function returns the minimum element in 1D-array */
unsigned char find_minimum(unsigned char * arr, unsigned int arr_length){

  int i;
  unsigned char Minimum = arr[0];
  for(i=1;i<arr_length;i++){
    if(arr[i]<Minimum){
      Minimum = arr[i];
    }
    else {
    /* It's preferred to add else even with no code */
    }
  } 
  return Minimum; 
}

/* This function returns the mean of 1D-array */
unsigned char find_mean(unsigned char * arr, unsigned int arr_length){
  /* The sum variable we shouldn't use unsigned char because it will cause overflow */
  int sum = 0;
  int i;
  /* Calculting sum of all elements in array */
  for(i=0;i<arr_length;i++){
    sum += arr[i];
    
  }
  //printf("%d \n",sum);
  float Mean_unrounded = sum / arr_length;
  int Mean = Mean_unrounded;
  return Mean;
  
}

/* This function returns the median of 1D-array */
unsigned char find_median(unsigned char * arr, unsigned int arr_length){

  sort_array(arr,arr_length);
  float median_unrounded = 0;
  /* First we have to check if the array has odd or even number of elements */
  if(arr_length % 2 == 0){
    median_unrounded = ( arr[(arr_length/2)-1] + arr[(arr_length/2)] ) /2;
  }
  else {
    median_unrounded = arr[arr_length/2];
  }
  int median = median_unrounded;
  return median;  
}

/* This function prints the elements of 1D-array. */
void print_array(unsigned char * arr, unsigned int arr_length){
  if(PORNOT == 1){
    int i;
    for(i=0 ; i <arr_length ; i++){
      if (i==0){
        PRINTF("{ %d,", arr[0]);
      }
      else if (i==(arr_length-1)){
        PRINTF(" %d }\n",arr[arr_length-1]);
      }
      else {
        PRINTF(" %d," , arr[i]);
      }
    
    }
  }
  else { return;}
}

/* This function prints the statistics of an array */
void print_statistics(unsigned char * arr, unsigned int arr_length){

  unsigned char Max,Min, Median, Mean;
  Max = find_maximum(arr,arr_length);
  Min = find_minimum(arr,arr_length);
  Median = find_median(arr,arr_length);
  Mean = find_mean(arr,arr_length);
  print_array(arr,arr_length);
  printf("In this array :\n  -Maximum = %d \n  -Minimum = %d \n  -Mean = %d \n", Max, Min, Mean);
  printf("  -Median = %d \n",Median);
  printf("And the sorted array is : \n");
  print_array(arr,arr_length);
          
}

