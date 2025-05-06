
C Pointer & Struct




This session focuses on mastering low-level pointer arithmetic, struct memory layout, and pointer-to-struct manipulation in ANSI C.
It simulates operations common in embedded sensor systems: value swapping, sorting, and memory inspection.

🧰 Tools Used
Tool / Feature	Purpose
GCC / Clang	Compiling and running .c files
VSCode / CLI	Editor / terminal work
sizeof()	Struct size evaluation
%p, (void*)	Memory address inspection

⚙️ Subsystems & Logic
Pointer Arithmetic – Navigation through arrays using *p, p[i], *(p+i)

Swap Functions – Swapping values and structs using pointer logic

Struct Memory Mapping – Understanding field alignment and padding

Pointer-to-Struct (->) – Clean access to struct members

Sensor Sorting System – Rank and sort struct array by reading value

💻 Code Files
🔸 ptr_math.c
Simulates raw pointer math on an integer array.

Key functions:

*p, *(p+i), p[i]

p++, ++p

🔸 swap_func.c
Swaps two integers via pointers.

Concepts:

*a, *b dereferencing

Temporary buffering logic

🔸 struct_mem.c
Prints memory layout of a struct Sensor and explains padding.

Concepts:

sizeof()

%p to inspect addresses

Alignment visualization

🔸 struct_pointer_access.c
Access and modify a struct using a pointer.

Concepts:

ptr->field

*ptr vs ptr->

🔸 sensor_swap.c
Compares two sensor structs and swaps them using pointer-based logic.

Logic:

If Sensor A has a higher value, swap it with B

Inspect memory layout and struct field changes

🔸 sensor_compare_system.c
Mini-project: Sorts 3 sensors by reading value using pointer-based swap logic.

Key Features:

Struct array simulation

Sorting without stdlib

Full memory address print for each field

Prints sorted sensor list

🧠 Concepts Practiced
Pointer fundamentals

Struct-based data modeling

Memory layout prediction

Function design with pointers

Manual sorting algorithms

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  

