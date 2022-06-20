#include "../include/common/platform.h"
#include "../include/common/data.h"
#include "../include/common/course1.h"
#include "../include/common/memory.h"
#include "../include/common/stats.h"

int main(){
    #ifdef COURSE1
      course1();
      return 0;
    #endif
    return(0);
}