#include "../include/common/data.h"
#include "../include/common/memory.h"
#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    //int32_t buff;
    uint8_t sign;
    uint8_t i=0;


    if(data == 0){
        *(ptr) = '0';
        *(ptr + 1) = '\0';

        return 2;
    }

    if(data < 0 && base == 10){
        sign = 1;
        data = data*-1;
    }

    while(data != 0){
        *(ptr + i) = data%base;
        i++;
        data = data/base;
    }

    if(sign == 1){
        *(ptr + 1) = '-';
        i++;
    }
    *(ptr + i) = '\0';
    i++;

    my_reverse(ptr,(i-1));
    return i;


}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int32_t data;
    uint8_t sign;

    if(*ptr == '-'){
        sign = 1;
        ptr++;
        digits--;
    }

    digits--;

    for(int i = 0;i<digits;i++){
        data = data * base + *ptr - '0';
        ptr++;
    }

    if(sign){
        data = -1*data;
    }
    return data;
}