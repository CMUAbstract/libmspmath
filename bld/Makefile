LIB = libmspmath

OBJECTS = \
	mult.o \
	sqrt.o \

ifeq ($(TOOLCHAIN),clang)
OBJECTS += divmodhi3.o
endif # TOOLCHAIN = clang

override SRC_ROOT = ../../src

override CFLAGS += \
	-I$(SRC_ROOT)/include/libmspmath \
