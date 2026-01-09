// Longest Palindromic Substring
#include <stdio.h>
#include <string.h>

int expands(char *s, int l, int r){
    while(l>=0 && r<strlen(s) && s[l]==s[r]){
        l--; r++;
    }
    return r-l-1;
}

int main(){
    char str[]="babad";
    int start=0, end=0;

    for(int i=0;i<strlen(str);i++){
        int len1=expands(str,i,i);
        int len2=expands(str,i,i+1);
        int len=len1>len2?len1:len2;
        if(len>end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }

    for(int i=start;i<=end;i++)
        printf("%c",str[i]);

    return 0;
}

// Output
// bab
