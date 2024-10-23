
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "kv_cache.h"


// Lookup the provided key in the KV cache.
// If the key is not found, fetch it from storage by calling read_key
// and place the KVPAIR in the cache.
// If placing a KVPAIR from memory into the cache causes the number of elements
// in the bin to exceed MAX_BIN_ELEMENTS, remove a KVPAIR using the LRU
// replacement policy and call write_key if the removed KVPAIR has
// been modified and changes need to be written back to memory.
// If the key is found in the cache, update LRU order for the
// key's bin appropriately.
// Input: the KV cache hash table and key to lookup
// Return: pointer to KVPAIR with the desired key

unsigned int hits;
unsigned int misses;
unsigned int writebacks;


KVPAIR *lookup(KVCACHE *kv_cache, long key, unsigned int bins) {

    unsigned int index = key % bins;

    //initialize the two kv pairs
    KVPAIR *current_pair = kv_cache[index].list;
    KVPAIR *previous_pair = NULL;

    //when you get a hit
    while (current_pair != NULL) {

        if (current_pair->key == key) {
            hits ++;

            //KVPAIR *previous_pair = current_pair->prev;
            //KVPAIR *next_pair = current_pair->next;

            //when pair isn't at front of list
            if (previous_pair != NULL) {
                
                //link on either side
                previous_pair->next = current_pair->next;
                if (current_pair->next != NULL) {
                    current_pair->next->prev = previous_pair;
                }

                // move current pair to front
                current_pair->next = kv_cache[index].list;
                kv_cache[index].list = current_pair;

                return current_pair;
            }


            if (previous_pair == NULL) {
                return current_pair;
            }
    
        }

        //update previous and current pair one forward
        previous_pair = current_pair;
        current_pair = current_pair->next;
    }


    //key not found
    misses++;

    KVPAIR *new_pair = read_key(key);

    //double linked up
    new_pair->next = kv_cache[index].list;
    kv_cache[index].list = new_pair;

    //see if max amount of items in list or not; if so do LRU
    KVPAIR *counter = kv_cache[index].list;
    int count = 1;
    while (counter->next != NULL) {
        count ++;

        //check to see if max number of items in an index

        if (count > MAX_BIN_ELEMENTS) {
            if (counter->next->modified) {
                writebacks++;
                write_key(counter->next);
            }

            //free value pointer first, then free entire KV pair

            KVPAIR *to_free = counter->next;
            free(to_free->val);
            free(to_free);

            counter->next = NULL;

            break;
        }
        counter = counter->next;
    }
    return new_pair;
}
