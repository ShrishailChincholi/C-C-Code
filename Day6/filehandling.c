#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    /* Writing to a file */
    fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        printf("File not created\n");
        return 1;
    }

    fprintf(fp, "Hello, this is File Handling in C.");
    fclose(fp);

    /* Reading from a file */
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File not opened\n");
        return 1;
    }

    printf("File content:\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
    return 0;
}
