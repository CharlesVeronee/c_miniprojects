#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "CuTest.h"

/**
 * Returns a new, dynamically allocated string whose value is the string stored
 * at `str1` concatenated with the string stored at `str2`. Note that `str1`
 * string comes first in the final string. You should use `malloc()` to allocate
 * the buffer that will hold the resulting string. Note that `str1` and `str2`
 * are valid pointers.
 * 
 * See test code below for an example of usage.
 */

char* stringcat(char* str1, char* str2) {
    char* ptr = malloc(strlen(str1) + strlen(str2)+1);
    strcpy(ptr, str1);
    strcat(ptr, str2);
    return ptr;
}

/**
 * TODO: Modify the `test_stringcat()` function to remove memory leaks.
 */

void test_stringcat(CuTest *tc) {
    char* output = NULL;

    output = stringcat("compsci", "210");
    CuAssertStrEquals(tc, "compsci210", output);

    free(output);

    output = stringcat("The weather in Durham is...", "hot and humid in the summer!");
    CuAssertStrEquals(tc, "The weather in Durham is...hot and humid in the summer!", output);

    free(output);
}

/**
 * The next few functions utilize a simple linked list struct shown below.
 * Functions that make and destroy the list are also provided below.
 */

/*
 * The linked-list node structure.
 */
struct ll_node {
    int val;
    struct ll_node *next;
};

/*
 * This function constructs the linked list recursively.
 */
struct ll_node* make_sample_list(int *values, int size) {
    if(size == 0)
        return NULL;
    struct ll_node *new_node = malloc(sizeof(struct ll_node));
    (*new_node).val = *values;
    // Using recursion isn't the most efficient way to go, but it is a simple
    // one...
    struct ll_node* rest_of_list = make_sample_list(values+1, size - 1);
    (*new_node).next = rest_of_list;
    return new_node;
}

/*
 * This function destroys the linked list recursively.
 */
void free_list(struct ll_node* head) {
    if(head == NULL)
        return;
    free_list((*head).next);
    free(head);
}

/* 
 * Computes the sum of all values in the list. Note that an empty list is a NULL
 * head and its sum is 0.
 * 
 * Look at the test cases for an example of usage.
 */

int sum_linked_list(struct ll_node* head) {
    int sum = 0;
    if(head == NULL)
        return 0;
    
    while (head != NULL) {
        sum += head->val;
        head = head->next;
    }
    return sum;
}

void test_sum_linked_list(CuTest *tc) {

    int list1[] = {1,1,2};
    struct ll_node* head = make_sample_list(list1, 3);
    CuAssertIntEquals(tc, 4, sum_linked_list(head));
    free_list(head);

    int list2[] = {1,1,1,1,100,20};
    head = make_sample_list(list2, 6);
    CuAssertIntEquals(tc, 124, sum_linked_list(head));
    free_list(head);

    head = NULL;
    CuAssertIntEquals(tc, 0, sum_linked_list(head));    
}

/*
 * Compares 2 linked lists for equality.
 * 
 * Returns 0 if the lists have different values.
 * 
 * Returns 1 if the lists are equal but fully distinct in memory (i.e. they have
 * no nodes in common).
 * 
 * Returns 2 if they share some nodes but not all nodes in memory. Note that
 * this can only happen if they have different prefixes that eventually merge
 * into one list. Think about why this is the case...
 * 
 * Returns 3 if they are the same list in memory.  
 *
 * Note that two empty lists are considered to be equal in memory BUT the two
 * distinct but equal lists can still end in null and still be considered
 * distinct.
 */

int linked_list_equality(struct ll_node* head1, struct ll_node* head2) {
    if (head1 == NULL && head2 == NULL) {
        return 3;
    }

    if (head1 == head2) {
        return 3;
    }

    while (head1 != NULL && head2 != NULL) {
        
        if (head1->val != head2->val) {
            return 0;}
        if (head1 == head2) {
            return 2;}
        head1 = head1->next;
        head2 = head2->next;

        if (head1 == NULL ^ head2 == NULL){
            return 0;
        }
    }

    return 1; 

}

void test_linked_list_equality(CuTest *tc) {

    int list1[] = {1,1,2};
    int list2[] = {1,1,3};
    struct ll_node* head1 = make_sample_list(list1, 3);
    struct ll_node* head2 = make_sample_list(list2, 3);
        
    CuAssertIntEquals(tc, 0, linked_list_equality(head1, head2));
    free_list(head1);
    free_list(head2);

    int list3[] = {1,1,2,4};
    int list4[] = {1,1,2};
    head1 = make_sample_list(list3, 4);
    head2 = make_sample_list(list4, 3);
        
    CuAssertIntEquals(tc, 0, linked_list_equality(head1, head2));
    free_list(head1);
    free_list(head2);

    int list5[] = {1,1,2,4};
    head1 = make_sample_list(list5, 4);
    // this will make a memory distinct list
    head2 = make_sample_list(list5, 4);
        
    CuAssertIntEquals(tc, 1, linked_list_equality(head1, head2));
    free_list(head1);
    free_list(head2);

    int list6[] = {1,1,2,4};
    struct ll_node* shared_list = make_sample_list(list6, 4);
    struct ll_node extra1, extra2;
    extra1.val = 0;
    extra1.next = shared_list;
    extra2.val = 0;
    extra2.next = shared_list;
    CuAssertIntEquals(tc, 2, linked_list_equality(&extra1, &extra2));

    CuAssertIntEquals(tc, 3, linked_list_equality(shared_list, shared_list));
    free_list(shared_list);

}

int main(int argc, char *argv[]) {
    
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    if (argc < 2) {
            printf("Usage: pointers2 <testname> \ntest names:\n");
            printf("all\nstringcat\nsum_linked_list\nlinked_list_equality\nmake_chain_in_memory\n");
                        return(-1);
    }
    if (!strcmp(argv[1], "all")) {
        SUITE_ADD_TEST(suite, test_stringcat);
        SUITE_ADD_TEST(suite, test_sum_linked_list);
        SUITE_ADD_TEST(suite, test_linked_list_equality);
    } else if (!strcmp(argv[1], "stringcat")) {
        SUITE_ADD_TEST(suite, test_stringcat);} 
    else if (!strcmp(argv[1], "sum_linked_list")) {
        SUITE_ADD_TEST(suite, test_sum_linked_list);
    } else if (!strcmp(argv[1], "linked_list_equality")) {
        SUITE_ADD_TEST(suite, test_linked_list_equality);
    }

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
    return 0;
}
