
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "kv_store.h"

/**
 * Purpose: deserialize a key-value pair buffer (the format is in the README
 * file).
 * 
 * Inputs:
 * - `char *buf`: pointer to the key-value pair buffer.
 * - `size_t buffer_size`: total size of the key-value pair buffer (in bytes).
 * 
 * Return: `KVPAIR *start_of_list`, which is a pointer to start of linked list
 * of `KVPAIR`s if successful. Otherwise, return NULL.
 * 
 * Assumptions: `buf` is not empty or NULL and the `buffer_size` is the correct
 * size of the buffer.
 *
 * Hints: 
 * - Although you could probably make this function recursive, our
 *   implementation just uses a `while` loop.
 * - You will probably have a pointer which will go through the buffer. You
 *   first should probably think about how long you should be iterating for.
 * - Once you have figured out the correct bounds for iteration, for each new
 *   key-value pair you see, you will probably want to allocate a new node in
 *   your list, and then populate all the fields in that node. This will
 *   probably involve calling `memcpy()` a couple of times, and also `malloc()`
 *   for the value.
 * - Once you're done populating an individual node of the linked list, you are
 *   to actually add it to the list. This can be done by appending the node to
 *   the tail of the list. Think about how to do this...
 */

KVPAIR *deserialize(char *buf, size_t buffer_size) {
    KVPAIR *head = NULL;
    KVPAIR *tail = NULL;
 
    char *pointer = buf;
 
    while (pointer - buf < buffer_size) {
        KVPAIR *new_pair = (KVPAIR *)malloc(sizeof(KVPAIR));
        long key1;
        memcpy(&key1, pointer, sizeof(long));
        pointer += sizeof(long);

        new_pair->key = key1;
 
        unsigned int val_size1;
        memcpy(&val_size1, pointer, sizeof(unsigned int));
        pointer += sizeof(unsigned int);

        new_pair->size = val_size1;
 
        char *value1 = (char *)malloc(val_size1 + 1);
        if (value1 == NULL) {
            return NULL;}

        memcpy(value1, pointer, val_size1);
        value1[val_size1] = '\0';
        pointer += val_size1;

        new_pair->val = value1;
 
        new_pair->next = NULL;
 
        if (tail == NULL) {
            head = new_pair;
            tail = new_pair;
        } else {
            tail->next = new_pair;
            tail = new_pair;
        }
    }
 
    return head;
}


/**
 * Purpose: Look up the provided key in a `KVPAIR` list.
 * 
 * Inputs: 
 * - `KVPAIR *list`: pointer to the start of the linked list of `KVPAIR`s.
 * - `long key`: the key to look up in the linked list.
 * 
 * Return: `KVPAIR *found_entry`, which is pointer to the entry that contains
 * the key or NULL, if the key is not found.
 */

KVPAIR *lookup(KVPAIR *list, long key) {
    KVPAIR *pointer = list;
    while (pointer != NULL) {
        if (pointer->key == key) {
            return pointer;
        }
        else{
            pointer = pointer->next;
        }
    }

    return NULL;
}


/**
 * Purpose: Delete the `KVPAIR` with the specified key from the linked list.
 * 
 * Inputs: 
 * - `KVPAIR **list`: pointer to the pointer (handle) of first key-value pair.
 * - `long key`: the key to the `KVPAIR` entry that should be deleted.
 * 
 * Return: 1 if the key was found in the list and deleted successfully. 0 if the
 * key was not found in the list and/or some error occured during the deletion.
 * 
 * Hints:
 * - You will need to change `KVPAIR`'s next pointers in the list and free
 *   memory.
 * - Think about what needs to be updated if the first entry in the list is
 *   deleted...
 */

int delete(KVPAIR **list, long key) {
    KVPAIR *pointer = *list;
    KVPAIR *previous = NULL;
    while (pointer != NULL) {
        if (pointer->key == key) {
            if (previous == NULL){
                *list = pointer-> next;}
            else {
                previous->next = pointer->next;}

            free(pointer->val);
            free(pointer);
            return 1;
            }

            else{
            previous = pointer;
            pointer = pointer->next;}
            }
        return 0;
    }
