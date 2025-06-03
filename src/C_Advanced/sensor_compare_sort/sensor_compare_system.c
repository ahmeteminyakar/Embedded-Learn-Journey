#include <stdio.h>

typedef struct {
    char id;
    int reading;
    char status;
} Sensor;

void printSensor(Sensor *s) {
    printf("ID     : %c\n", s->id);
    printf("Reading: %d\n", s->reading);
    printf("Status : %c\n", s->status);
    printf("Memory layout:\n");
    printf("  &id     : %p\n", (void*)&s->id);
    printf("  &reading: %p\n", (void*)&s->reading);
    printf("  &status : %p\n", (void*)&s->status);
    printf("  sizeof  : %lu\n", sizeof(*s));
    printf("-------------\n");
}

void swapSensors(Sensor *a, Sensor *b) {
    Sensor temp = *a;
    *a = *b;
    *b = temp;
}

void sortSensors(Sensor *a, Sensor *b, Sensor *c) {
    if (a->reading < b->reading)
        swapSensors(a, b);
    if (a->reading < c->reading)
        swapSensors(a, c);
    if (b->reading < c->reading)
        swapSensors(b, c);
}

int main() {
    Sensor A = {'A', 500, 'O'};
    Sensor B = {'B', 670, 'O'};
    Sensor C = {'C', 1000, 'F'};

    printf("== ORIGINAL STATS ==\n");
    printSensor(&A);
    printSensor(&B);
    printSensor(&C);

    sortSensors(&A, &B, &C);

    printf("\n== SORTED STATS (by reading) ==\n");
    printSensor(&A);
    printSensor(&B);
    printSensor(&C);

    return 0;
}
