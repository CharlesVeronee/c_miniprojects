# Lab 07

## Objectives

* Gain more experience with pointers and dynamic memory allocation (the infamous
  `malloc()` and `free()` functions).

---

### Overview

Pointers and dynamic memory allocation are very important tools in C. You will
be working a bit with strings, but also with a simple singly linked list.

Thanks to Mike Hewner for his work on these problems!

---

### `pointers2.c`

Modify three user functions (and one tester function) in `pointer2.c` to
correctly implement the specified functionality. The functionality is in the
comments above each function in `pointers2.c`. As always, if you're confused by
the instructions, feel free to come to office hours or post on Ed! The functions
you need to work on are:

1. `stringcat()`,
2. `test_stringcat()` (this is the testing function you fix),
3. `sum_linked_list()`,
4. `linked_list_equals()`.

---

### Testing:

Everytime you make changes in the source file `pointers2.c`, you have to
build the corresponding executable `pointers2` by executing:

```bash
make pointers2
```

You can then test all of the functions by running:

```bash
./pointers2 all
```

You can even test an individual function by passing the function name as a
command line argument. For example:

```bash
./pointers2 sum_linked_list
```

or:

```bash
./pointers2 stringcat
```

You may use any of the libraries that are included at the top of `pointers2.c`.
This includes `string.h`, which provides the following useful (but not strictly
necessary) functions:

- `strlen(char *str)`: Returns the number of characters in the provided string,
  not including the terminator.
- `strcat(char *dest, char *src)`: Concatenates string `src` onto the end of
  string `dest`. Note that the buffer pointed to by `dest` must be large enough
  to contain the result, or else an error may occur. 

---

### Final Local Testing Before Submission

To test your functions one more time, you can use the autograder:

```bash
python3 test_kit.py ALL
```

---

### Submission

Submit your `pointers2.c` file to Gradescope via the GitLab submission button.
