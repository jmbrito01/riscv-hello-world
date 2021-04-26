#include "sys.h"
#include "userland.h"

uint64_t get_clock_cycles();
int m_read_hart_id();

int _userland u_main() {
    sys_puts("Hello from U-mode!\n");

    sys_puts("C Done.\n");
    return 0;
}

int _userland u_main2() {
    sys_puts("Hello from U-mode 2!\n");

    sys_puts("C Done.\n");

    return 0;
}

uint64_t _userland get_clock_cycles() {
    register uint64_t a0 asm ("a0");
#if XLEN == 64
    asm volatile (
        "csrr a0, cycle"
        : "=r"(a0)  // output in a0
    );
#elif XLEN == 32
    // TODO
#else
    #error Unknown xlen
#endif
    return a0;
}

int _userland m_read_hart_id() {
    register int a0 asm ("a0");
    asm volatile (
        "csrr a0, mhartid"
        : "=r"(a0)  // output in a0
    );
    return a0;
}

void _userland push_pop_stack() {
    asm(
#if XLEN == 64
        "addi sp, sp, -16;"
        "ld   t0, 0(sp);"
        "ld   t1, 8(sp);"
        "sd   t0, 0(sp);"
        "sd   t1, 8(sp);"
        "addi sp, sp, 16;"
#elif XLEN == 32
        "addi sp, sp, -8;"
        "lw   t0, 0(sp);"
        "lw   t1, 4(sp);"
        "sw   t0, 0(sp);"
        "sw   t1, 4(sp);"
        "addi sp, sp, 8;"
#else
    #error Unknown xlen
#endif
    : // no output
    : // no input
    : "t0", "t1"  // t0 and t1 get clobbered
    );
}
