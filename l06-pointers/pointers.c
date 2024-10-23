#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "CuTest.h"

/*
 * This function takes two pointers to integers, and returns the sum of the
 * integers being pointed to.
 * 
 * Look at the `test_add_with_pointers()` below for an example of usage.
 */
int add_with_pointers(int *val1, int *val2) {
    int x = *val1;
    int y = *val2;
    return x+y;
}

void test_add_with_pointers(CuTest *tc) {
    int a = 7;
    int b = 11;
    // These two lines are essentially asserting that the sum of 7 and 11 is 18,
    // and also that the sum of 11 and 11 is 22. Note that we are passing (to
    // the function `add_with_pointers()`) the addresses of the two integers. In
    // other words, we are passing two pointers.
    CuAssertIntEquals(tc, 18, add_with_pointers(&a, &b));
    CuAssertIntEquals(tc, 22, add_with_pointers(&b, &b));
}

/*
 * This function takes an integer as a parameter.  It returns the address of
 * that integer in the global array called `arrayForFinding` or `NULL` if that
 * integer is not present in the array.
 * 
 * Note: `arrayForFinding` is zero delimited - its last element is always 0 and
 * 0 is not a valid element elsewhere in the array. You'll want to use this
 * information to know when to stop searching, similarly to how you would stop
 * searching for a character in a null-terminated array of characters.
 * 
 * Look at the `test_address_in_array()` for an example of usage.
 */

int arrayForFinding[] = { 7, 8, 13, 19, 3, 0 };

int* address_in_array(int value_to_find) {
    int* pointer = arrayForFinding;
    while (*pointer != 0) {
        if (*pointer == value_to_find) {
            return pointer;
        }
        pointer++;
    }
    return NULL;
}

void test_address_in_array(CuTest *tc) {
    // Here we are asserting that the address of the array (second argument
    // here), is at the same time the address of the number 7 in the array. Note
    // that the cast we are doing here is not necessary (due to the way C
    // handles arrays and pointers -- they are basically the same thing), but it
    // is good that it's here since it makes things more obvious.
    CuAssertPtrEquals(tc, (int*) arrayForFinding, address_in_array(7));
    CuAssertPtrEquals(tc, (int*) arrayForFinding + 1 , address_in_array(8));
    CuAssertPtrEquals(tc, (int*) arrayForFinding + 4 , address_in_array(3));
    CuAssertPtrEquals(tc, NULL , address_in_array(777));
}

/*
 * This function takes an integer array with 2 fours in it.
 * It returns the number of bytes between the pair of 4s.  
 * 
 * If the 4s are consecutive, the function should return 0.  
 * If there was n number of values in between the 4s, 
 * the function should return n * sizeof(int).
 * 
 * You might want to use pointer subtraction here, among other things.
 * 
 * Look at the `test_bytes_between_4s()` for an example of usage.
 */
int bytes_between_4s(int* array) {
    int* first_4 = NULL;
    int* second_4 = NULL;
    int index = 0;
 
    while (array[index] != 4) {
        if (array[index] == 0) {
            return 0;
        }
        index++;
    }
    first_4 = &array[index];
    index++;
    while (array[index] != 4) {
        if (array[index] == 0) {
            return 0;
        }
        index++;
    }
    second_4 = &array[index];
    return (second_4 - first_4 - 1) * sizeof(int);
}

void test_bytes_between_4s(CuTest *tc) {
    // By now you probably get how `Cu*` functions work, but here we are making
    // sure that in an array where there is exactly one integer between the two
    // fours, your function is returning `sizeof(int)`. Similarly, we make sure
    // that when there are three integers in between, you function returns
    // `3*sizeof(int)`. Finally, we make sure that when the fours are right next
    // to each other, your function returns 0.
    int onedist[] = {4,1,4};
    CuAssertIntEquals(tc, sizeof(int), bytes_between_4s(onedist));
    int threedist[] = {7,4,9,9,77,4,12};
    CuAssertIntEquals(tc, 3*sizeof(int), bytes_between_4s(threedist));
    int zerodist[] = {1,4,4};
    CuAssertIntEquals(tc, 0, bytes_between_4s(zerodist));
}

/* 
 * This function takes 2 (valid) pointers to integers and compares the
 * value they point to determine the smallest value.  Then it sets both
 * integers to that value.
 * 
 * Look at the `test_point_to_smallest()` for example of usage.
 */

void point_to_smallest(int* first, int* second) {
    int x = *first;
    int y = *second;
    if (y>x) {
        *second = *first;
    }
    if (x>y) {
        *first = *second;
    }
    return;
}

void test_point_to_smallest(CuTest *tc) {
    int a, b;
    a = 7;
    b = 8;
    point_to_smallest(&a, &b);
    CuAssertIntEquals(tc, 7, a);
    CuAssertIntEquals(tc, 7, b);

    a = 10;
    b = 4;

    point_to_smallest(&a, &b);
    CuAssertIntEquals(tc, 4, a);
    CuAssertIntEquals(tc, 4, b);
}

/*
 * This function takes 2 int** (double pointers, or handles).  It compares the
 * integers being pointed to, and then sets the pointers to the address of the
 * smaller of the two integers.
 * 
 * If the values are equal, both pointers should be set to
 * the address of the first pointer.
 * 
 * Either of the pointers being passed in might point to NULL instead of
 * a valid integer - in that case the other value is implicitly the
 * smallest and both pointers should be set to point to the non-NULL
 * value.  You can assume both pointers will not be NULL at the same time.
 * 
 * Look at the test_point_to_smallest_ptr for example of usage.
 */

void point_to_smallest_ptr(int** first, int** second) {
    if (*first == NULL) {
        *first = *second;
    } else if (*second == NULL) {
        *second = *first;

    } else {
        int value1 = *(*first);
        int value2 = *(*second);

        if (value1 > value2) {
            *first = *second;
        } else if (value2 > value1) {
            *second = *first;
        } else if (value2 == value1) {
            *second = *first;
        }
    }
    return;
}


void test_point_to_smallest_ptr(CuTest *tc) {

    int a, b, *a_ptr, *b_ptr;
    a = 7;
    b = 8;
    a_ptr = &a;
    b_ptr = &b;
    point_to_smallest_ptr(&a_ptr, &b_ptr);
    CuAssertIntEquals(tc, 7, *a_ptr);
    CuAssertIntEquals(tc, 7, *b_ptr);

    a = 11;
    b = 11;
    a_ptr = &a;
    b_ptr = &b;
    point_to_smallest_ptr(&a_ptr, &b_ptr);
    CuAssertPtrEquals(tc, &a, a_ptr);
    CuAssertPtrEquals(tc, &a, b_ptr);

    
    a = 10;
    b = 4;
    a_ptr = &a;
    b_ptr = &b;

    point_to_smallest_ptr(&a_ptr, &b_ptr);
    CuAssertIntEquals(tc, 4, *a_ptr);
    CuAssertIntEquals(tc, 4, *b_ptr);

    
    a_ptr = &a;
    b_ptr = NULL;

    point_to_smallest_ptr(&a_ptr, &b_ptr);
    CuAssertIntEquals(tc, 10, *a_ptr);
    CuAssertIntEquals(tc, 10, *b_ptr);    

    
    a_ptr = NULL;
    b_ptr = &b;

    point_to_smallest_ptr(&a_ptr, &b_ptr);
    CuAssertIntEquals(tc, 4, *a_ptr);
    CuAssertIntEquals(tc, 4, *b_ptr);    

}

/*
 * This function takes a pointer to an integer value and a (assumed
 * non-negative) power.  The function modifies the given value by taking it to
 * the stated power. Note that continuous multiplication using the underlying
 * value is completely fine here.
 * 
 * Look at the `test_power_replace()` for an example of usage.
 */
void power_replace(int* val, int power) {
    int base = *val;
    int i;
    int answer = 1;
    for (i=1 ; i<= power; i++) {  
        answer = answer * base;  
    }
    *val = answer;
    return;
}

void test_power_replace(CuTest *tc) {
    int val = 2;

    power_replace(&val, 3);
    CuAssertIntEquals(tc, 8, val);
    power_replace(&val, 2);
    CuAssertIntEquals(tc, 64, val);
    power_replace(&val, 1);
    CuAssertIntEquals(tc, 64, val);
    power_replace(&val, 0);
    CuAssertIntEquals(tc, 1, val);
}

/*
 * This function takes two integer pointers and computes a^3 + b^3, where
 * a and b are the two integer values pointed at. 
 * 
 * Note that the computation must be done with the already written
 * `power_replace()` function and the values of the initial parameters a and b
 * must not be changed (hint: make some copies of the original integers).
 * 
 * Look at the `test_power_sum_dont_replace()` for example of usage.
 */

int power_sum_dont_replace(int* a, int* b) {
    int copya = *a;
    int copyb = *b;

    power_replace(&copya, 3);
    power_replace(&copyb,3);
   
    
    int answer = copya + copyb;

    return answer;
}

void test_power_sum_dont_replace(CuTest *tc) {
    int a = 2;
    int b = 3;
    int result = power_sum_dont_replace(&a, &b);
    CuAssertIntEquals(tc, 35, result);
    CuAssertIntEquals(tc, 2, a);
    CuAssertIntEquals(tc, 3, b);

    a = 4;
    b = 1;
    result = power_sum_dont_replace(&a, &b);
    CuAssertIntEquals(tc, 65, result);
    CuAssertIntEquals(tc, 4, a);
    CuAssertIntEquals(tc, 1, b);
}

/*
 * This function takes two strings as parameters, only 1 of which will contain a
 * lowercase 'q'.  
 * The function puts the string with a q into the address pointed at by the
 * output pointer. In other words, the third argument will be a `char **`
 * (double pointer).
 * 
 * For example:
 * char *a = "foo"
 * char *b = "q"
 * char *c;
 * 
 * set_string_with_q(a, b, &c);
 * 
 * // now c == b
 * 
 * Look at the test_set_string_with_q for example of usage
 */


void set_string_with_q(char* s1, char* s2, char** output) {
    if (strchr(s1, 'q') != NULL){
        *output = s1;
    }
    else{
        *output = s2;
    }
}

void test_set_string_with_q(CuTest *tc) {

    char* q_str = "abcq";
    char* no_q_str = "xy";
    char* output;

    set_string_with_q(q_str, no_q_str, &output);
    CuAssertPtrEquals(tc, q_str, output);
    set_string_with_q(no_q_str, q_str, &output);
    CuAssertPtrEquals(tc, q_str, output);
    
    char* q_str2 = "qabc";
    char* no_q_str2 = "abcdef";

    set_string_with_q(no_q_str2, q_str2, &output);
    CuAssertPtrEquals(tc, q_str2, output);
}

/*
 * The following function is OPTIONAL. You DO NOT have to implement it to get
 * full points for the lab.
 *
 * The function take an array of strings and a size of that array.
 * 
 * The function sets elements of the array (the strings) to NULL if the second
 * character of the given, referenced string is a q. If that is not the case,
 * the string is left as is.
 * 
 * You can assume no element of the array is initially NULL, but checking for
 * this is good practice.
 * 
 * Look at the test_remove_2nd_q_strings for example of usage.
 */

void remove_2nd_q_strings(char** array, int size) {
    return;
}

void test_remove_2nd_q_strings(CuTest *tc) {

    char* q_1st = "qabcd";
    char* q_2nd = "aqbcd";
    char* q_strs1[] = {q_1st, q_2nd, q_1st, q_2nd , q_2nd};

    remove_2nd_q_strings(q_strs1, 4);
    CuAssertPtrEquals(tc, q_1st, q_strs1[0]);
    CuAssertPtrEquals(tc, NULL, q_strs1[1]);
    CuAssertPtrEquals(tc, q_1st, q_strs1[2]);
    CuAssertPtrEquals(tc, NULL, q_strs1[3]);
    //check that we respect size
    CuAssertPtrEquals(tc, q_2nd, q_strs1[4]);

    char* no_q = "hello";
    char* q_2nd_2 = "qq";

    char* q_strs2[] = {q_2nd, q_2nd_2, no_q, q_1st , q_2nd_2};

    remove_2nd_q_strings(q_strs2, 5);
    
    CuAssertPtrEquals(tc, NULL, q_strs2[0]);
    CuAssertPtrEquals(tc, NULL, q_strs2[1]);
    CuAssertPtrEquals(tc, no_q, q_strs2[2]);
    CuAssertPtrEquals(tc, q_1st, q_strs2[3]);
    CuAssertPtrEquals(tc, NULL, q_strs2[4]);
    
}


/*
 * Another optional function. You DO NOT have to implement it to get full points
 * for the lab.
 *
 * `doublecorrectly()` takes a `void` pointer to an array of data and `num`
 * parameter indicating the size of that array. 
 *
 * The array contains either 32 bit integer values (int32_t) or doubles (size
 * could theoretically vary - you can use pointer math or sizeof(double) to
 * figure out what the size is on this system). The first parameter is set to
 * false if the values are integer data, true if the values are double data.
 * 
 * `doublecorrectly()` should loop though the items in the array and double them
 * in the appropriate way for the type they are.
 * 
 * Look at the `test_doublecorrectly()` for example of usage.
 */

void doublecorrectly(bool is_double, void* data, int num) {
    return;
}

void test_doublecorrectly(CuTest *tc) {

    int32_t intdata[] =  {1, 4, -1};
    doublecorrectly(false, intdata, 3);
    CuAssertIntEquals(tc, 2, intdata[0]);
    CuAssertIntEquals(tc, 8, intdata[1]);
    CuAssertIntEquals(tc, -2, intdata[2]);

    double doubledata[] =  {1.0, 8.0, -1.0, 999};
    doublecorrectly(true, doubledata, 4);
    CuAssertDblEquals(tc, 2.0, doubledata[0],0.00001);
    CuAssertDblEquals(tc, 16.0, doubledata[1],0.00001);
    CuAssertDblEquals(tc, -2.0, doubledata[2], 0.00001);
    CuAssertDblEquals(tc, 1998, doubledata[3], 0.00001);    
    
}


int main(int argc, char *argv[]) {
    
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    if (argc < 2) {
            printf("Usage: pointers <testname> \ntest names:\n");
            printf("all\nadd_with_pointers\naddress_in_array\nbytes_between_4s\npoint_to_smallest\npoint_to_smallest_ptr\npower_replace\npower_sum_dont_replace\nset_string_with_q\nremove_2nd_q_strings\ndoublecorrectly\n");
            return(-1);
    }
    if (!strcmp(argv[1], "all")) {
        SUITE_ADD_TEST(suite, test_add_with_pointers);
        SUITE_ADD_TEST(suite, test_address_in_array);
        SUITE_ADD_TEST(suite, test_bytes_between_4s);
        SUITE_ADD_TEST(suite, test_point_to_smallest);
        SUITE_ADD_TEST(suite, test_point_to_smallest_ptr);
        SUITE_ADD_TEST(suite, test_power_replace);
        SUITE_ADD_TEST(suite, test_power_sum_dont_replace);
        SUITE_ADD_TEST(suite, test_set_string_with_q);
        SUITE_ADD_TEST(suite, test_remove_2nd_q_strings);
        SUITE_ADD_TEST(suite, test_doublecorrectly);
    } else if (!strcmp(argv[1], "add_with_pointers")) {
        SUITE_ADD_TEST(suite, test_add_with_pointers);
    } else if (!strcmp(argv[1], "address_in_array")) {
        SUITE_ADD_TEST(suite, test_address_in_array);
    } else if (!strcmp(argv[1], "bytes_between_4s")) {
        SUITE_ADD_TEST(suite, test_bytes_between_4s);
    } else if (!strcmp(argv[1], "point_to_smallest")) {
        SUITE_ADD_TEST(suite, test_point_to_smallest);
    } else if (!strcmp(argv[1], "point_to_smallest_ptr")) {
        SUITE_ADD_TEST(suite, test_point_to_smallest_ptr);
    } else if (!strcmp(argv[1], "power_replace")) {
        SUITE_ADD_TEST(suite, test_power_replace);
    } else if (!strcmp(argv[1], "power_sum_dont_replace")) {
        SUITE_ADD_TEST(suite, test_power_sum_dont_replace);
    } else if (!strcmp(argv[1], "set_string_with_q")) {
        SUITE_ADD_TEST(suite, test_set_string_with_q);
    } else if (!strcmp(argv[1], "remove_2nd_q_strings")) {
        SUITE_ADD_TEST(suite, test_remove_2nd_q_strings);
    } else if (!strcmp(argv[1], "doublecorrectly")) {
        SUITE_ADD_TEST(suite, test_doublecorrectly);
    }

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
    return 0;
}
