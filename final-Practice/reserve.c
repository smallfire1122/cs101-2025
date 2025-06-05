#include <stdio.h>

int reverse(int num) {
    if (num < 10) return num;
    int digits = 1, temp = num;
    while (temp /= 10) digits *= 10;
    return (num % 10) * digits + reverse(num / 10);
}

int main() {
    int num = 54321;
    printf("Reverse of %d = %d\n", num, reverse(num));
    return 0;
}
