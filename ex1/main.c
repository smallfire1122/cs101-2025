#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    
    fp = fopen("a.bin", "wb");
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);

    int a_r[3];
    char b_r[3];
    float c_r[3];

    fp = fopen("a.bin", "rb");
    fread(a_r, sizeof(int), 3, fp);
    fread(b_r, sizeof(char), 3, fp);
    fread(c_r, sizeof(float), 3, fp);
    fclose(fp);

    printf("%d %d %d\n", a_r[0], a_r[1], a_r[2]);
    printf("%c %c %c\n", b_r[0], b_r[1], b_r[2]);
    printf("%.6f %.6f %.6f\n", c_r[0], c_r[1], c_r[2]);

    return 0;
}
