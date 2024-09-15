// hashmap.c
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashNode* create_node(void* key, void* value, size_t key_size, size_t value_size) {
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = malloc(key_size);
    new_node->value = malloc(value_size);
    memcpy(new_node->key, key, key_size);
    memcpy(new_node->value, value, value_size);
    new_node->next = NULL;
    return new_node;
}

HashMap* create_hashmap(size_t key_size, size_t value_size,
                        int (*hash_function)(void* key, int size),
                        int (*compare_function)(void* key1, void* key2),
                        int initial_size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = initial_size;
    map->count = 0;
    map->key_size = key_size;
    map->value_size = value_size;
    map->hash_function = hash_function;
    map->compare_function = compare_function;
    map->buckets = (HashNode**)malloc(initial_size * sizeof(HashNode*));
    
    for (int i = 0; i < initial_size; i++) {
        map->buckets[i] = NULL;
    }
    
    return map;
}

// Resize hashmap based on current load factor
void resize_hashmap(HashMap* map) {
    int new_size;
    if ((float)map->count / map->size > LOAD_FACTOR) {
        new_size = map->size * 2;  // Expand
    } else if ((float)map->count / map->size < SHRINK_FACTOR && map->size > INITIAL_SIZE) {
        new_size = map->size / 2;  // Shrink
    } else {
        return;
    }
    
    HashNode** new_buckets = (HashNode**)malloc(new_size * sizeof(HashNode*));
    for (int i = 0; i < new_size; i++) {
        new_buckets[i] = NULL;
    }

    for (int i = 0; i < map->size; i++) {
        HashNode* node = map->buckets[i];
        while (node) {
            int new_index = map->hash_function(node->key, new_size);
            HashNode* next_node = node->next;
            node->next = new_buckets[new_index];
            new_buckets[new_index] = node;
            node = next_node;
        }
    }

    free(map->buckets);
    map->buckets = new_buckets;
    map->size = new_size;
}

void insert(HashMap* map, void* key, void* value) {
    if ((float)map->count / map->size > LOAD_FACTOR) {
        resize_hashmap(map);
    }

    int index = map->hash_function(key, map->size);
    HashNode* head = map->buckets[index];

    HashNode* temp = head;
    while (temp) {
        if (map->compare_function(temp->key, key) == 0) {
            memcpy(temp->value, value, map->value_size);
            return;
        }
        temp = temp->next;
    }

    HashNode* new_node = create_node(key, value, map->key_size, map->value_size);
    new_node->next = head;
    map->buckets[index] = new_node;
    map->count++;
}

void* search(HashMap* map, void* key) {
    int index = map->hash_function(key, map->size);
    HashNode* temp = map->buckets[index];

    while (temp) {
        if (map->compare_function(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

void delete_map(HashMap* map, void* key) {
    int index = map->hash_function(key, map->size);
    HashNode* temp = map->buckets[index];
    HashNode* prev = NULL;

    while (temp) {
        if (map->compare_function(temp->key, key) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                map->buckets[index] = temp->next;
            }
            free(temp->key);
            free(temp->value);
            free(temp);
            map->count--;
            
            // Resize after deletion
            if ((float)map->count / map->size < SHRINK_FACTOR && map->size > INITIAL_SIZE) {
                resize_hashmap(map);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void free_hashmap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        HashNode* temp = map->buckets[i];
        while (temp) {
            HashNode* to_free = temp;
            temp = temp->next;
            free(to_free->key);
            free(to_free->value);
            free(to_free);
        }
    }
    free(map->buckets);
    free(map);
}
