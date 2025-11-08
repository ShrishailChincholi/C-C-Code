// Day 2 of Learning C programm
// Ternary Exmaple

// #include<stdio.h>               
// int main(){
//     int age ;
//     printf("Enter your age : \n");
//     scanf("%d",&age);
//     age>18?printf("Adult\n:"):printf("Not Adult\n");//Ternary Opreator
//     return 0;
// };
// OutPut 
// Enter your age : 
// 16
// Not Adult


// Switch Case Example
// #include<stdio.h>
// int main(){
//     int Id;
//     printf("Enter your Id 1-5:\n");
//     scanf("%d",&Id);
//     switch (Id)
//     {
//         case 1 : printf("Shrishail  ");
//         break;
//         case 2 : printf("Raju  ");
//         break;
//         case 3 : printf("Shanshank  ");
//         break;
//         case 4 : printf("Vishal  ");
//         break;
//         case 5 : printf("Vinod  ");
//         break;

//         default : printf("Invalid Id Plzz try agian.........");
//     }

//     return 0;
// }

// Output
// Enter your Id:
// 4
// Vishal  

// Example WCP to give Grades to a Student
// #include<stdio.h>
// int main(){
//     int Mark;
//     printf("Enter Your Marks 30 to 100 \n");
//     scanf("%d",&Mark);
//     if(Mark<=30){
//         printf("Your Grade is C \n");
//         printf("  Fail.... \n");
//     } else if (Mark>30 && Mark<=70)
//     {
//         printf("Your Grade is B \n");
//         printf(" Not Bad Give More your best \n");
//     }else if (Mark>70 && Mark<=90)
//     {
//        printf("Your Grade is A \n");
//        printf("Very Good:-)");
//     }else if (Mark>90 && Mark<=100)
//     {
//         printf("Your Grade is A+ \n");
//         printf("Excellent well Done ");
//     }
    
//     return 0;
// }

// OutPut
// Enter Your Marks 30 to 100 
// 30
// Your Grade is C 
//   Fail.... 

// WPP the Enter Charcter is upper case or lower case Letter
// #include<stdio.h>
// int main() {
//     char ch;
//     printf("Enter Letter :- \n ");
//     scanf("%c",&ch);
//     if(ch >= 'A' && ch<='Z'){
//         printf("%c is Upper Case Letter",ch);
//     }else if (ch >= 'a' && ch <= 'z' )
//     {
//          printf("%c is Lower Case Letter",ch);
//     } else{
//         printf("Not A English Letter");
//     }
    
//     return 0;
// }

// OutPut 
// Enter Letter :- 
//  M
// M is Upper Case Letter

