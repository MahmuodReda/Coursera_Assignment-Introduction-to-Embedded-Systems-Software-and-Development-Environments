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
# 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      compile-all: Compile all object files, but DO NOT link.
#      build: Compile all object files and link into a final executable.
#      clean:remove all compiled objects, preprocessed outputs, 
#            assembly outputs, executable files and build output files.
# Platform Overrides:
#      HOST 
#      MSP432
# EXAMPLE:
#      make build PLATFORM=HOST
#      ./c1m2.out
#      make clean
#------------------------------------------------------------------------------
include sources.mk

OUTPUT = c1m2
LINKER_FILE = ../msp432p401r.lds
VFLAG= -DVERBOSE
COMMONFLAGS = $(INCLUDES) $(TARGET) $(VFLAG) -Wall -std=c99 -g -DCOURSE1
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	SRCS = $(SOURCESHOST)
	INCLUDES = $(INCLUDESHOST)
	TARGET = -DHOST
	SIZETOOL = size -A
	CFLAGS = $(COMMONFLAGS)
	CPPFLAGs = -E
	LDFLAGS = -Xlinker -Map=$(OUTPUT).map 
	OBJUMP = objdump -d -M intel -S $< > $@
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SRCS = $(SOURCESMSP)
	INCLUDES = $(INCLUDESMSP)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs 
	TARGET = -DMSP432 
	CPPFLAGs = -E
	LDFLAGS = -Wl,-Map=$(OUTPUT).map -T $(LINKER_FILE)
	SIZETOOL = arm-none-eabi-size -Ad
	OBJUMP = arm-none-eabi-objdump -d -S $< > $@
        EXTRA = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CFLAGS =  $(COMMONFLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) $(EXTRA)
	

		
endif


# Platform Overrides
PLATFORM = 
#Deps for every file
DEPS = $(SRCS:.c=.d)

OBJS = $(SRCS:.c=.o)

PPS = $(SRCS:.c=.i)

ASMS = $(SRCS:.c=.asm)

#Compile files but don't link try (make main.o)
%.o : %.c 
	$(CC) -MMD -MP -c  $<  $(CFLAGS) -o $@

#generate preprocessed files 
%.i : %.c
	$(CC)  $(CPPFLAGs) $< $(CFLAGS) -o $@

#Generate Readable assembly file, you can read it try (cat main.asm)
%.asm : $(OBJS)
	$(OBJUMP)
	





.PHONY: compile-all
compile-all:
	$(CC) -c $(CFLAGS) $(SRCS)


.PHONY: build
build: all

.PHONY: all
all: $(OUTPUT).out

#SIZE tool, everytime you build will get you a report about size in the command line
$(OUTPUT).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS)  $(LDFLAGS) -o $@ -lm
	$(SIZETOOL) $(OUTPUT).out


.PHONY: clean
clean:
	rm -f $(OBJS) $(PPS) $(ASMS) $(DEPS) $(OUTPUT).out $(OUTPUT).map



