#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("*p     = %d\n", *p);        // 10
    printf("*(p+2) = %d\n", *(p + 2));  // 30
    printf("p[3]   = %d\n", p[3]);      // 40

    p++;  // move pointer
    printf("*p after p++ = %d\n", *p);  // 20

    ++p;  // move again
    printf("*p after ++p = %d\n", *p);  // 30

    return 0;
}
