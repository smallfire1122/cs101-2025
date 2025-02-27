#include <stdio.h>

int main() {
    int i = 12345;  // 變數 i 代表輸入數字
    int first;
    int last = i % 10;  // 取得最後一位數

    while (i >= 10) {  // 迴圈取得第一位數
        i /= 10;
    }
    first = i;

    printf("first %d + last %d = %d\n", first, last, first + last);

    return 0;
}
