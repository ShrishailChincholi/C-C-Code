#include <stdio.h>

int main() {
    unsigned int x = 1;
    char *c = (char*)&x;

    if (*c)
        printf("Little Endian");
    else
        printf("Big Endian");

    return 0;
}

// Output

// Little Endian

// Stack operation
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;


int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}


int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}


void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}


void peek() {
    if (isEmpty()) {
        printf("Stack is empty. No top element\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n------ STACK MENU ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again\n");
        }
    }

    return 0;
}
🧪 Sample Input / Output (Example Run)
------ STACK MENU ------
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed into stack

Enter your choice: 1
Enter value to push: 20
20 pushed into stack

Enter your choice: 4
Stack elements are:
20
10

Enter your choice: 3
Top element is: 20

Enter your choice: 2
20 popped from stack
🧠 Key Points for Exams

Stack follows LIFO (Last In First Out)

push() → insert element

pop() → remove top element

peek() → view top element

Overflow when stack is full

Underflow when stack is empty

If you want next:

🔁 Stack using Linked List

🧮 Infix to Postfix using Stack

🧠 Reverse string using Stack

📚 Theory + diagram explanation

Just say the word 😄

not push and pop take another exmple

Ahh okay 👍 — no push & pop.
Let’s take a different stack application example that still uses the stack concept, and make it a big, exam-friendly C program.

📚 STACK APPLICATION
🔄 Reversing a String Using Stack (Without Push/Pop Functions)

👉 Here, the stack is used internally to reverse a string.
👉 No separate push() / pop() functions.
👉 Logic is written directly in main.

✅ C Program: Reverse a String Using Stack
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX], stack[MAX];
    int top = -1;
    int i;

    printf("Enter a string: ");
    gets(str);   // for simplicity (commonly used in exams)

    /* Pushing characters into stack */
    for (i = 0; str[i] != '\0'; i++) {
        top++;
        stack[top] = str[i];
    }

    /* Popping characters from stack to reverse */
    for (i = 0; i <= top; i++) {
        str[i] = stack[top];
        top--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
🧪 Sample Output
Enter a string: STACK
Reversed string: KCATS
🧠 Stack Logic Used Here

Characters are stored one by one in stack

Stack follows LIFO

Last character comes out first → string gets reversed

📌 Another Stack Example (Conceptual – Exam Line)

Undo/Redo in text editors, Function calls, Expression evaluation, Parenthesis checking all use stacks.

🔥 Want one more big stack example (still no push/pop)?

✅ Checking balanced parentheses

✅ Decimal to Binary conversion

✅ Palindrome check using stack

✅ Expression evaluation

Tell me which one you want next 👌

give more complicate code 

Alright 😄 let’s level this up.
Here’s a more complicated, exam-level STACK program that uses real logic, multiple conditions, loops, and error checking — still NO push() / pop() functions.

🔐 STACK APPLICATION (COMPLEX)
✅ Checking Balanced Parentheses Using Stack

👉 This is a classic & important problem
👉 Uses stack logic inside the program
👉 Handles (), {}, []
👉 Good for DS exams + interviews

🧠 Problem Statement

Check whether an expression has balanced parentheses.

Examples

{(a+b)*c} → ✅ Balanced

{(a+b]*c} → ❌ Not Balanced

✅ C Program (Complicated Stack Logic)
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char exp[MAX];
    char stack[MAX];
    int top = -1;
    int i;
    int flag = 1;

    printf("Enter an expression: ");
    gets(exp);   // used for exam simplicity

    for (i = 0; exp[i] != '\0'; i++) {

        /* If opening bracket, store in stack */
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top++;
            stack[top] = exp[i];
        }

        /* If closing bracket, check stack */
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (top == -1) {
                flag = 0;   // no matching opening bracket
                break;
            }

            /* Matching conditions */
            if ((exp[i] == ')' && stack[top] == '(') ||
                (exp[i] == '}' && stack[top] == '{') ||
                (exp[i] == ']' && stack[top] == '[')) {
                top--;  // remove matched opening bracket
            } else {
                flag = 0;
                break;
            }
        }
    }

    /* Final stack check */
    if (top != -1)
        flag = 0;

    if (flag == 1)
        printf("Expression is BALANCED\n");
    else
        printf("Expression is NOT BALANCED\n");

    return 0;
}

// Output
// ------ STACK MENU ------
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice: 1
// Enter value to push: 10
// 10 pushed into stack

// Enter your choice: 1
// Enter value to push: 20
// 20 pushed into stack

// Enter your choice: 4
// Stack elements are:
// 20
// 10

// Enter your choice: 3
// Top element is: 20

// Enter your choice: 2
// 20 popped from stack


#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int marks;
};

void input(struct Student s[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%d", &s[i].marks);
    }
}

void display(struct Student s[], int n) {
    printf("\nID\tName\tMarks\n");
    printf("--------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", s[i].id, s[i].name, s[i].marks);
    }
}

void findTopper(struct Student s[], int n) {
    int max = s[0].marks;
    int index = 0;

    for(int i = 1; i < n; i++) {
        if(s[i].marks > max) {
            max = s[i].marks;
            index = i;
        }
    }

    printf("\nTopper: %s with %d marks\n", s[index].name, max);
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    input(s, n);
    display(s, n);
    findTopper(s, n);

    return 0;
}


#include <stdio.h>

#define N 8

int board[N];  

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        
        if (board[i] == col || abs(board[i] - col) == row - i)
            return 0;
    }
    return 1;
}


void solve(int row) {
    if (row == N) {
        // print solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;   // place queen
            solve(row + 1);     // move to next row
        }
    }
}

int main() {
    solve(0);
    return 0;
}

// Output
//  .  Q  .  .  .  .  .  .
//  .  .  .  .  Q  .  .  .
//  Q  .  .  .  .  .  .  .
//  .  .  .  .  .  .  Q  .
//  .  .  Q  .  .  .  .  .
//  .  .  .  .  .  Q  .  .
//  .  .  .  Q  .  .  .  .
//  .  .  .  .  .  .  .  Q





#include <stdio.h>
#include <stdlib.h>

#define N 4

int board[N];

// Check if queen can be placed safely
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == row - i)
            return 0;
    }
    return 1;
}

// Solve using backtracking
void solve(int row) {
    if (row == N) {
       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    solve(0);
    return 0;
}


// Output
//  .  Q  .  .
//  .  .  .  Q
//  Q  .  .  .
//  .  .  Q  .



#include <stdio.h>
#include <string.h>

struct LengthFreq {
    int length;
    int count;
};

// Function to sort by length
void sort(struct LengthFreq arr[], int size) {
    struct LengthFreq temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].length > arr[j].length) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char str[1000];
    char *word;
    struct LengthFreq freq[100];
    int size = 0, found;

    fgets(str, sizeof(str), stdin);

    word = strtok(str, " \n");

    while (word != NULL) {
        int len = strlen(word);
        found = 0;

        for (int i = 0; i < size; i++) {
            if (freq[i].length == len) {
                freq[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            freq[size].length = len;
            freq[size].count = 1;
            size++;
        }

        word = strtok(NULL, " \n");
    }

    sort(freq, size);

    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d:%d", freq[i].length, freq[i].count);
        if (i < size - 1)
            printf(", ");
    }
    printf("}");

    return 0;
}



#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function to sort students by marks
void sortStudents(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].marks < s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}



void searchStudent(struct Student s[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nStudent not found\n");
}

int main() {
    int n, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter Roll, Name, Marks: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    sortStudents(s, n);

    printf("\nSorted Student Records (High to Low Marks):\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }

    printf("\nEnter roll number to search: ");
    scanf("%d", &key);

    searchStudent(s, n, key);

    return 0;
}




#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to find highest salary
void highestSalary(struct Employee e[], int n) {
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (e[i].salary > e[maxIndex].salary) {
            maxIndex = i;
        }
    }

    printf("\nHighest Salary Employee:\n");
    printf("ID: %d\nName: %s\nSalary: %.2f\n",
           e[maxIndex].id, e[maxIndex].name, e[maxIndex].salary);
}

// Function to increase salary by percentage
void increaseSalary(struct Employee e[], int n, float percent) {
    for (int i = 0; i < n; i++) {
        e[i].salary += (e[i].salary * percent / 100);
    }
}

int main() {
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee e[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter ID, Name, Salary: ");
        scanf("%d %s %f", &e[i].id, e[i].name, &e[i].salary);
    }

    increaseSalary(e, n, 10); // increase by 10%

    printf("\nUpdated Employee Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", e[i].id, e[i].name, e[i].salary);
    }

    highestSalary(e, n);

    return 0;
}

