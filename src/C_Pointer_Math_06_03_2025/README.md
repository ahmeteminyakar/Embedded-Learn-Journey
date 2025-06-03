# 🧠 C_Pointer_Math

This folder contains progressive exercises, explanations, and experiments focused on pointer arithmetic, memory access, and array interactions in C. The goal is to master memory-level thinking, dereferencing logic, and pointer-based manipulation—crucial for embedded systems.

---

## 📅 Study Session: June 2–3, 2025

### ✅ Topics Covered
- Pointer declaration and dereferencing
- Pointer arithmetic
- Array-pointer relationship
- Address calculation and memory delta
- Typecasting pointers (e.g., `int*` ↔ `char*`)
- Memory aliasing (`int**` and indirect access)
- Function-based pointer manipulation (`void write_register(...)`)
- Memory layout inspection with `%p` and `%ld`
- Byte-level modification of multi-byte integers

---

## 🗂 File Overview

| File Name              | Description                                                       |
|------------------------|-------------------------------------------------------------------|
| `day01_ptr_math.c`     | Fundamentals: `int*`, dereferencing, address printing             |
| `pointer_array.c`      | Array traversal using pointer arithmetic                          |
| `pointer_tasks.c`      | Combined challenge including all learned concepts                 |
| `byte_view_demo.c`     | Casting to `char*` and modifying individual bytes of an `int`     |
| `pointer_challenge.c`  | Final complex task using registers, aliasing, and offset writing  |

---

## 🔧 Key Functions

### `void write_register(int* base, int offset, int value);`
> Abstracted memory manipulation function to simulate hardware register writes.

```c
write_register(regs, 2, 0xABCD1234);


*(base + offset)
Core pattern used for offset-based memory access, simulating register maps.
```c
🧠 Core Learnings
int* ptr = &val; → Points to variable’s address

*(ptr + i) → Access i-th offset in memory, assuming element type size

(char*)ptr → Cast to byte-wise pointer to analyze or modify data

Pointer arithmetic is scaled by type size

int** (double pointers) allow layered memory abstraction (important for RTOS and drivers)

%p → Pointer (memory address), (void*) cast is required

%x or %X → Hexadecimal representation of values

%ld → Signed long decimal, used for pointer distance in bytes


