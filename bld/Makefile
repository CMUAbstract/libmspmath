LIB = libmspmath

OBJECTS = \
	mult.o \
	sqrt.o \

ifeq ($(TOOLCHAIN),gcc)
#Added to suppress complaints from libgcc about mulsi2_f5
-mhwmult=none \
else
OBJECTS += divmodhi3.o
endif # TOOLCHAIN = clang

override SRC_ROOT = ../../src

override CFLAGS += \
	-I$(SRC_ROOT)/include/libmspmath \
