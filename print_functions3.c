#include "main.h"

/**
 * print_o - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_o(va_list list)
{
    unsigned int num;
    int len;
    char *octal_rep, *rev_str;

    num = va_arg(list, unsigned int);

    if (num == 0)
        return (_putchar('0'));

    if (num < 1)
        return (-1);

    len = base_len(num, 8);
    octal_rep = malloc(sizeof(char) * len + 1);

    if (octal_rep == NULL)
        return (-1);

    for (len = 0; num > 0; len++)
    {
        octal_rep[len] = (num % 8) + 48;
        num = num / 8;
    }

    octal_rep[len] = '\0';
    rev_str = rev_string(octal_rep);

    if (rev_str == NULL)
    {
        free(octal_rep);
        return (-1);
    }

    write_base(rev_str);
    free(octal_rep);
    free(rev_str);

    return (len);
}

/**
 * print_x - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_x(va_list list)
{
    unsigned int num;
    int len, rem_num;
    char *hex_rep, *rev_hex;

    num = va_arg(list, unsigned int);

    if (num == 0)
        return (_putchar('0'));

    if (num < 1)
        return (-1);

    len = base_len(num, 16);
    hex_rep = malloc(sizeof(char) * len + 1);

    if (hex_rep == NULL)
        return (-1);

    for (len = 0; num > 0; len++)
    {
        rem_num = num % 16;
        if (rem_num > 9)
        {
            rem_num = hex_check(rem_num, 'x');
            hex_rep[len] = rem_num;
        }
        else
            hex_rep[len] = rem_num + 48;
        num = num / 16;
    }

    hex_rep[len] = '\0';
    rev_hex = rev_string(hex_rep);

    if (rev_hex == NULL)
    {
        free(hex_rep);
        return (-1);
    }

    write_base(rev_hex);
    free(hex_rep);
    free(rev_hex);

    return (len);
}

/**
 * print_X - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_X(va_list list)
{
unsigned int num;
    int len, rem_num;
    char *hex_rep, *rev_hex;

    num = va_arg(list, unsigned int);

    if (num == 0)
        return (_putchar('0'));

    if (num < 1)
        return (-1);

    len = base_len(num, 16);
    hex_rep = malloc(sizeof(char) * len + 1);

    if (hex_rep == NULL)
        return (-1);

    for (len = 0; num > 0; len++)
    {
        rem_num = num % 16;
        if (rem_num > 9)
        {
            rem_num = hex_check(rem_num, 'X');
            hex_rep[len] = rem_num;
        }
        else
            hex_rep[len] = rem_num + 48;
        num = num / 16;
    }

    hex_rep[len] = '\0';
    rev_hex = rev_string(hex_rep);

    if (rev_hex == NULL)
    {
        free(hex_rep);
        return (-1);
    }

    write_base(rev_hex);
    free(hex_rep);
    free(rev_hex);

    return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
    char *hex = "abcdef", *Hex = "ABCDEF";

    num = num - 10;

    if (x == 'x')
        return (hex[num]);
    else
        return (Hex[num]);

    return (0);
}
