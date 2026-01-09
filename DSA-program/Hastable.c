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
// Structure for the hash table 
struct HashTable { 
    struct Node* table[SIZE]; 
}; 
 
// Function to initialize the hash table 
void initializeHashTable(struct HashTable* ht) { 
    for (int i = 0; i < SIZE; i++) { 
        ht->table[i] = NULL; 
    } 
} 
 
// Function to calculate the hash value for a key 
int hash(char* key) { 
    int sum = 0; 
    for (int i = 0; key[i] != '\0'; i++) { 
        sum += key[i]; 
    } 
    return sum % SIZE; 
} 
 
// Function to insert a key-value pair into the hash table 
void insert(struct HashTable* ht, char* key, int value) { 
    int index = hash(key); 
 
    // Create a new node 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    strcpy(newNode->key, key); 
    newNode->value = value; 
    newNode->next = NULL; 
 
    // Insert the new node into the hash table
        if (ht->table[index] == NULL) { 
        ht->table[index] = newNode; 
    } else { 
        newNode->next = ht->table[index]; 
        ht->table[index] = newNode; 
    } 
 
    printf("Key '%s' with value %d inserted into the hash table.\n", key, value); 
} 