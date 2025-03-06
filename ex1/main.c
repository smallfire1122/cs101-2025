
#include <stdio.h>

int main() {
    FILE* fp;

    
    int a[] = {0, 1, 2};
    char b[] = "ABC"; 
    float c[] = {1.1, 1.2, 1.3};

    
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        perror("無法開啟 a.bin 進行寫入");
        return 1;
    }
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp); 
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);

   
    int a_read[3] = {0};
    char b_read[3] = {0};
    float c_read[3] = {0.0};

    
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        perror("無法開啟 a.bin 進行讀取");
        return 1;
    }
    fread(a_read, sizeof(int), 3, fp);
    fread(b_read, sizeof(char), 3, fp);
    fread(c_read, sizeof(float), 3, fp);
    fclose(fp);

    
    printf("整數陣列: %d %d %d\n", a_read[0], a_read[1], a_read[2]);
    printf("字元陣列: %c %c %c\n", b_read[0], b_read[1], b_read[2]);
    printf("浮點數陣列: %.6f %.6f %.6f\n", c_read[0], c_read[1], c_read[2]);

    return 0;
}
