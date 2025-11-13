// file open and close
#include<stdio.h>
int main(){
    FILE *fptr ;
    fptr = fopen("nods.txt","r");
    if (fptr == NULL)
    {
        printf("File  doesn't exits");
    }else{
        fclose(fptr);
    }

}
//Output
// //File  doesn't exits

// // reading file from a file

#include<stdio.h>
int main(){
    FILE *fptr ;
    int num;
    fptr = fopen("file.txt","r");
// reading file we use fscanf
    fscanf(fptr,"%d",&num);
    printf(" numbers=  %d",num);
    fclose(fptr);
}

// //output
// //  numbers=  123456

// // write to file
#include <stdio.h>
int main()
{
    FILE *fptr;
    int num;
    fptr = fopen("file.txt", "w");
    // Writing file we use fprintf
    fprintf(fptr, "%d", 7);
    fprintf(fptr, "%d", 8);
    fprintf(fptr, "%d", 9);
    fprintf(fptr, "%d", 10);
    fprintf(fptr, "%d", 45);
    fclose(fptr);
    fptr = fopen("file.txt", "r");
    fscanf(fptr, "%d", &num);
    printf(" numbers=  %d",num);
    
}

// // Output
// // 7891045


// // read and write a char
// // fgets(fptr) // reading file
// // fputc('A',fptr)// writeing a file

#include<stdio.h>
int main(){
    FILE *fptr ;
 
    fptr = fopen("file.txt","r");
    printf(" numbers=  %d", fgets(fptr));
    fclose(fptr);
}


// //// EOF (end of file)
#include<stdio.h>
int main(){
    char ch;
    FILE *fptr ;
    fptr = fopen("file.txt","r");
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c",ch);
        ch = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
    
}

// // // Output
// // //shrishial chincholi

