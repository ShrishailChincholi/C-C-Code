// String Anagram Check

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int count[256] = {0};

    gets(s1);
    gets(s2);

    if (strlen(s1) != strlen(s2)) {
        printf("Not Anagram");
        return 0;
    }

    for (int i = 0; s1[i]; i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not Anagram");
            return 0;
        }
    }

    printf("Anagram");
    return 0;
}

// output
// hello
// world
// Not Anagram
