#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides

ifeq ($(PLATFORM),HOST) #------------------------------HOST
  CC = gcc
  LD = ld
  SIZE = size
  LDFLAGS = -Wl,-Map=$(TARGET).map
  OBJDUMP = objdump
  CFLAGS = -Wall -Werror -g -O0 -std=c99
  DEFFLAG = -DHOST
  $(info    HOST SELECTED)
else #------------------------------MSP432

  LINKER_FILE = ../msp432p401r.lds
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  LDFLAGS = -Wl,-Map=$(TARGET).map,-T $(LINKER_FILE)
  CFLAGS = -Wall -O0 -g -std=c99 -mcpu=cortex-m4 -mthumb -march=armv7e-m  -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
  OBJDUMP = arm-none-eabi-objdump
  DEFFLAG = -MSP432
  $(info    ARM SELECTED)
endif

ifeq ($(VERBOSE), VERBOSE)
  VER=-g
endif


CPPFLAGS = -E
#CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES) -D$(PLATFORM) $(ARMFLAGS) -D$(VERBOSE) -D$(COURSE1)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
PREP = $(SOURCES:.c=.i)
ASM = $(SOURCES:.c=.asm)
MAPS = $(SOURCES:.c=.map)
OUTS = $(SOURCES:.c=.out)
TARGET = course1



#--------------------Build Target Guidelines
%.i : %.c
	$(CC) $(DEFFLAG) $(CPPFLAGS) $< $(CFLAGS) -o $@


%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

#--------------------Compile All
.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o


#--------------------Build
.PHONY: build
build: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

#--------------------Clean
FILES = *.asm *.i *.o *.d
.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREP) $(ASM) $(DEPS) $(OBJS)
