#include <stdio.h>

int main() {
    char v = 'A';
    char* p = &v;
    printf("Address of v: %p\n", (void*)&v);
    printf("Address stored in p: %p\n", (void*)p);
    printf("Address of p: %p\n", (void*)&p);
    printf("Value of *p: %c\n", *p);

    return 0;
}
