#include "main.h"

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int a;
	static char b[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, b, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		b[a++] = c;
	return (1);
}

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}