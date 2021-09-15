#include "palindrome.h"

/**
 * strrev - reverses a string
 *
 * @s: a fixed sized string to reverse
 */

void strrev(char s[])
{
	int i, j = strlen(s) - 1;
	char c;

	for (i = 0; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/**
 * lutoa - turns an unsigned long to string
 *
 * @n: an unsigned long
 * @s: a fixed sized string
 */

void lutoa(unsigned long n, char s[])
{
	int i = 0;

	for (i = 0; i < 19; i++)
	{
		if (n > 0)
			s[i] = (n % 10) + '0';
		else
			s[i] = '\0';
		n /= 10;
	}
	s[i] = '\0';

	strrev(s);
}

/**
 * is_palindrome - checks if n is a palindrome
 *
 * @n: an unsigned long to check
 *
 * Return: 1 if n is a palindrome, 0 if not
 */

int is_palindrome(unsigned long n)
{
	char num[19];
	size_t i, j;

	lutoa(n, num);
	j = strlen(num) - 1;

	for (i = 0; i < strlen(num) / 2; i++, j--)
		if (num[i] != num[j])
			return (0);

	return (1);
}
