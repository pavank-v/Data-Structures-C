#include <stdio.h>
#include "binary_tree.h"

int main(){
    TreeNode* root = NULL;

    insertTreeNode(&root, 12);
    insertTreeNode(&root, 19);
    insertTreeNode(&root, 2);
    insertTreeNode(&root, 17);
    insertTreeNode(&root, 10);
    insertTreeNode(&root, 872);
    insertTreeNode(&root, 212);
    insertTreeNode(&root, 122);

    deleteTreeNode(&root, 2);
    deleteTreeNode(&root, 17);

    printf("Inorder traversal -> ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal -> ");
    preorder(root);
    printf("\n");
    printf("postorder traversal -> ");
    postorder(root);
    printf("\n");
    printf("Breadth first search -> ");
    bfs(root);
    printf("The depth of the tree is: %d\n", treeDepth(root));
    freeTree(root);
    
    return 0;
}