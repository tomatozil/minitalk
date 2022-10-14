//
// Created by jiyun on 2022/07/20.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void    print_char(char c, int *print_byte);
void    print_str(char *s, int *print_byte);
void    print_nbr(char type, unsigned long nbr, int *print_type);
int     ft_printf(const char *format, ... );

#endif
