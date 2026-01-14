
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

struct TrieNode {
    struct TrieNode* children[ALPHABET];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, char* key) {
    struct TrieNode* temp = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = createNode();
        temp = temp->children[index];
    }
    temp->isEndOfWord = 1;
}

int search(struct TrieNode* root, char* key) {
    struct TrieNode* temp = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!temp->children[index])
            return 0;
        temp = temp->children[index];
    }
    return temp->isEndOfWord;
}

int main() {
    struct TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "hi");
    insert(root, "help");

    printf("Search hello: %d\n", search(root, "hello"));
    printf("Search hey: %d\n", search(root, "hey"));

    return 0;
}

// OUTPUT
// Search hello: 1
// Search hey: 0
