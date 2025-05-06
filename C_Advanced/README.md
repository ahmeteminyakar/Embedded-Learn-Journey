# 🔧 C Pointer & Struct Mastery

Low-level pointer and memory operations using ANSI C, simulating embedded system data handling patterns such as sensor swapping, struct sorting, and memory inspection.

---

## 📦 Project Modules

| File | Description |
|------|-------------|
| `ptr_math.c` | Demonstrates raw pointer arithmetic over integer arrays using `*p`, `p[i]`, and `*(p+i)` syntax. |
| `swap_func.c` | Swaps two integers via pointer dereferencing. Core logic with `*a`, `*b`, and temporary variable buffering. |
| `struct_mem.c` | Visualizes memory layout, alignment and padding of a `Sensor` struct using `%p` and `sizeof()`. |
| `struct_pointer_access.c` | Access and update struct fields via pointer using `->` and `(*ptr).field`. |
| `sensor_swap.c` | Swaps two `Sensor` structs if value A > B using pointer logic. |
| `sensor_compare_system.c` | Mini sorting engine for an array of 3 `Sensor` structs by `reading` value with pointer-based comparison logic. |

---

## 🧠 Core Concepts

- ✅ Pointer arithmetic: `p++`, `*(p+i)`, `p[i]`
- ✅ Pointer-to-struct access: `ptr->field`, `(*ptr).field`
- ✅ Struct padding & memory alignment
- ✅ Swap logic with pointer references
- ✅ Manual sorting without stdlib
- ✅ Memory layout tracing using `%p` casting

---

## ⚙️ Tools & Environment

| Tool / Command | Purpose |
|----------------|---------|
| `GCC / Clang`  | Compile & run `.c` files |
| `VSCode / Terminal` | Code + testing |
| `sizeof()`     | Struct size evaluation |
| `%p`, `(void*)` | Print address for memory visualization |

---

## 🚀 Demo Output Snapshot (Example)

```c
Sensor A: value = 53, address = 0x7ffeefbff5c0  
Sensor B: value = 42, address = 0x7ffeefbff5d0  
Swapped → Sensor A now: value = 42  

```
---
📚 Learning Outcomes
Embedded C pointer fluency

Struct-based modeling for sensor data

Predicting memory layout (alignment/padding)

Designing clean swap & sort logic with pointers

Foundation for embedded systems memory handling


🧩 Future Extension
Add dynamic struct array allocation

Integrate qsort() for performance comparison

Extend Sensor with timestamp & ID fields

Build UART packet encoder for struct data

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  
