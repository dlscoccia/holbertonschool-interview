#include "palindrome.h"
/**
* is_palindrome - detects if an int if a palindrome number
* @n: int value
* Return: return 1 if n is a palindrome, and 0 otherwise
**/

int is_palindrome(unsigned long n)
{
int reversedN = 0, remainder, originalN = n;

/* reversed integer is stored in reversedN */
while (n != 0)
{
remainder = n % 10;
reversedN = reversedN * 10 + remainder;
n /= 10;
}

/* check if orignalN and reversedN are equal */
if (originalN == reversedN)
return (1);
else
return (0);
}
