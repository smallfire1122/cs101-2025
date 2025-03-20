#include <stdio.h>

int main() {
    int num = 2;
    int* ip = &num;
    printf("%x\n", *ip);
    return 0;
}
