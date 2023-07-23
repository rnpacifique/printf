#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

// FLAGS
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

// SIZES
#define S_LONG 2
#define S_SHORT 1

/**
 * struct - struct operation by Pacifique and Jean Luc
 * @fmt: the format
 * @af: associated function.
 */
struct fmt
{
	char fmt; 
	int (*af)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_r - structs opearation
 *
 * @fmt: format
 * @fm_r: The associated function.
 */
typedef struct fmt fmt_r;

int _printf(const char *format, ...);
int handle_print(constant char *fmt, int *a, va_list arguments, char buffer[], int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* printing chars and strings */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* printing numbers */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size)
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size)
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char bufffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], flags, char flag_ch, int width, int precision, int size);


