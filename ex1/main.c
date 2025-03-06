#include <stdio.h>

int main() {
    FILE *fp;

    
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入。\n");
        return 1;
    }
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);

   
    int ra[3];
    char rb[3];
    float rc[3];

    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取。\n");
        return 1;
    }
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);
    fclose(fp);

    
    printf("int 陣列內容: %d %d %d\n", ra[0], ra[1], ra[2]);
    printf("char 陣列內容: %c %c %c\n", rb[0], rb[1], rb[2]);
    printf("float 陣列內容: %.6f %.6f %.6f\n", rc[0], rc[1], rc[2]);

    return 0;
}
