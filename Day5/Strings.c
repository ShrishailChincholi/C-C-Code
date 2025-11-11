// Strings
#include <stdio.h>
int main()
{
    char var[] = "Shrishail";
    printf("%s", var);
    return 0;
}

//Output
// Shrishail

// Example2
#include<stdio.h>

char printString(char arr[]);


int main(){
    char fname[] = "Shrishail";
    char lname[] = "Chincholi";

    printString(fname);
    printString(lname);

}

char printString(char arr[]){
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    
}


// Output
// Shrishail
//Chincholi

// write progeam that input user name get the length of string
#include<stdio.h>

char StringL(char arr[]);


int main(){
    char fname[] = "Shrishail"; 
   printf("The length string is %d",StringL(fname));

}

char StringL(char arr[]){
    int count =0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
    
}

//Output
// The length string is 9

// find the salted form of password entered byuser if the salt is "123"&added at the end
#include<stdio.h>

void salt(char pas[]);
int main(){
    char pass[100];
    scanf("%s",pass);
    salt(pass);

}

void salt(char pas[]){
    char salt[]= "123";
    char newpass[200];

    strcpy (newpass,pas);
    strcat (newpass,salt);
    puts(newpass);

}

// Output 
//shrishail 
// shrishail123
