#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define SIZE 10 
 
// Structure for a node in the hash table 
struct Node { 
    char key[50]; 
    int value; 
    struct Node* next; 
};