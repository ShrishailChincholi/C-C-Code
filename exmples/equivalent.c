#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];
    int i, j, c = 0;

    scanf("%s", string1);
    scanf("%s", string2);

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    int t = len1 + len2;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (string1[i] == string2[j]) {
                c = c + 2;
                string2[j] = '*';
                break;
            }
        }
    }

    printf("%d", t - c);

    return 0;
}

// Output
// Input:
// abcd
// bcdf

// Output:
// 2




#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int i, j, c = 0;

    scanf("%s %s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int t = len1 + len2;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                c += 2;
                s2[j] = '*';
                break;
            }
        }
    }

    printf("%d", t - c);

    return 0;
}