#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Create a new tree node
TreeNode* create_TreeNode(int data) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    if (tmp == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    tmp->key = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// Insert a new node in the binary tree using level order traversal
void insertTreeNode(TreeNode** root, int data) {
    TreeNode* new_TreeNode = create_TreeNode(data);
    
    if (!new_TreeNode) {
        return;  // Memory allocation failed
    }
    if (*root == NULL) {
        *root = new_TreeNode;
        printf("%d is inserted\n", data);
        return;
    }

    // Dynamic allocation of queue
    TreeNode** que = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (que == NULL) {
        printf("Queue memory allocation failed!\n");
        return;
    }

    TreeNode* temp;
    int front = -1, rear = -1;

    que[++rear] = *root;
    while (front != rear) {
        temp = que[++front];
        if (temp->left == NULL) {
            temp->left = new_TreeNode;
            printf("%d is inserted\n", data);
            free(que);
            return;
        }
        else {
            que[++rear] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = new_TreeNode;
            printf("%d is inserted\n", data);
            free(que);
            return;
        }
        else {
            que[++rear] = temp->right;
        }
    }

    free(que);  // Free queue memory after use
}

// Find the deepest and rightmost node in the binary tree
TreeNode* deepestRightMostTreeNode(TreeNode* root) {
    TreeNode* temp;
    // Dynamic queue allocation
    TreeNode** que = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (que == NULL) {
        printf("Queue memory allocation failed!\n");
        return NULL;
    }
    
    int front = -1, rear = -1;
    que[++rear] = root;

    while (front != rear) {
        temp = que[++front];

        if (temp->left != NULL) {
            que[++rear] = temp->left;
        }
        if (temp->right != NULL) {
            que[++rear] = temp->right;
        }
    }

    free(que);  // Free queue memory
    return temp;
}

// Delete the deepest and rightmost node
void deleteDeepestRightMostTreeNode(TreeNode* root, TreeNode* keyTreeNode) {
    TreeNode* temp;
    // Dynamic queue allocation
    TreeNode** que = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (que == NULL) {
        printf("Queue memory allocation failed!\n");
        return;
    }

    int front = -1, rear = -1;
    que[++rear] = root;

    while (front != rear) {
        temp = que[++front];

        if (temp->right != NULL) {
            if (temp->right == keyTreeNode) {
                temp->right = NULL;
                free(keyTreeNode);
                free(que);
                return;
            } else {
                que[++rear] = temp->right;
            }
        }

        if (temp->left != NULL) {
            if (temp->left == keyTreeNode) {
                temp->left = NULL;
                free(keyTreeNode);
                free(que);
                return;
            } else {
                que[++rear] = temp->left;
            }
        }
    }

    free(que);  // Free queue memory
}

// Delete a node with the specified key
void deleteTreeNode(TreeNode** root, int data) {
    if (*root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if ((*root)->left == NULL && (*root)->right == NULL) {
        if ((*root)->key == data) {
            free(*root);
            *root = NULL;
            return;
        } else {
            printf("TreeNode not found\n");
            return;
        }
    }

    TreeNode* temp;
    TreeNode* keyTreeNode = NULL;

    // Dynamic queue allocation
    TreeNode** que = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (que == NULL) {
        printf("Queue memory allocation failed!\n");
        return;
    }
    
    int front = -1, rear = -1;
    que[++rear] = *root;

    while (front != rear) {
        temp = que[++front];
        
        if (temp->key == data) {
            keyTreeNode = temp;
            break;
        }
        if (temp->left != NULL) {
            que[++rear] = temp->left;
        }
        if (temp->right != NULL) {
            que[++rear] = temp->right;
        }
    }

    if (keyTreeNode == NULL) {
        printf("TreeNode not Found\n");
        free(que);
        return;
    } else {
        TreeNode* deepestTreeNode = deepestRightMostTreeNode(*root);
        keyTreeNode->key = deepestTreeNode->key;
        deleteDeepestRightMostTreeNode(*root, deepestTreeNode);
    }
    printf("%d deleted successfully\n", data);
    free(que);  // Free queue memory
}

// Inorder traversal of the tree
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Preorder traversal of the tree
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal of the tree
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Breadth-first search traversal of the tree
void bfs(TreeNode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    // Dynamic queue allocation
    TreeNode** que = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (que == NULL) {
        printf("Queue memory allocation failed!\n");
        return;
    }
    
    TreeNode* temp;
    int front = -1, rear = -1;
    que[++rear] = root;

    while (front != rear) {
        temp = que[++front];
        printf("%d ", temp->key);

        if (temp->left != NULL) {
            que[++rear] = temp->left;
        }
        if (temp->right != NULL) {
            que[++rear] = temp->right;
        }
    }

    printf("\n");
    free(que);  // Free queue memory
}

// Calculate the depth of the binary tree
int treeDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return MAX(treeDepth(root->left), treeDepth(root->right)) + 1;
}

// Free all nodes of the binary tree
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
