// Write a funcation named slice which takes a string & returns a sliced string from index n to m
#include<stdio.h>
void slice(char str[],int n, int m);

int main(){
    char str[] ="Helloworld";
    slice(str,3,6);
}

void slice(char str[],int n,int m){
    char newstr[100];
    int j = 0;
    for (int i = n; i <= m; i++,j++)
    {
        newstr[j] = str[i];
    }
    newstr[j] = '\0';
    puts(newstr);
}

//Output
// lowo

// write a funcation to count the occurrence of vowels in string
#include<stdio.h>
 int counvowels(char str[]);

 int main(){
    char str[] = "shrishailchincholi";
    printf("%d " ,counvowels(str));
 }

 int counvowels(char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
       if (str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='i'||str[i]=='u' )
       {
        count ++;
       }
       
    }
    return count;
    
 }

 // Output
// 6

// // check if a given character is present in a string or not
#include<stdio.h>
void checkchar(char str[],char ch);
int main(){
    char str[]= "shrishail";
    char ch = 'a';
    checkchar(str,ch);
}
void checkchar(char str[],char ch){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]==ch)
        {
            printf("Character is present ");
            return;
        }
        
    }
    printf("Character is not present ");
}

// // Output
// // Character is present 