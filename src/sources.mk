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

# Sources and includes for msp432

SOURCESMSP = main.c \
	     memory.c \
	     stats.c \
	     data.c \
	     course1.c \
	     interrupts_msp432p401r_gcc.c \
	     startup_msp432p401r_gcc.c \
	     system_msp432p401r.c

INCLUDESMSP = -I../include/common/ \
	      -I../include/msp432/ \
	      -I../include/CMSIS/

# Sources and includes for Host

SOURCESHOST = main.c \
	      memory.c \
	      stats.c \
	      data.c \
	      course1.c



	
INCLUDESHOST = -I../include/common
	      




