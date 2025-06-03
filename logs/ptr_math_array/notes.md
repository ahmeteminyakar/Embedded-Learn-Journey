# 🧠 Pointer Math & Array Interaction — Full Notes  
🗓️ **Session Dates**: June 2–3, 2025  
📁 **Path**: logs/ptr_math_array/notes_pointer_math_array.md  
🎯 **Goal**: Understand memory, pointer arithmetic, dereferencing, and how arrays relate to pointers in C.

---

## 🧩 1. Pointer Basics

```c
int x = 42;
int* p = &x;
Key Concepts
Syntax	Meaning
int* p	Declare pointer to an int
p = &x	Assign address of x to p
*p	Dereference p (get value at addr)
*p = *p + 10	Modify the value at pointer


printf("Address: %p\n", (void*)p);
printf("Value: %d\n", *p);
%p: Prints memory address (needs cast to void*)

%d: Decimal value

%x: Hexadecimal representation (e.g. 0xFF)

🧠 2. Pointers and Arrays

int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;
Pointer ↔️ Array Relationship
Expression	Equivalent
arr[i]	*(arr + i)
ptr[i]	*(ptr + i)

✅ Arrays are stored contiguously in memory.
Pointer arithmetic steps by size of type (e.g., 4 bytes for int).

📏 3. Address Delta (Memory Step Size)

printf("%ld", (char*)&arr[i] - (char*)&arr[i - 1]);
Cast to (char*) to do byte-level subtraction.

For int: address step is usually 4 bytes.

🔁 4. Pointer as Function Parameter

void add_offset(int* base, int offset) {
    *(base + offset) += 100;
}
Used to:

Modify values in arrays/registers via offset

Write into memory locations relative to base

🧪 Called as: add_offset(arr2, i);

🪛 5. Viewing Data as Bytes

int val = 0x12345678;
char* view = (char*)&val;
Byte Access:

printf("Byte[0] = 0x%x", view[0]); // Least Significant Byte
Modification:

view[1] = 0x99;
🎯 Used in:

Embedded memory maps

Bit-field hacking

Protocol decoders

🔄 6. Double Pointer (Pointer to Pointer)

int final = 0xBEEFCAFE;
int* ptr = &final;
int** pptr = &ptr;
**pptr = 0xABCDABCD;
Used in:

Pass-by-reference of pointer

Multilevel indirection (e.g., 2D array, dynamic memory)

API handles or memory driver abstraction

🛠️ 7. Register Simulation & Memory Log

int regs[6] = {
  0x00000000, // CTRL_REG
  0x00000000, // STATUS_REG
  0x11223344, // CONFIG_A
  0x55667788, // CONFIG_B
  0xDEADBEEF, // ERROR_REG
  0xCAFEBABE  // FINAL
};
Manipulated via:

write_register(regs, 3, 0xABCDEF99);

char* byteView = (char*)&regs[2]; byteView[1] = 0x77;

Full Memory Dump:

for (int i = 0; i < 6; i++) {
  printf("regs[%d] = 0x%x at %p\n", i, *(regs+i), (void*)(regs+i));
}