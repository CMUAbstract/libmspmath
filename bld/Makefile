LIB = libmspmath

OBJECTS = \
	mult.o \
	sqrt.o \

ifeq ($(TOOLCHAIN),gcc)
else
OBJECTS += divmodhi3.o
endif # TOOLCHAIN = clang

override SRC_ROOT = ../../src

ifeq ($(TOOLCHAIN),ticl)
override CFLAGS += \
	--include_path="$(SRC_ROOT)/include/libmspmath"
else
override CFLAGS += \
	-I$(SRC_ROOT)/include/libmspmath
endif
