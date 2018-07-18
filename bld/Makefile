LIB = libmspmath


OBJECTS = \
	mult.o \
	sqrt.o \

ifeq ($(TOOL),)
  $(warning TOOL IS EMPTY)
else
  $(warning libmspmath TOOL = ${TOOL})
  ifeq ($(TOOL),gcc)
    $(warning failure!)
  else
    $(warning success again!)
    OBJECTS += divmodhi3.o
  endif
endif

ifeq ($(TOOL),gcc)
  $(warning adding hwmult flag)
#Added to suppress complaints from libgcc about mulsi2_f5
  -mhwmult=none \
else
  $(warning adding divmodhi)
  OBJECTS += divmodhi3.o
endif # TOOLCHAIN = clang

ifneq ($(DIVMOD),)
  OBJECTS += \
  divmodhi3.o
else
  $(warning DIVMOD Has value)
endif

$(info toolchain = ${TOOLCHAIN}, tool = ${TOOL})

override SRC_ROOT = ../../src

override CFLAGS += \
	-I$(SRC_ROOT)/include/libmspmath \
