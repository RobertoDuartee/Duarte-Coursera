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
 * @file <stats.c> 
 * @brief <c code for stats >
 *
 * <The code implement some basic statistic functions given a data set>
 *
 * @author <Roberto Duarte>
 * @date <15/06/2022>
 *
 */



#include <stdio.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

/* Size of the Data Set */
#define SIZE (40)

int len;
unsigned char *sorted_array;
int min;
int max;
float median;
float mean;

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  len = sizeof(test)/sizeof(test[0]);
  printf("length of the array: %i\n",len);


  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Original Array: ");
  print_array(test,len);

  sorted_array = sort_array(test,len);
  printf("\nSorted Array: ");
  for(int i = 0;i<len;i++){
    printf("%d,",sorted_array[i]);
  }

  median = find_median(sorted_array,len);
  mean = find_mean(sorted_array,len);
  min = find_minimum(sorted_array,len);
  max = find_maximum(sorted_array,len);

  print_statistics(min,max,mean,median);

  return(0);

}


void print_array(unsigned char array[],unsigned int length){
  /*
  for(int i = 0;i<length;i++){
    printf("%d,",array[i]);
  }*/
  #ifdef VERBOSE
    for(int =0;i<length;i++){
      PRINTF("%d,",array[i]);
    }
    PRINTF("\n");
  #endif
}

unsigned char * sort_array(unsigned char array[],unsigned int length){
  int value;

  for(int i = 0;i<length;i++){
    for(int j = i+1;j<length;j++){
      if(array[i]>array[j]){
        value = array[i];
        array[i] = array[j];
        array[j] = value;
      }
    }
  }
  /*for(int i = 0;i<length;i++){
    printf("%d,",array[i]);
  }*/
  return array;
}

void print_statistics(int min,int max,int mean,int median){
  printf("\nMinimum: %d",min);
  printf("\nMaximum: %d",max);
  printf("\nMean: %i",mean);
  printf("\nMedian: %i\n",median);
}

int find_median(unsigned char array[],unsigned int length){
  int median;
  if(length%2 == 0){
    median = (array[length/2-1]+array[length/2])/2.0;
  }
  else{
    median = array[length/2+1];
  }
  return median;
}

int find_mean(unsigned char array[],unsigned int length){
  int sum = 0;
  
  for(int i = 0;i<length;i++){
    sum = sum + array[i];
  }
  sum = sum/length;
  return sum;
}

int find_minimum(unsigned char array[],unsigned int length){
  int min;
  min = array[0];
  for(int i = 0;i<length;i++){
    if(array[i]<min){
      min = array[i];
    }
  }
  return min;
}

int find_maximum(unsigned char array[],unsigned int length){
  int max;
  max = array[0];
  for(int i = 0;i<length;i++){
    if(array[i]>max){
      max = array[i];
    }
  }
  return max;
}

/* Add other Implementation File Code Here */
