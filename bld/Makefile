LIB = libmspmath

ifeq ($(TOOL),)
  $(warning TOOL IS EMPTY)
else
  $(warning TOOL = ${TOOL})
endif

ifeq ($(TOOL),gcc)
  $(warning adding hwmult flag)
#Added to suppress complaints from libgcc about mulsi2_f5
  -mhwmult=none \
else
  $(warning adding divmodhi)
  OBJECTS += divmodhi3.o
endif # TOOLCHAIN = clang

OBJECTS = \
	mult.o \
	sqrt.o \

ifneq ($(DIVMOD),)
  OBJECTS += \
  divmodhi3.o
endif

$(info toolchain = ${TOOLCHAIN}, tool = ${TOOL})

override SRC_ROOT = ../../src

override CFLAGS += \
	-I$(SRC_ROOT)/include/libmspmath \
