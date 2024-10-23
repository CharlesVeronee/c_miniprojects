# Lab 06

## Objectives

- Gain some experience with pointers in C.

---

### Overview

This lab gets you started with working with pointers in C. Using (and misusing)
pointers is a very important concept to learn and practice. 

Using pointers correctly can result in less time in a program's execution,
creating data structures like a linked list, stack, queue, etc., dynamically
allocating memory based on the program's needs, and much more. 

Misusing pointers can result in buggy programs, segmentation faults, exploitable
programs, and much more.

Thanks to Professor Mike Hewner for his work on these problems!

---

### `pointers.c`

There are a total of 10 functions for you to write (the first 8 are required,
the last 2 are optional). Each function is defined in the file `pointers.c` and
you are to fill in the function body to implement the specified functionality.

The file `pointers.c` contains instructions for each function along with test cases.

Required functions:
* `add_with_pointers()`
* `address_in_array()`
* `bytes_between_4s()`
* `point_to_smallest()`
* `point_to_smallest_ptr()`
* `power_replace()`
* `power_sum_dont_replace()`
* `set_string_with_q()`

Extra Credit Functions:
* `remove_2nd_q_strings()`
* `doublecorrectly()`

---

### Local Testing and Submission

1. Run `make` to (re)compile your program(s).

2. Test all functions:

   ```bash
   ./pointers
   ```

3. Or test individual components:

   ```bash
   ./pointers TEST_SUITE_NAME
   ```

   where `TEST_SUITE_NAME` is one of function names (e.g. `add_with_pointers`).

4. Run the local Python test script to check your code:

   ```bash
   python3 test_kit.py ALL
   ```

5. Add, commit, and push the file `pointers.c` to your Git repository.

6. Submit your completed lab to Gradescope via the GitLab submission button.
