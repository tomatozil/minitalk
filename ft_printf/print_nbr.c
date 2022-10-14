//
// Created by jiyun on 2022/07/20.
//
#include "ft_printf.h"

char    *check_base(char type)
{
	if (ft_strchr("udi", type))
		return ("0123456789");
	else if (ft_strchr("px", type))
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

void print_nbr_base(unsigned long nbr, char *base, int notation, int *print_byte)
{
	if (nbr / notation)
		print_nbr_base(nbr / notation, base, notation, print_byte);
	*print_byte += write(1, &(base[nbr % notation]), 1);
}

void    print_nbr(char type, unsigned long nbr, int *print_byte)
{
	char    *base;

	base = check_base(type);
	if (ft_strchr("di", type))
	{
		if ((int)nbr < 0)
		{
			*print_byte += write(1, "-", 1);
			nbr *= -1;
		}
	}
	else if (type == 'p')
		*print_byte += write(1, "0x", 2);
	print_nbr_base(nbr, base, ft_strlen(base), print_byte);
}