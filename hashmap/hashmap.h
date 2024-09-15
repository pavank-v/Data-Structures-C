// hashmap.h
#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

#define INITIAL_SIZE 10       // Initial size of the hashmap
#define LOAD_FACTOR 0.75      // Load factor to trigger resizing
#define SHRINK_FACTOR 0.25    // Shrink factor to reduce size when the map is sparse

typedef struct HashNode {
    void* key;                
    void* value;              
    struct HashNode* next;    
} HashNode;

typedef struct HashMap {
    HashNode** buckets;       
    int size;                 
    int count;                
    size_t key_size;          
    size_t value_size;        
    int (*hash_function)(void* key, int size);   
    int (*compare_function)(void* key1, void* key2); 
} HashMap;

HashMap* create_hashmap(size_t key_size, size_t value_size,
                        int (*hash_function)(void* key, int size),
                        int (*compare_function)(void* key1, void* key2),
                        int initial_size);
void insert(HashMap* map, void* key, void* value);
void* search(HashMap* map, void* key);
void delete_map(HashMap* map, void* key);
void resize_hashmap(HashMap* map);
void free_hashmap(HashMap* map);

#endif // HASHMAP_H
