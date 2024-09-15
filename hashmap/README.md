# HashMap Implementation in C

This project implements a dynamic HashMap (hash table) in C. The HashMap supports various data types for keys and values, and provides functionality to insert, search, and delete key-value pairs. It also dynamically resizes based on the load factor.

## Features

- **Dynamic Resizing**: Automatically resizes when the load factor exceeds or drops below the threshold.
- **Collision Handling**: Uses chaining to handle hash collisions.
- **Customizable Hash Function**: Accepts a user-defined hash function for flexible key support.
- **Customizable Compare Function**: Accepts a user-defined comparison function for keys.
- **Supports Different Key-Value Types**: Can handle different data types for keys and values by specifying their size.

## File Structure

- **hashmap.h**: Header file that defines the `HashMap` and `HashNode` structures and function prototypes.
- **hashmap.c**: Implementation of the hashmap operations (insert, search, delete, and dynamic resizing).
- **main.c**: Example file that demonstrates how to use the hashmap.

## How to Use

1. **Include the Header**: Include `hashmap.h` in your project to access the HashMap functions.

2. **Create a HashMap**: Call `create_hashmap()` to create a new hashmap with your custom hash and compare functions.

3. **Insert Elements**: Use `insert()` to insert key-value pairs into the hashmap.

4. **Search for Elements**: Use `search()` to find a value associated with a given key.

5. **Delete Elements**: Use `delete_map()` to remove a key-value pair from the hashmap.

6. **Free Memory**: When done, use `free_hashmap()` to release all memory associated with the hashmap.

## Example

```c
#include "hashmap.h"
#include <stdio.h>
#include <string.h>

int hash_function(void* key, int size) {
    char* str_key = (char*)key;
    int hash = 0;
    while (*str_key) {
        hash = (hash * 31 + *str_key) % size;
        str_key++;
    }
    return hash;
}

int compare_function(void* key1, void* key2) {
    return strcmp((char*)key1, (char*)key2);
}

int main() {
    HashMap* map = create_hashmap(sizeof(char*), sizeof(int), hash_function, compare_function, 10);

    char* key1 = "apple";
    int value1 = 5;
    insert(map, key1, &value1);

    char* key2 = "banana";
    int value2 = 7;
    insert(map, key2, &value2);

    int* search_result = (int*)search(map, key1);
    if (search_result) {
        printf("Value for key '%s': %d\n", key1, *search_result);
    } else {
        printf("Key '%s' not found\n", key1);
    }

    delete_map(map, key2);

    free_hashmap(map);
    return 0;
}
```