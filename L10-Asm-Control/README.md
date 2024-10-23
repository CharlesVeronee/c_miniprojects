# Lab 10: Asm Control

## Objectives

- Learn about how the compiler turns C conditionals into x86-64 assembly code.
- Solve the inputs to a mystery program by disassembling the functions and
  stepping through the program in GDB.
- Perform some basic string manipulation in C.

---

### `prog2.c`

To get started, build the program `prog2` by typing `make` at the command
prompt.

Then use GDB to disassemble the functions `my_if()`, `my_for()`, and `my_while()`.  

To do this, start the debugger (i.e., `gdb prog2`) and then at the prompt type 

```
(gdb) disas my_if
``` 

to see the x86-64 instructions for the function `my_if()`.  Be sure to
understand what each instruction is doing. 

Do the same for the other functions.  Look at the source code in `prog2.c`,
DIS 7.1-7.4, 
and the [x86 Guide Sheet](https://web.stanford.edu/class/cs107/guide/x86-64.html) 
on the course website to help your understanding. 

While stepping through the functions, you might want to print out the argument
registers and the return registers to see how the registers are changing.

You can also check out the [GDB Cheat
Sheet](https://drive.google.com/file/d/1fYWLKE5yLp02Tv6rYKVBAxAs3LW0WoRi/view)
linked on the course website to see more debugging commands you can run.

---

### `mystery2`

The main task of this lab is to reverse engineer four functions in program
`mystery2`.

Run the program `mystery2` (type `./mystery2`). It should prompt for some inputs
and you need to figure out the correct inputs by examining the instructions of
the corresponding functions.  

The functions are cleverly named `f1()`, `f2()`, and `f3()`.  You can
run the program interactively (you enter answers on the command line) for
initial testing of your program.  

You can run each test individually by passing an integer argument to `mystery2`
(e.g., .`./mystery2 1` will test `f1()`) or just run `./mystery2` and it will
progress through all tests.

Ultimately for final testing and submission you need to place your answers in a
files called:

1. `solution_f1.txt`,
2. `solution_f2.txt`,
3. `solution_f3.txt`,

These file should have your answers on a single line with spaces between the
integer values

For example, if the solution for `f2()` is "1 2 3", then the contents of
`solution_f2.txt` should be:

```text
1 2 3
```

You can then use I/O redirection to execute the program with your solution file
(i.e., `./mystery2 1 < solution_f1.txt`).

---


---

### Final Local Testing Before Submission

Test your results by running

```bash
python3 test_kit.py mystery2
```

If your files are not properly named, the last line of the error will look
something like this:

```bash
FileNotFoundError: [Errno 2] No such file or directory: 'solution_f1.txt'
```

Please follow the naming format we provided for you above, and make sure you
have created all four solution files in your lab directory.

---

### Submission

1. Please run the below before submitting to Gradescope to delete your compiled
   executables (NOTE: `mystery2` is provided to you and should **NOT** be
   deleted):

   ```bash
   make clean
   ```

2. Submit your solution .txt files to Gradescope via GitLab submission.
