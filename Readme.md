# Data Structures Library in C

Welcome to the Data Structures Library in C! This repository contains implementations of various data structures and algorithms in C, including linked lists, queues, stacks, binary trees, heaps, and more.

## Features

- **Linked List**: Single Linked List, Doubly Linked List
- **Queue**: Circular Queue
- **Stack**: Basic Stack operations
- **Binary Tree**: Basic Binary Tree operations including insertion, deletion, traversal
- **Heap**: Min-Heap

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation

To get started with this repository, you'll need to have a C compiler installed on your system. You can compile the programs using `gcc` or any other C compiler.

### Example

1. Clone the repository:

    ```bash
    git clone https://github.com/pavank1301/MyLibrary.git
    ```

2. Navigate to the directory:

    ```bash
    cd repository-name
    ```

3. Compile the code:

    ```bash
    gcc main.c binary_tree.c linked_list.c queue.c stack.c heap.c -o data_structures
    ```

4. Run the program:

    ```bash
    ./data_structures
    ```

## Usage

Each implementation is in its respective file:

- **Linked List**: `linked_list.c` and `linked_list.h`
- **Queue**: `queue.c` and `queue.h`
- **Stack**: `stack.c` and `stack.h`
- **Binary Tree**: `binary_tree.c` and `binary_tree.h`
- **Heap**: `heap.c` and `heap.h`

Refer to the specific implementation files for details on the functions and their usage.

### Example Usage for Binary Tree

```c
#include "binary_tree.h"
#include <stdio.h>

int main() {
    TreeNode* root = NULL;
    
    insertTreeNode(&root, 10);
    insertTreeNode(&root, 20);
    insertTreeNode(&root, 30);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
```

## Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please submit a pull request. For significant changes, open an issue first to discuss.

### Steps to Contribute

- Fork the repository
- Create a new branch (git checkout -b feature-branch)
- Make your changes
- Commit your changes (git commit -am 'Add new feature')
- Push to the branch (git push origin feature-branch)
- Create a new Pull Request