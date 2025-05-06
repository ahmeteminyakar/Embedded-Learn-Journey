#include <stdio.h>

struct Sensor {
    char id;
    int value;
    char status;
};

void swapSensors(struct Sensor *a, struct Sensor *b) {
    struct Sensor temp = *a;
    *a = *b;
    *b = temp;
}

void printSensor(struct Sensor *s) {
    printf("Sensor %c:\n", s->id);
    printf("  Value  : %d\n", s->value);
    printf("  Status : %c\n", s->status);
    printf("  Memory layout:\n");
    printf("    &id     : %p\n", (void*)&s->id);
    printf("    &value  : %p\n", (void*)&s->value);
    printf("    &status : %p\n", (void*)&s->status);
    printf("    sizeof  : %lu\n\n", sizeof(*s));
}

int main() {
    struct Sensor A = {'A', 740, 'O'};
    struct Sensor B = {'B', 620, 'O'};

    printf("== BEFORE SWAP ==\n");
    printSensor(&A);
    printSensor(&B);

    if (A.value > B.value) {
        swapSensors(&A, &B);
    }

    printf("== AFTER SWAP ==\n");
    printSensor(&A);
    printSensor(&B);

    return 0;
}
