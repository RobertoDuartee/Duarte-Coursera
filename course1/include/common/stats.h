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
 * @file <stats.h> 
 * @brief <It is a header for c file >
 *
 * <It is a header for a code that analyze and report analytics on the 
maximum, minimum,mean and median of a data set>
 *
 * @author <Roberto Duarte>
 * @date <15/06/2022>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <prints min,max,mean,meadian>
 *
 * <The function will receive 4 integer values an it will print them on temrinal>
 *
 * @param <min> <minimum value of a given array>
 * @param <max> <maximum value of a given array>
 * @param <mean> <the mean of the array>∫∫
 * @param <median> <The median of the array>
 *
 * @return <It will not return anything but it will print the calculated mean,median,min,max>
 */
void print_statistics(int min,int max,int mean,int median);
/**
 * @brief <print given array>
 *
 * <This function prints the input array>

 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 * 
 * @return <it will not return anything but it will print the orignial vector>
 */
void print_array(unsigned char array[],unsigned int length);

/**
 * @brief <finds median value of an array input>
 *
 * <This function finds the median value of an input array>
 *
 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 *
 * @return <it will return the median as a float type>
 */
int find_median(unsigned char array[],unsigned int length);
/**
 * @brief <finds mean value of an input array>
 *
 * <This funciton finds the mean value of an input array>
 *
 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 *
 * @return <it will return the mean as float type>
 */
int find_mean(unsigned char array[],unsigned int length);
/**
 * @brief <finds minimum value of an array>
 *
 * <This function finds the minomum value of an array>
 *
 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 *
 * @return <it will return the minimum value as int type>
 */
int find_minimum(unsigned char array[],unsigned int length);
/**
 * @brief <finds maximum value of an array>
 *
 * <This function finds maximum value of an array>
 *
 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 *
 * @return <it will return the maximum value as int type>
 */
int find_maximum(unsigned char array[],unsigned int length);
/**
 * @brief <Sorts an input array>
 *
 * <This function sorts an input array in ascending order>
 *
 * @param <array> <an array of numbers>
 * @param <lenght> <length of the array>
 *
 * @return <it will return a vector sorted in ascending order as char type>
 */
unsigned char * sort_array(unsigned char array[],unsigned int length);
#endif /* __STATS_H__ */

