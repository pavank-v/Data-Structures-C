// main.c
#include <stdio.h>
#include "hashmap.h"

// Hash and compare functions for integer keys
int int_hash_function(void* key, int size) {
    int int_key = *(int*)key;
    return int_key % size;
}

int int_compare_function(void* key1, void* key2) {
    int int_key1 = *(int*)key1;
    int int_key2 = *(int*)key2;
    return int_key1 - int_key2;
}

int main() {
    HashMap* map = create_hashmap(sizeof(int), sizeof(int), int_hash_function, int_compare_function, INITIAL_SIZE);

    for (int i = 0; i < 10; i++) {
        int key = i, value = i * 10;
        insert(map, &key, &value);
    }

    for (int i = 0; i < 10; i++) {
        int key = i;
        int* result = (int*)search(map, &key);
        if (result) {
            printf("Key %d: Value %d\n", i, *result);
        } else {
            printf("Key %d not found\n", i);
        }
    }

    for (int i = 0; i < 3; i++) {
        int key = i;
        delete_map(map, &key);
    }
    
    for (int i = 0; i < 10; i++) {
        int key = i;
        int* result = (int*)search(map, &key);
        if (result) {
            printf("Key %d: Value %d\n", i, *result);
        } else {
            printf("Key %d not found\n", i);
        }
    }

    free_hashmap(map);
    return 0;
}
