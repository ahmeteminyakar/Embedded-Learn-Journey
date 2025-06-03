#include <stdio.h>

// Write to a register using offset
void write_register(int* base, int offset, int value) {
    *(base + offset) = value;
}

int main() {
    // Register Map
    int regs[6] = {
        0x00000000,  // CTRL_REG
        0x00000000,  // STATUS_REG
        0x11223344,  // CONFIG_A
        0x55667788,  // CONFIG_B
        0xDEADBEEF,  // ERROR_REG
        0xCAFEBABE   // FINAL
    };

    int* ptr = regs;

    // Modify CONFIG_B via offset write
    write_register(regs, 3, 0xABCDEF99);

    // Modify CTRL_REG via alias pointer
    int* ptr_alias = &regs[0];
    *ptr_alias = 0x12345678;

    // Print all register values, addresses and deltas
    for (int i = 0; i < 6; i++) {
        printf("---------- regs[%d] ----------\n", i);
        printf("Value     : 0x%x\n", *(ptr + i));
        printf("Address   : %p\n", (void*)(ptr + i));
        printf("Delta     : %ld bytes from base\n", (char*)(ptr + i) - (char*)ptr);

        // Optional: Byte-level breakdown
        unsigned char* bytewise = (unsigned char*)(ptr + i);
        printf("Bytes     : %02x %02x %02x %02x\n",
               bytewise[0], bytewise[1], bytewise[2], bytewise[3]);
    }

    // Modify byte 1 of CONFIG_A (regs[2])
    char* byteView = (char*)&regs[2];
    byteView[1] = 0x77;
    printf("Modified CONFIG_A: 0x%x\n", regs[2]);

    // Pointer-to-pointer: modify ERROR_REG
    int* err_ptr = &regs[4];
    int** pptr = &err_ptr;
    **pptr = 0xABCDABCD;
    printf("Modified ERROR_REG via **pptr: 0x%x\n", regs[4]);

    return 0;
}
