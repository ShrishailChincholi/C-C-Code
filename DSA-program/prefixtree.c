
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