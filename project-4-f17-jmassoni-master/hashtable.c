// HashTable Implementation Starter Code
// CMS 230, 2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hashtable struct definitions and function prototypes
#include "hashtable.h"


//*** Hash a string to an integer ***//
// Input
//    char *s: the string to hash
// Output
//    The integer hash code
//
// Implements the basic hashing String hashing algorithm used by Java.
unsigned long int hash(char *s) {
    unsigned long int h = 0;

    int i;
    for (i = 0; i < strlen(s); i++) {
        h += h * 31 + (unsigned long int) s[i];
    }

    return h;
}


//*** Create a new hashtable_t ***//
// Input
//    tableSize: the number of buckets in the new table
// Output
//    A pointer to the new table
HashTable * hashtableInit(int tableSize) {

    // C is different from Java, but not that different
    // Almost always, create a pointer to the struct that we want to initialize
    // then allocate memory for that struct with malloc
    
    // Use pointers to interact with the underlying struct
    // Use -> the same way you'd use . in Java

    
    // Allocate memory for a new HashTable
    HashTable *h = malloc(sizeof(HashTable));

    // Allocate memory for an array of buckets and assign
    // them to the table's buckets field
    h->buckets = malloc(sizeof(HashNode *) * tableSize);

    // Set the new HashTable's size field
    h->size = tableSize;

    // Return the new HashTable
    return h;
    
}


//*** Insert a key-value pair into a table ***//
// Inputs
//    hashtable *h: the hashtable performing the insertion
//    char *key: the key string
//    char *value: the value string
// Output
//    Nothing
void hashtableInsert(HashTable *h, char *key, char *value) {
    int index = hash(key) % h->size;
    
    // Make a new node
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    
    // Insert that new node into the head of the list in the
    // specified bucket
    newNode->next = h->buckets[index];
    h->buckets[index] = newNode;
    
    // Insert into the head of the linked list given by
    // h->buckets[index]
}


//*** Lookup the value associated with a particular key ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find
// Output
//    The char *value associated with the key or NULL if no match exists
char * hashtableLookup(HashTable *h, char *key) {
    int index = hash(key) % h->size;
    

    
    
    // Lookup which bucket and then traverse the linked list
    HashNode *veryCool = h->buckets[index];
    while (veryCool != NULL){
        
        if(strcmp(veryCool->key, key) == 0){
            
            return veryCool->value;
            
        }
        
        veryCool = veryCool->next;
    }
    
    return NULL;
}


//*** Remove a key-value pair from the table if it exists ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find and remove
// Output
//    The char *value associated with the key or NULL if no match exists
//    The pair is removed if it exists in the table
char * hashtableRemove(HashTable *h, char *key) {
    int index = hash(key) % h->size;
    
    HashNode *good = h->buckets[index];
    HashNode *better = NULL;
    HashNode *best = NULL;
    while(good != NULL){
        
        if(strcmp(good->key, key) == 0){
            
            best = good;
            
            if(better == NULL){
                
                h->buckets[index] = h->buckets[index]->next;
                
            } else {
            
            better->next = good->next;
            
                
            }
            
            free(good);
            return best->value;
       
        }
        
        better = good;
        good = good->next;
        
    }
    // Will be like remove in a linked list
    
    return NULL;
}


//*** Print a hashtable ***//
// Input
//    hashtable_t *h: the table
void hashtablePrint(HashTable *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        HashNode *node = h->buckets[i];
        printf("Contents of bucket %d:\n", i);

        while (node != NULL) {
            printf("    <%s, %s>\n", node->key, node->value);
            node = node->next;
        }
    }
}

//*** There is no main function --- use the Python test script ***//
