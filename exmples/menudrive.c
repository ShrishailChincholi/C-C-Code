#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define SIZE 10 
 

struct Node { 
    char key[50]; 
    int value; 
    struct Node* next; 
}; 
 
struct HashTable { 
    struct Node* table[SIZE]; 
}; 
 
void initializeHashTable(struct HashTable* ht) { 
    for (int i = 0; i < SIZE; i++) { 
        ht->table[i] = NULL; 
    } 
} 