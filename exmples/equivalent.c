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






#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int i, j, found, count = 0;

    scanf("%s %s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Check characters of s1 not in s2
    for (i = 0; i < len1; i++) {
        found = 0;
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) count++;
    }


    for (i = 0; i < len2; i++) {
        found = 0;
        for (j = 0; j < len1; j++) {
            if (s2[i] == s1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) count++;
    }

    printf("%d", count);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int i;

    int freq1[26] = {0};
    int freq2[26] = {0};

    scanf("%s %s", s1, s2);


    for (i = 0; s1[i] != '\0'; i++) {
        freq1[s1[i] - 'a']++;
    }


    for (i = 0; s2[i] != '\0'; i++) {
        freq2[s2[i] - 'a']++;
    }

 
    for (i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            printf("Not Anagram");
            return 0;
        }
    }

    printf("Anagram");

    return 0;
}



#include <stdio.h>

int main() {
    int num, original, remainder;
    int result = 0;

    scanf("%d", &num);

    original = num;

    while (num != 0) {
        remainder = num % 10;
        result += remainder * remainder * remainder;
        num /= 10;
    }

    if (result == original)
        printf("Armstrong Number");
    else
        printf("Not Armstrong");

    return 0;
}




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
                c += 2;
                string2[j] = '*';  
                break;
            }
        }
    }

    printf("%d", t - c);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int i, j, count = 0;

    scanf("%s", s1);
    scanf("%s", s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                count++;
                s2[j] = '*';  // mark used
                break;
            }
        }
    }

    printf("%d", count);

    return 0;
}



#include <stdio.h>

int main() {
    int n, k;
    int resultg = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 2; i <= n; i++) {
        resultg = (resultg + k) % i;
    }

    printf("%d", resultg + 1);

    return 0;
}


#include <stdio.h>

int main() {
    int n, step;
    int pos = 0;

    scanf("%d", &n);
    scanf("%d", &step);

    for (int i = 1; i <= n; i++) {
        pos = (pos + step) % n;
    }

    printf("%d", pos);

    return 0;
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int result = 0;
    int step = 1;

    for (int i = 2; i <= n; i++) {
        result = (result + step) % i;
        step++;  // step increases each round
    }

    printf("%d", result + 1);

    return 0;
}



#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[100], res[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        res[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);

    return 0;
}



#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], temp[200];

    scanf("%s %s", s1, s2);

    if (strlen(s1) != strlen(s2)) {
        printf("Not Rotation");
        return 0;
    }

    strcpy(temp, s1);
    strcat(temp, s1);  

    if (strstr(temp, s2))
        printf("Rotation");
    else
        printf("Not Rotation");

    return 0;
}





#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int pos = 0;

    for (int i = 1; i <= n; i++) {
        pos = (pos + k) % n;
    }

    printf("Final Position: %d", pos + 1);

    return 0;
}


#include <stdio.h>

int main() {
    int r, c, k;
    scanf("%d %d", &r, &c);

    int mat[50][50], res[50][50];

    // Input matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    scanf("%d", &k);

    // Rotate each row
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][(j + k) % c] = mat[i][j];
        }
    }


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

int main() {
    int r, c, steps;
    scanf("%d %d", &r, &c);

    int mat[50][50];

  
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    scanf("%d", &steps);

    int i = 0, j = 0; 

    printf("%d ", mat[i][j]);

   
    for (int s = 0; s < steps; s++) {
        i = (i + 1) % r;
        j = (j + 1) % c;
        printf("%d ", mat[i][j]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char input[1000];
    int arr[500], n = 0;

    
    fgets(input, sizeof(input), stdin);

    
    char *ptr = input;
    while (*ptr) {
        if ((*ptr >= '0' && *ptr <= '9') || *ptr == '-') {
            arr[n++] = strtol(ptr, &ptr, 10);
        } else {
            ptr++;
        }
    }

    if (n == 0) {
        printf("0");
        return 0;
    }


    
    qsort(arr, n, sizeof(int), compare);

    int longest = 1, current = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            continue; 
        } else if (arr[i] == arr[i - 1] + 1) {
            current++;
        } else {
            if (current > longest)
                longest = current;
            current = 1;
        }
    }

    
    if (current > longest)
        longest = current;

    printf("%d\n", longest);

    return 0;
  
}


#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {1, 2, 0, 1};  
    int n = 4;

    qsort(arr, n, sizeof(int), compare);

    int longest = 1, current = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            continue; 
        } 
        else if (arr[i] == arr[i - 1] + 1) {
            current++;
        } 
        else {
            if (current > longest)
                longest = current;
            current = 1;
        }
    }

    if (current > longest)
        longest = current;

    printf("%d\n", longest);

    return 0;
}






#include <stdio.h>

int main() {
    int arr[] = {3, 7, 2, 1, 9, 8};
    int n = 6;

    int max = arr[0], min = arr[0];

  
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int size = max - min + 1;
    int present[size];

    for (int i = 0; i < size; i++) {
        present[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        present[arr[i] - min] = 1;
    }

    int longest = 0, current = 0;

    
    for (int i = 0; i < size; i++) {
        if (present[i] == 1) {
            current++;
            if (current > longest)
                longest = current;
        } else {
            current = 0;
        }
    }

    printf("%d\n", longest);

    return 0;
}


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  
    int count = 0;

    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size); 

        int arr[size];

        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }

       
        if (size <= 1) {
            count++;
            continue;
        }

        int diff = arr[1] - arr[0];
        int valid = 1;

        for (int j = 1; j < size; j++) {
            if (arr[j] <= arr[j - 1] || (arr[j] - arr[j - 1]) != diff) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}




#include <stdio.h>

int isValid(int arr[], int n) {
    if (n <= 1) return 1;

    int d = arr[1] - arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] <= arr[i-1] || arr[i] - arr[i-1] != d)
            return 0;

    return 1;
}

int main() {
    int n, size, count = 0;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &size);
        int arr[size];

        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);

        if (isValid(arr, size))
            count++;
    }

    printf("%d", count);
    return 0;
}