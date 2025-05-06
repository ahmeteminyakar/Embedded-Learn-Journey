#include <stdio.h>

struct Sensor {
    char id;       // 1 byte
    int value;     // 4 bytes
    char status;   // 1 byte
};

int main() {
    struct Sensor s = {'A', 1234, 'O'};

    printf("Size of struct: %lu bytes\n", sizeof(s));

    printf("Address of s.id     : %p\n", (void*)&s.id);
    printf("Address of s.value  : %p\n", (void*)&s.value);
    printf("Address of s.status : %p\n", (void*)&s.status);

    return 0;
}
