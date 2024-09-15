# Binary Tree Implementation in C

This implementation provides various operations for managing a binary tree, including insertion, deletion, and traversal.

## Features

- **Dynamic Queue Allocation**: Uses a dynamic array for queue operations in level-order traversal.
- **Basic Operations**: Includes insertion, deletion, and traversal methods.
- **Memory Management**: Handles memory allocation and deallocation.

## File Structure

- **binary_tree.h**: Header file defining the structure of the binary tree and function prototypes.
- **binary_tree.c**: Implementation of binary tree operations (insert, delete, traverse, etc.).
- **main.c**: Example file demonstrating how to use the binary tree functions.

## How to Use

1. **Include the Header**: Include `binary_tree.h` in your project to access the binary tree functions.

2. **Create a Tree Node**: Use `create_TreeNode()` to create a new node with a specified key.

3. **Insert Nodes**: Use `insertTreeNode()` to add nodes to the tree.

4. **Delete Nodes**: Use `deleteTreeNode()` to remove nodes from the tree.

5. **Traverse the Tree**: Use `inorder()`, `preorder()`, `postorder()`, and `bfs()` for different types of tree traversal.

6. **Calculate Depth**: Use `treeDepth()` to compute the depth of the tree.

7. **Free Tree**: Use `freeTree()` to release all allocated memory.

## Example

```c
#include "binary_tree.h"
#include <stdio.h>

int main() {
    TreeNode* root = NULL;
    
    insertTreeNode(&root, 10);
    insertTreeNode(&root, 20);
    insertTreeNode(&root, 30);
    insertTreeNode(&root, 40);
    insertTreeNode(&root, 50);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    printf("BFS traversal: ");
    bfs(root);
    
    printf("Tree depth: %d\n", treeDepth(root));
    
    deleteTreeNode(&root, 30);
    
    printf("After deletion, inorder traversal: ");
    inorder(root);
    printf("\n");
    
    freeTree(root);
    return 0;
}
```


## Compilation
```bash
    gcc main.c binary_tree.c -o binary_tree_program
````