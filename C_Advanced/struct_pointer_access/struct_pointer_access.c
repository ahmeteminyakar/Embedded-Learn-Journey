#include <stdio.h>

struct Sensor {
    char id;
    int value;
    char status;
};

void printSensor(struct Sensor *s) {
    printf("Sensor ID    : %c\n", s->id);
    printf("Sensor Value : %d\n", s->value);
    printf("Sensor Status: %c\n", s->status);
}

int main() {
    struct Sensor tempSensor = {'T', 874, 'O'};

    struct Sensor *ptr = &tempSensor;

    // Access using pointer
    printSensor(ptr);

    // Modify using pointer
    ptr->value = 999;
    ptr->status = 'X';

    printf("\nAfter Modification:\n");
    printSensor(ptr);

    return 0;
}
