#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Structure for a node in the hash table
struct Node
{
    char key[50];
    int value;
    struct Node *next;
};
// Structure for the hash table
struct HashTable
{
    struct Node *table[SIZE];
};

// Function to initialize the hash table
void initializeHashTable(struct HashTable *ht)
{
    for (int i = 0; i < SIZE; i++)
    {
        ht->table[i] = NULL;
    }
}

// Function to calculate the hash value for a key
int hash(char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    return sum % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable *ht, char *key, int value)
{
    int index = hash(key);

    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    // Insert the new node into the hash table
    if (ht->table[index] == NULL)
    {
        ht->table[index] = newNode;
    }
    else
    {
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }

    printf("Key '%s' with value %d inserted into the hash table.\n", key, value);
}
// Function to search for a key in the hash table and return its value
int search(struct HashTable *ht, char *key)
{
    int index = hash(key);

    // Search for the key in the linked list at the calculated index
    struct Node *current = ht->table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Return -1 if the key is not found
}

// Function to delete a key from the hash table
void deleteKey(struct HashTable *ht, char *key)
{
    int index = hash(key);

    // Search for the key in the linked list at the calculated index
    struct Node *current = ht->table[index];
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            // Remove the node from the linked list
            if (prev == NULL)
            {
                ht->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            printf("Key '%s' deleted from the hash table.\n", key);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Key '%s' not found in the hash table.\n", key);
}
// Function to display the hash table
void displayHashTable(struct HashTable *ht)
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        struct Node *current = ht->table[i];
        while (current != NULL)
        {
            printf("(%s, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    struct HashTable ht;
    initializeHashTable(&ht);

    int choice, value;
    char key[50];

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key: ");
            scanf("%s", key);
            printf("Enter the value: ");
            scanf("%d", &value);
            insert(&ht, key, value);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%s", key);
            value = search(&ht, key);
            if (value != -1)
            {
                printf("Value for key '%s': %d\n", key, value);
            }
            else
            {
                printf("Key '%s' not found in the hash table.\n", key);
            }
            break;
        case 3:
            printf("Enter the key to delete: ");
            scanf("%s", key);
            deleteKey(&ht, key);
            break;
        case 4:
            displayHashTable(&ht);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            continue;
        }

    } while (choice != 5);

    return 0;
}

// Output
// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 1
// Enter the key: apple
// Enter the value: 10
// Key 'apple' with value 10 inserted into the hash table.


// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 1
// Enter the key: banana
// Enter the value: 20
// Key 'banana' with value 20 inserted into the hash table.


// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 1
// Enter the key: mango
// Enter the value: 30
// Key 'mango' with value 30 inserted into the hash table.

// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 4


// Hash Table:
// 0:
// 1:
// 2:
// 3:
// 4: (banana, 20)
// 5: (apple, 10)
// 6:
// 7:
// 8: (mango, 30)
// 9:

// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 2
// Enter the key to search: apple

// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 3
// Enter the key to delete: banana

// Menu:
// 1. Insert
// 2. Search
// 3. Delete
// 4. Display Hash Table
// 5. Exit
// Enter your choice: 5
// Exiting the program.
