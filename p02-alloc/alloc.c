// A segregated storage memory allocator.  Complete the code required in the functions below
// to implement a segregated memory allocator.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alloc.h"

int max_heap_size = 1024;  // default is a 1K heap (pretty small)

void *heap[4] = {NULL,NULL,NULL,NULL}; // the heap bins for each segregated size 8,16,32,64

unsigned int heap_size = 0; // A variable that keeps track of the how much memory we allocated

// allocate_slab uses the default malloc library to allocate memory
// input: size in bytes of slab to allocate
// return: pointer to slab allocated, NULL if allocation would exceed max_heap_size
void *allocate_slab(unsigned int size) {
    unsigned int total_size = heap_size + size;
    if (total_size > max_heap_size){
        return NULL;}

    heap_size+=size;
    void *slab = malloc(size);
    return slab;
}


// Returns a pointer to a heap block of the appropriate
// size.
// If no such block exists in the free list, this function calls
// allocate_slab to get space NUM_HEAP_BLOCKS blocks of the
// appropriate size and adds them to the free list, then returns
// one of them.
void *my_alloc(unsigned int size) {

    int blk_size = sizeof(blk_header_t);
    unsigned int total_size = size + blk_size;

    int bin = (size > 8) + (size > 16) + (size > 32) + (size > 64);
    
    blk_header_t* starter = heap[bin];

    int slab_heap_size = total_size * NUM_HEAP_BLOCKS;

    if (starter == NULL) {
        starter = (blk_header_t*) allocate_slab(slab_heap_size);

        if (starter == NULL) {
            printf("Malloc failed, out of memory!\n");
            exit(0);
        }

        blk_header_t* starter_block = (blk_header_t*)starter;

            for (int i = 0; i < NUM_HEAP_BLOCKS-1; i++) {
                starter_block->size = total_size - blk_size;

                starter_block->next =(blk_header_t*)((char*)starter_block + total_size);

                starter_block = starter_block->next;
            }

        starter_block->next = NULL;

        starter_block->size = total_size - blk_size;
        
    }

    blk_header_t *separate = (blk_header_t*) starter;

    void* top = (void*)((char*) starter + blk_size);


    heap[bin] = starter->next;
    separate->next = NULL;
    return top;
}

void my_free(void *ptr) {
    int blk_size = sizeof(blk_header_t);

    if (ptr == NULL) {
        return;
    }

    blk_header_t *head = (blk_header_t *) ((void*) ptr - blk_size);
    int bin; 

    if (head -> size > 32) {
        bin = 3; 
    } else if (head -> size > 16) {
        bin = 2; 
    } else if (head -> size > 8) {
        bin = 1; 
    } else {
        bin = 0; 
    }

    head -> next = (blk_header_t*) heap[bin]; 
    heap[bin] =  (void*) head;
}
