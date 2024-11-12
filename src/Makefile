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
#      <FILE>.o -Builds <FILE>.o object file
#      <FILE>.i -Builds <FILE>.i preproccessed file
#      <FILE>.asm -Builds <FILE>.asm assembly file
#      compile-all -compile all object files, but DO NOT link
#      build -Builds and links all source files
#      clean -removes all generated files
#
# Platform Overrides:
#      PLATFORM - the target platform ( Host , MSP432 )
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#common Flags
FLAGS = -Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99
TARGET = c1m2

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = $(FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
endif

ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
    LINKER_FILE = -T msp432p401r.lds
    LINKER_FILE_PATH = -L ../
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
    OTHER_ARCH_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16

    SOURCES = main.c \
	      memory.c \
	      interrupts_msp432p401r_gcc.c \
	      startup_msp432p401r_gcc.c \
	      system_msp432p401r.c

# Compiler Flags and Defines
    CC = arm-none-eabi-gcc
    LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE_PATH) $(LINKER_FILE)
    CFLAGS = $(FLAGS) $(OTHER_ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
    CPPFLAGS = -DMSP432 $(INCLUDES)
    SIZE = arm-none-eabi-size
    
endif

#making variables for object files, dependency files, assembly files, preprocessed files
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

#using -c flag to stop before linking, so i only need CPPFLAGS & CFLAGS
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -S flag to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -E flag to generate preprocessed, so i only need CPPFLAGS
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#using -E -M flag to generate dependency files
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

#compile-all will generate all object files for all source files without linking
.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build:$(DEPS)
build:$(TARGET).out

$(TARGET).out:$(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map
