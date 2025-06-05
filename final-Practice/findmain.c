#include <stdio.h>
#include <string.h>

int main() {
    FILE* txt = fopen("Q6.c", "r");
    char buffer[100];
    int line = 1;
    while (fgets(buffer, 100, txt)) {
        if (strstr(buffer, "int main") != NULL) {
            printf("%02d %s", line, buffer);
            break;
        }
        line++;
    }
    fclose(txt);
    return 0;
}
