//
// Created by jiyun on 2022/07/20.
//
#include "ft_printf.h"

void    print_char(char c, int *print_byte)
{
	*print_byte += write(1, &c, 1);
}