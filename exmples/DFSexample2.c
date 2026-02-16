#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void dfs(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);   // Preorder DFS
    dfs(root->left);
    dfs(root->right);
}