# Lab 05

## Objectives

- Get comfortable performing bit manipulations in C.

---

### Overview

Like with previous labs, fork and clone the repository to your container.

You are to write the code for 6 functions: `isNegative()`, `negate()`,
`getByte()`, `byteSwap()`, `rotateRight()` and `addOK()` using only bit-wise
operations (no conditionals, `while` loops, function calls, etc). You are
allowed to define new variables to help you.

Please read through the comments in the source code for restrictions and
specifications about input and output, and about the coding style that you
should use for this lab.

---

### `bits.c`

The function prototypes of the functions you need to complete are defined in
`bits.c`, but they simply return the value `2` right now. You need to change the
function bodies to return the correct value, but you are limited to using only
bit-wise operations. Further information about correct functionality for each
function is in `bits.c` (you should definitely read the information in that file
before starting on the lab...) and will be briefly described below.

The provided `Makefile` runs the provided program `dlc` on your `bits.c` file to
check for any violations of the operator restrictions. If there are any
restrictions you do not understand, please make a *private* post with your code
or question on the discussion forum and we can take a look. Last semester, there
were some issues with the `dlc` compiler, so if you see errors you cannot
explain at all, feel free to reach out to us on Ed, or come to office hours.

**Important Note: PLEASE DO NOT MODIFY ANYTHING OTHER THAN THE 6 FUNCTIONS IN
`bits.c`**. If you do, the `dlc` compiler will almost certainly give you errors,
and you will get no points for the lab.

**Another Important Note:** If you wish to debug this file, you can use
`printf()`, but please do not include any header files. This includes `stdio.h`.
This is another quirk of the `dlc` checker.

**Quick Note about Number Representation:** In this assignment, and future
assignments, numbers may be presented to you in decimal, hexadecimal, binary,
and octal (okay, maybe never octal). In C, the way numbers are represented
doesn't matter as the number itself is stored as a binary number in memory.
Therefore, doing something like 

```c
int three = 1 + 2;
```

is equivalent in C to writing

```c
int three = 0x1 + 0x2;
```

You can even mix the different number representations if it helps you:

```c
int three = 0x1 + 2;
```

The integer `three` holds the value of `3` in all three provided code snippets.

---

### Individual Functions

Note that all this information can be found in `bits.c`. Again, please read the
information in that file before starting with the lab.

* `isNegative()`: Returns `1` if the integer passed in is negative and `0` if
  it's not negative. For example, passing in `-300` will result in `1`, while
  passing in `300` will result in `0`.

* `negate()`: Takes the number passed in and negates it. For example, `1`
  becomes `-1` and vice versa.

* `getByte()`: Returns the byte at position `n` of the number `x`. For example,
  the byte returned at position `1` of the hexadecimal number `0x12345678` would
  be `0x56`, while the byte returned at position `3` of the hexadecimal number
  `0x12345678` would be `0x12`. Note that **two** hexadecimal digits represent
  one byte. How many bits do you need to represent one byte?

* `byteSwap()`: Returns the integer `x` after `2` bytes of data at position `n`
  and `m` are swapped with each other. For example, the integer returned from
  swapping position `1` and `3` of `0x12345678` would be `0x56341278`.

* `rotateRight()`: Returns the integer `x` rotated to the right by `n` **bits**.
  For example, `0x12345678` rotated to the right by `4` bits would be
  `0x81234567`, `0x12345678` rotated to the right by `8` bits would be
  `0x78123456`, `0x12345678` rotated to the right by `24` bits would be
  `0x34567812`.

* `addOK()`: Returns `1` if `x + y` does not result in overflow and `0` if `x +
  y` result in overflow. For example `0x80000000 + 0x80000000` returns `0`,
  while `0x80000000 + 0x70000000` returns `1`.

---

### Debugging Advice

**MAKE SURE TO DECLARE VARIABLES AT THE TOP OF EACH FUNCTION.**

It is extremely helpful sometimes to debug your code by putting print statements
in the functions that are failing (or use GDB if you have experience with
debugging C) and running the individual function test to see how the number
changes after each line of code. **You must comment out or delete the print
statements once you are ready to test/submit your code.**

Instructions for testing all functions with the Python tester and individual
functions with the `btest` executable is described in the **Local Testing and
Submission** section below.

You may look at the provided `btest.c` to see how to check individual functions
and tests. Also, make sure to check out the `tests/` folder for the expected
terminal outputs.

After running the Python test script, the `tests/` folder will be populated with
the actual and expected text files as well as a difference text file. You should
use these files to help debug your code in addition to using GDB or adding print
statements in your code.

---

### Local Testing and Submission

1. Run `make` to compile `bits.c` along with the provided testing file
   `btest.c`. This command will also run your code in `bits.c` through the `dlc`
   compiler, to check whether it follows all the specifications. Therefore, you
   do not need to run the `dlc` program yourself at any point in time, and also,
     you **should not change anything** in `btest.c`.

2. You can test individual functions or all of them with the `btest` executable.
   ```bash
   ./btest <testname>
   ```
   For example, `./btest ALL` will run all functions while `./btest negate` will
   run only the `negate()` function.

3. Run the local Python test script by running the following on the Unix command
   line:
    ```bash
    python3 test_kit.py ALL
    ```

4. Add, commit, and push the `bits.c` file to your Git repository.

5. Submit your completed lab to Gradescope via the GitLab submission button.
