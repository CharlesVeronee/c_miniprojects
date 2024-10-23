**Objectives**
- Understand bits can be used to represent strings, images, and more.
- Debug buggy C code

---

**Overview**

This lab helps you understand that bits can be used to represent all kinds of things. In this lab you will explore strings and how they are stored in memory, you will also perform image file operations.

---

**image.c**

For this one you need to write a program named `image.c` from scratch that reads 
in an image file in a specific format perform a transformation on that image and 
write it back out to a file. (You will need to create the `image.c` file on your own).

**Important:** Please put these `#include`'s at the top of your `image.c` file.
```c
#include <stdio.h>
#include <stdlib.h>
#include "image_util.h"
```

**Also important:** You should use the provided `my_fwrite()` function instead of the
 general `fwrite()` function when creating your output file. All of the inputs are 
 the same as `fwrite()` but the implementation is different. This is hidden from you 
 inside of `image_util.o`. Using the provided function requires doing the step above.


The input (and output) image file is in a format called PPM and has the structure shown 
below.  PPM is one of many image file formats, we use it in this lab because it is very 
straightforward for data manipulation.

```
P6
width height
colors
<data for all the pixels>
```

The first three lines are all in ASCII, so you can read them with appropriate `fscanf()`.
We use fscanf instead of sscanf because we're dealing with an input file (a stream of data)
rather than a string. The data for the pixels is binary, thus not human readable, and you
must use `fread()` to read them into your program. Each pixel has three colors and each color is one byte in size, so there are 3 * width * height bytes to read for the image. 

**hint** 
The function signature of fread and my_fwrite is as follows:
`fread(char* dest, size_t data_size, size_t num_data, FILE* src)`
`my_fwrite(char* src, size_t data_size, size_t num_data, FILE* dest)`

You should use file input to read in the input image and file output two write a new image 
file in the same PPM format. You can assume that width <= 1024 and height <= 1024 for this lab.

You are to transform the image by inverting (complementing) the bit values for each pixel.
You need to write out a valid PPM image file as your result. This file must have all the header lines
in ASCII and the correct binary data for the pixels.

Your program needs to take two command line arguments and needs to be called image.  You are provided
the PPM file sample.ppm  so an example program execution would be:
```bash
./image sample.ppm newimg.ppm
```
This would execute your program and write a new file called newimg.ppm

You can view the input and output image files by opening them on your local machine. 

In Visual Studio Code, right click the .ppm file and click download. You should then select a folder to download it to on your local computer.

On a Mac you can use preview to view the new files. 

On a Windows or Linux machine, you can Google "ppm to png online converter", upload the ppm file, and download the png file to view.

---

**Local Testing and Submission**

1. Run `make` to recompile your program(s)

2. Or run `make PROGRAM_NAME` 
   where PROGRAM_NAME is one of [image, stringbug] to make individual programs

3. Run the local python test script by running the following on the unix command line:
    ```bash
    python3 test_kit.py ALL
    ```

4. Or test individual components:
    ```bash
    python3 test_kit.py TEST_SUITE_NAME
    ```
    where TEST_SUITE_NAME is one of [image, string]

5. Add, commit, and push the files to your git repo:
   - image.c    

6. Submit your completed lab to Gradescope via the GitLab submission button