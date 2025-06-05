#include <stdio.h>

int rec_Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return rec_Fibonacci(n - 1) + rec_Fibonacci(n - 2);
}

int main() {
    int n = 10;
    int sum = rec_Fibonacci(n);
    printf("Fibonacci(%d) = %d", n, sum);
    return 0;
}
