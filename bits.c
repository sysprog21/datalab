/*
 * Modified CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Read the following instructions carefully.

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
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
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
  int pow2plus1(int x) {
      // exploit ability of shifts to compute powers of 2
      return (1 << x) + 1;
  }

  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
  int pow2plus4(int x) {
      // exploit ability of shifts to compute powers of 2
      int result = (1 << x);
      result += 4;
      return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any
arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  2. Use the btest test harness to check your functions for correctness.
  3. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
 */

/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x)
{
    int y = (x >> 30);
    y = y >> 1;
    return (y ^ x) + (~y + 1);
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000, 0x80000000) = 0,
 *            addOK(0x80000000, 0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
    int sum = x + y;
    int same = (~(x ^ y)) & (sum ^ x);



    return ((~same) >> (30) >> 1) & 1;
}

/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
    x = x & (x >> 2);
    x = x & (x >> 4);
    x = x & (x >> 8);
    x = x & (x >> 16);
    x = x & 1;
    return x;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    x = x & (x >> 2);
    x = x & (x >> 4);
    x = x & (x >> 8);
    x = x & (x >> 16);
    x = x >> 1;
    x = x & 1;
    return x;
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x)
{
    return 42;
}

/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{
    return 42;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
    return 42;
}

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
    return 42;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
    return 42;
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5, 3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit)
{
    return 42;
}

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    return 42;
}

/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y)
{
    return 42;
}

/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
    return 42;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x)
{
    return 42;
}

/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x)
{
    return 42;
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    return 42;
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
int byteSwap(int x, int n, int m)
{
    return 42;
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    return 42;
}

/*
 * countLeadingZero - count the number of zero bits preceding the
 *                    most significant one bit
 *   Example: countLeadingZero(0x00000F00) = 20,
 *            countLeadingZero(0x00000001) = 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int countLeadingZero(int x)
{
    return 42;
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
    return 42;
}

/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x)
{
    return 42;
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *                Round toward zero
 *   Examples: dividePower2(15, 1) = 7, dividePower2(-33, 4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n)
{
    return 42;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
    return 42;
}

/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *                  Should exactly duplicate effect of C expression (x*3/4),
 *                  including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x)
{
    return 42;
}

/*
 * fitsBits - return 1 if x can be represented as an n-bit, two's complement
 *            integer.
 *            1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
    return 42;
}

/*
 * fitsShort - return 1 if x can be represented as a 16-bit, two's complement
 *             integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    return 42;
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf)
{
    return 42;
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *                  for floating point argument f.
 *                  Argument is passed as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point value.
 *                  Anything out of range (including NaN and infinity) should
 *                  return 0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    return 42;
}

/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *                  Result is returned as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x)
{
    return 42;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *                Both the arguments are passed as unsigned int's, but
 *                they are to be interpreted as the bit-level representations
 *                of single-precision floating point values.
 *                If either argument is NaN, return 0.
 *                +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug)
{
    return 42;
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *               Both the arguments are passed as unsigned int's, but
 *               they are to be interpreted as the bit-level representations
 *               of single-precision floating point values.
 *               If either argument is NaN, return 0.
 *               +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug)
{
    return 42;
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf)
{
    return 42;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *               (2.0 raised to the power x) for any 32-bit integer x.
 *
 *               The unsigned value that is returned should have the
 *               identical bit representation as the single-precision
 *               floating-point number 2.0^x.
 *               If the result is too small to be represented as a denorm,
 *               return 0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    return 42;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *                 floating point argument f.
 *                 Both the argument and result are passed as unsigned int's,
 *                 but they are to be interpreted as the bit-level
 *                 representation of single-precision floating point values.
 *                 When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf)
{
    return 42;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level representation
 *               of single-precision floating point values.
 *               When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    return 42;
}

/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *                floating point argument f.
 *                Both the argument and result are passed as unsigned int's,
 *                but they are to be interpreted as the bit-level
 *                representation of single-precision floating point values.
 *                When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf)
{
    return 42;
}

/*
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *                       Result is returned as unsigned int, but it is to be
 *                       interpreted as the bit-level representation of a
 *                       single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u)
{
    return 42;
}

/*
 * getByte - Extract byte n from word x
 *           Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
    return 42;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *                  most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x)
{
    return 42;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *               two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    return 0;
}

/*
 * implication - return x -> y in propositional logic - 0 for false,
 *               1 for true
 *   Example: implication(1, 1) = 1
 *            implication(1, 0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y)
{
    return 42;
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x)
{
    return 42;
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters
 *                '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    return 42;
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y)
{
    return 42;
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
    return 42;
}

/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y)
{
    return 42;
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    return 42;
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x)
{
    return 42;
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x)
{
    return 42;
}

/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x)
{
    return 42;
}

/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y)
{
    return 42;
}

/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x)
{
    return 42;
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x)
{
    return 42;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x)
{
    return 42;
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    return 42;
}

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x)
{
    return 42;
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x)
{
    return 42;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x)
{
    return 42;
}

/*
 * leftBitCount - returns count of number of consective 1's in
 *                left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x)
{
    return 42;
}

/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
    return 42;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *                Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n)
{
    return 42;
}

/*
 * maximumOfTwo - compute the maximum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int maximumOfTwo(int x, int y)
{
    return 42;
}

/*
 * minimumOfTwo - compute the minimum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int minimumOfTwo(int x, int y)
{
    return 42;
}

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    return 42;
}

/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *                   Should exactly duplicate effect of C expression (x*5/8),
 *                   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x)
{
    return 42;
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return 42;
}

/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void)
{
    return 42;
}

/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *                   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15, 2) = 3, remainderPower2(-35, 3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n)
{
    return 42;
}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *                      Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678, 1, 0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
    return 42;
}

/*
 * rotateLeft - Rotate x to the left by n
 *              Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n)
{
    return 42;
}

/*
 * rotateRight - Rotate x to the right by n
 *               Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n)
{
    return 42;
}

/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000, 0x40000000) = 0x7fffffff
 *             satAdd(0x80000000, 0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
    return 42;
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x)
{
    return 42;
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *   Examples: satMul3(0x10000000) = 0x30000000
 *             satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *             satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *              satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *             satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int satMul3(int x)
{
    return 42;
}

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *   Examples: sign(130) = 1
 *             sign(-23) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int sign(int x)
{
    return 42;
}

/*
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *                    where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x)
{
    return 42;
}

/*
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void)
{
    return 42;
}

/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000, 0x80000000) = 1,
 *            subtractionOK(0x80000000, 0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y)
{
    return 42;
}

/*
 * thirdBits - return word with every third bit (starting from the LSB)
 *             set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void)
{
    return 42;
}

/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    return 42;
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return 42;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *                   avoiding errors due to overflow
 *   Examples: trueFiveEighths(11) = 6
 *             trueFiveEighths(-9) = -5
 *             trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 4
 */
int trueFiveEighths(int x)
{
    return 42;
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *                    avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    return 42;
}

/*
 * twosComp2SignMag - Convert from two's complement to sign-magnitude
 *                    where the MSB is the sign bit
 *                    You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x)
{
    return 42;
}

/*
 * upperBits - pads n upper bits with 1's
 *             You may assume 0 <= n <= 32
 *   Example: upperBits(4) = 0xF0000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */
int upperBits(int n)
{
    return 42;
}
