#include <stdio.h>

int main() {
    int i = 12345;  
    int first;
    int last = i % 10; 

    while (i >= 10) {
        i /= 10;
    }
    first = i;

    printf("first %d + last %d = %d\n", first, last, first + last);

    return 0;
}
