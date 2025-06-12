#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* new_node(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int count_node(TreeNode* node) {
    if (node == NULL) return 0;
    return count_node(node->left)
         + count_node(node->right)
         + 1;
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x) {
    
}

int main(void) {
    TreeNode* root = new_node(1);
    root->left        = new_node(2);
    root->right       = new_node(3);
    root->right->left  = new_node(4);
    root->right->right = new_node(5);

    printf("Total nodes: %d\n", count_node(root));

    printf("can? %d\n", (int)btreeGameWinningMove(root,count_node(root),2 ));
    return 0;
}