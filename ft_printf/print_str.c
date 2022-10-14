//
// Created by jiyun on 2022/07/20.
//
#include "ft_printf.h"

void    print_str(char *s, int *print_byte)
{
	if (!s)
		*print_byte += write(1, "(null)", 6);
	else
		*print_byte += write(1, s, ft_strlen(s));
}