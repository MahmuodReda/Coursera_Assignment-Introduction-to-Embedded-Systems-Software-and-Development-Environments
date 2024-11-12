/**
 * @file data.c
 * @brief implementations of data maniuplation functions.
 *
 *
 * @author Esraa khaled
 * @date June 6 2020
 *
 */
#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t i=1;
  uint8_t* new_Data;
  int32_t num =data;
  int length = 0;

  do
  {
    length++;

    num /= 10;
  } while(num != 0);
  
  new_Data = (uint8_t*) reserve_words(length+1);

  while(data !=0){
    
    new_Data[length-i] =  data % base;
    data = data / base;
    i++;
    
  }  
  my_memcopy( new_Data, ptr,length);

  new_Data[length+1]= '\0';


  return (length+1);

    
  
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  uint8_t length = digits-1;
  uint32_t value = 0;
  uint8_t i;
  for(i=0;i<length;i++)
   {  value += (*(ptr+length-1-i)) * (pow(base, i)); }
   return value; 
   
}
