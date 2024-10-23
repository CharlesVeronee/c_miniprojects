/* 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Lab by editing the collection of functions
in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants. You are allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. use the autograder test scripts for local testing in your container
 *    python3 ../src/test_kit.py ALL  will run all the tests
 */


#endif

/*
 * 
 * Your code below
 * 
 */

/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
   // arithmetic shift right by 31 bits to put MSB in LSB position; binary AND creats a bitmask on all digits except the LSB
   // if LSB is 1 (negative), will return 1 (negative) and if LSB is 0 (positive), will return 0 (positive) 

   return ((x >> 31) & 1); 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
   // flips the bits; add 1 to negate number using two's complement

   return (~x + 1);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 3 (most significant) to 0 (least significant) 
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
   // arithmetic left shift n by 3 bits (which is multiplying n by 8 since 8 bits in a byte) to see how much you need to shift x by to get byte in LSB position
   // arithmetic right shift x by 8n bits to get desired byte in LSB position
   // mask new x with 0xFF to get rid of everything except least significant 8 bits
   int shiftn = n << 3;
   int shiftx = x >> shiftn;
   return (shiftx & 0xFF);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
   // arithmetic shift n and m left by 3 bits (which is multiplying n and m by 8 since 8 bits in a byte) to see how much you need to shift x by to get desired byte in LSB position
   // extract bytes at positions n and m using a mask to get rid of everything except desired byte in LSB position
   // clear the original bytes in position n and m in x by shifting mask into correct position and using ~ to invert all bits to create a clear mask which will be used with &
   // use mask on x to clear positions of byte n and m in x
   // get bytes into position by shifting byte n into m position and byte m into n position so they can be added to clear x
   // return bytes inserted into opposite positions
   int shiftn = n << 3;  
   int shiftm = m << 3;

   int byten = (x >> shiftn) & 0xFF;
   int bytem = (x >> shiftm) & 0xFF;

   int mask = ~(((0xFF << shiftn) | (0xFF << shiftm)));
   int clearx = x & mask;

   int newbytes = (byten << shiftm) | (bytem << shiftn);
   return clearx | newbytes;
}
/* 
 * rotateRight - Rotate x to the right by n bits
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
   // arithmetic shift x left by 32-n positions in order to get n bits to start of number on MSB side
   // right shift mask to by n-1 bits to clear bit space for new bits that will be shifted in during rotation
   // shift x by n to rotate number to the right
   // use & with shifted and opend to clear unwanted bits
   // binary OR the upper and lower parts together to get result

   int tomove = x << (32 + (~n +1));
   int mask = ~(1 << 31);
   int opened = mask >> (n+((~1)+1));
   int shifted = x >> n;
   int lowerbits = shifted & opened;
   return lowerbits | tomove;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
   // overflow if adding two negative numbers gives positive number or adding two positive numbers gives negative number
   // get signs of x, y, and sum of x and y
   // use XOR to see if x and the sign of the sum are the same and y and the sign of the sum are the same
   // if they are the same sign, there is no overflow
   int signx = x >> 31;
   int signy = y >> 31;
   int signsum = (x+y) >> 31;

   int diff_signs = (signx ^ signsum) & (signy ^ signsum);
  return !diff_signs;
}
