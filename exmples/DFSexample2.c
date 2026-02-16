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

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("DFS Traversal: ");
    dfs(root);

    return 0;
}
