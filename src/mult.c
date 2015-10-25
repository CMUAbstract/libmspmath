#include <msp430.h>
#include <stdint.h>

// NOTE: This is not implemented as a built-in in libmspbuiltins because Clang
// doesn't issue calls to operations where result type is different from
// argument type. But this case is more efficient and easier to implement than
// a full 32-bit multiplication.

__attribute__((naked))
uint32_t mult16(uint16_t a, uint16_t b)
{
    // NOTE: We have to hardcode addresses, because we ca neither access
    // definitions from the header inside the assembly, nor parametrize
    // the assembly snippet since function is naked. A non-naked function
    // with parametrized snipped turned out to be horribly inefficient
    // (the result construction needs a shift: 8 instructions...).

    // NOTE: The registers are dependent on Clang's calling convention.

    // Load OP1 and OP2 into the hardware multiplier and read result.

    __asm__ volatile (
        "MOV R15, &0x04C0\n"
        "MOV R14, &0x04C8\n"
        "MOV &0x04CA, R14\n"
        "MOV &0x04CC, R15\n"
        "RET\n"
    );
}
