#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_TreeNode(int data);
void insertTreeNode(TreeNode** root, int data);
void deleteTreeNode(TreeNode** root, int data);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
void bfs(TreeNode* root);
int treeDepth(TreeNode* root);
void freeTree(TreeNode* root);

#endif