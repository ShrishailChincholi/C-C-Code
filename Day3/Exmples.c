// Useing A funcation when user enter a i print jai shree and f for Bonjur
// Ex1
#include<stdio.h>

void namsati();
void bonjur();

void namsati(){
    printf("jai shree ram......\n");
}

void bonjur(){
    printf("Bonjur Frinds\n");
}

int main(){
    char ch;
    printf("Enter I for Indian and F for Franch \n");
    scanf("%c",&ch);
    if (ch == 'i')
    {
        namsati();
    }else
    {
        bonjur();
    }
    return 0;
    
}

// Output
// Enter I for Indian and F for Franch 
// i
// jai shree ram......