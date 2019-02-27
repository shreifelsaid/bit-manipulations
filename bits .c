/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
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

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

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
3. Has unpredictable behavior when shifting an integer by more
than the word size.

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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
    the coding rules are less strict.  You are allowed to use looping and
    conditional control.  You are allowed to use both ints and unsigneds.
    You can use arbitrary integer and unsigned constants.

    You are expressly forbidden to:
    1. Define or use any macros.
    2. Define any additional functions in this file.
    3. Call any functions.
    4. Use any form of casting.
    5. Use any data type other than int or unsigned.  This means that you
    cannot use arrays, structs, or unions.
    6. Use any floating point data types, operations, or constants.


    NOTES:
    1. Use the dlc (data lab checker) compiler (described in the handout) to 
	check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
	that you are allowed to use for your implementation of the function. 
	The max operator count is checked by dlc. Note that '=' is not 
	counted; you may use as many of these as you want without penalty.
	3. Use the btest test harness to check your functions for correctness.
	4. Use the BDD checker to formally verify your functions
	5. The maximum number of ops for each function is given in the
	header comment for each function. If there are any inconsistencies 
	between the maximum ops in the writeup and in this file, consider
	this file the authoritative source.

	/*
	 * STEP 2: Modify the following functions according the coding rules.
	 * 
	 *   IMPORTANT. TO AVOID GRADING SURPRISES:
	 *   1. Use the dlc compiler to check that your solutions conform
	 *      to the coding rules.
	 *   2. Use the BDD checker to formally verify that your solutions produce 
	 *      the correct answers.
	 */


#endif
	/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.

	   The GNU C Library is free software; you can redistribute it and/or
	   modify it under the terms of the GNU Lesser General Public
	   License as published by the Free Software Foundation; either
	   version 2.1 of the License, or (at your option) any later version.

	   The GNU C Library is distributed in the hope that it will be useful,
	   but WITHOUT ANY WARRANTY; without even the implied warranty of
	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	   Lesser General Public License for more details.

	   You should have received a copy of the GNU Lesser General Public
	   License along with the GNU C Library; if not, see
	   <http://www.gnu.org/licenses/>.  */
	/* This header is separate from features.h so that the compiler can
	   +1   include it implicitly at the start of every compilation.  It must
	   not itself include <features.h> or any other header that includes
	   <features.h> because the implicit include comes before any feature
	   test macros that may be defined in a source file before it first
	   explicitly includes a system header.  GCC knows the name of this
	   header in order to preinclude it.  */
	/* We do support the IEC 559 math functionality, real and complex.  */
	/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
	   Unicode 6.0.  */
	/* We do not support C11 <threads.h>.  */
	/* 
	 * bitXor - x^y using only ~ and & 
	 *   Example: bitXor(4, 5) = 1
	 *   Legal ops: ~ &
	 *   Max ops: 14
	 *   Rating: 1
	 */
	int bitXor(int x, int y) {


		int a = ~(x&y);
		int b = ~(x&a);
		int c = ~(y&a);
		int d = ~(b&c);
		return d;
	}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {

	int x = 0xAA;
	int y = ((x<<16)|((x<<8)|(x)));
	return (y<<16)|y;


}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
	int a =((x)&(0x000000FF))    <<24;
	int b =((x>>8)&(0x000000FF))<<16;
	int c =((x>>16)&(0x000000FF))<<8;
	int d =(x>>24)&(0x000000FF);
	//reversing bytes using different masks
	return (a|b|c|d) ;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {

	int mask = ~(((0x1 << 31)>>n)<<1);
	int a = mask&(x>>n);
	int b = x << (32+(~n+1));
	return (a|b);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) { 
	
	int a = (((0x55)<<8)|(0x55))<<16;
	int aa = a | a >> 16;
	int b = (((0x33)<<8)|(0x33))<<16;
	int bb = b | b >> 16;
	int c = (((0x0f)<<8)|(0x0f))<<16;
	int cc = c | c >> 16;
	int d = ((0xff)<<16)|(0xff);
	int e = ((0xff)<<8)|(0xff);
	//this is a standard hamming weight algorithm. works by adding every two bits together, then every four .. and so on. Adopted from the book Hacker's Delight.
	x = (x & aa ) + ((x >>  1) & aa ); //value of 2 bit sum into 32 bits
	x = (x & bb ) + ((x >>  2) & bb ); //value of 4 bit sum into 16 bits
	x = (x & cc ) + ((x >>  4) & cc ); //value of 8 bit sum into 8 bits
	x = (x & d ) + ((x >>  8) & d );   //value of 16 bit sum into 4 bits
	x = (x & e ) + ((x >>  16) & e ); //value of 32 bit sum into 2 bits
	return x;

}
/*
 *
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	int max = ~(1<<31);
	return max;
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
	int a=x>>31;
	int b=y>>31;
	int overFlow =x+y;
	int overFlowSign = overFlow>>31;
	//checks if overflow occured by comparing overflow sign and the signs of x and y
	return!!(a^b)|(!(b^overFlowSign));
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int rempwr2(int x, int n) {

	int pwr = 1<<n;
	int signOfx = x >> 31;
	int result = x & (pwr + ~0);
	int divisable = ~(!!result	+0) + 1; //if result = 0, we get 0, if result anything else we get 0xFFFFFFFFE
	return divisable&((x & (pwr + ~0)) + ((signOfx) & (~(1 << n)+1)));
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0xe0000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	int Tmin = (1<<31);
	int x2 = x+x;
	int signX = x>>31; //checks the sign of x. -1 if negative, 0 if positive.
	int mostSignificantBit = (x<<1)>>31; //the most significant bit of x (either 0 or -1);
	int signOverflow = (x2)>>31; //checks the sign of the multiplication of x by. -1 if negative, 0 if positive.
	int a = (signX^signOverflow); //evaluates to 0 if they sign of overflow and of X are the same, -1 otherwise (signX = ~signOverFlow);
	int result = (x2) + (a & ((mostSignificantBit^Tmin)+(~(x2)+1)));
	return result;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	int diff = y + (~x +1); //if y is greater or equal, the differnece is +ve or 0, else it is negative.
	int sameBits = (y^x); //checks for zero or 1; 1 if they are different, 0 if they are the same
	//algorithm used is a standard comparison predicate algorithm adopted from the book Hacker's Delight and edited to fit our purpose
	return (((diff)^(sameBits&(diff ^ y)))>>31)&(0x1);
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
	//first we multiply by 5
	int multiFive = (x<<2 ) +x;
	int result = multiFive & (8 + ~0);
	int signX = x>>31;
	//divide by 8
	int divEight = multiFive >> 3;
	//rounding in case of negative input
	return divEight + ((signX)&(!!result) ) ;     
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
	int zeroCheck = ((~x + 1)>>31)&1; //this variable would be (00000) if x is postive, (0000) if x is zero, and (11111) if x is negative;
	int signX = (x>>31)&1;  //this is the sign of x, if its negative then x is non zero by def.	      
	return signX |(signX^zeroCheck) ;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	
	int frac = uf & (0x007FFFFF);
	int exp =  (uf & (0x7F800000))>>23;
	//if the number is negative and not a NaN
	if ((uf>>31) && (((exp != 0xff)||(frac==0)))){
		return (uf<<1)>>1;
	}
	else {
		return uf;
	}

}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	//variables representing the unbiased exponent, the fraction, and the sign.
	int exp =  (uf & (0x7F800000))>>23;
	int frac = (uf & (0x007FFFFF))|(0x00800000);
	int exponent = (exp-127);
	unsigned sign = uf >> 31;
	//working around edge cases such as NaN and infinity
	if(exp == 0xff ){
		return 0x80000000u;
	}
	if(exponent < 0){//working around a range of exponent values as to not cause overflow
		return 0;
	}
	if(exponent <= 23){
		int result = (frac >> (23-exponent));
		if(sign){
			return -result;
		}
		return result;
	}
	if(exponent <=31) {
		int result = frac << (exponent-23);

		if(sign){
			return -result;
		}
		return result;
	}
	else {
		if(sign){ //if sign is negative
			return -2147483648;
		}
		else {
			return 2147483648;
		}
	}

}

/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

unsigned float_half(unsigned uf) {
	int exp =  (uf & (0x7F800000))>>23;
	int frac = (uf & (0x007FFFFF));
	int noExp =(uf & (0x807FFFFF));
	unsigned sign = uf >> 31;
	int firstAnswer = ((frac>>1)|(sign<<31));
	int secondAnswer = firstAnswer + 1;
	int thirdAnswer = noExp+((exp-1)<<23);
	int fourthAnswer = ((uf&0x7FFFFFFF)>>1)|(sign<<31);
	int condition1 = ((frac>>1)%2 == 1);
	int expConditon = (exp == 0);
	int fracCondition = (frac & 1);
	//the code here attempts to work around edge cases, such as when 
	//the biased exponent = 0, and how to round to the nearst even number. 
	//If there is no edge cases, the code simply returns f with 1 subtracted from its exponent
	if ((uf) == 0)
	{
		return 0;
	}
	if((exp == 0xff)||((expConditon)&(frac == 0)))
	{
		return uf;
	}
	if (exp == 1)
	{
		if(condition1 && fracCondition)
		{
			return fourthAnswer+1;
		}
		else
		{
			return fourthAnswer;
		}
	}
	if ((fracCondition) && (expConditon))
	{
		if(condition1)
		{
			return secondAnswer;
		}
		else
		{
			return firstAnswer;
		}
	}
	if (expConditon){
		return firstAnswer;
	}
	return thirdAnswer;
}
