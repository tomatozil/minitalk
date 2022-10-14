/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:22:24 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 18:05:34 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_format(const char *format)
{
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!ft_strchr("cspdiuxX%", *format))
				return (0);
		}
		format++;
	}
	return (1);
}

void	convert_to(char type, va_list arg_ptr, int *print_byte)
{
	if (type == 'c')
		print_char(va_arg(arg_ptr, int), print_byte);
	else if (type == 's')
		print_str(va_arg(arg_ptr, char *), print_byte);
	else if (type == 'p')
		print_nbr(type, va_arg(arg_ptr, uintptr_t), print_byte);
	else if (type == '%')
		print_char('%', print_byte);
	else if (ft_strchr("di", type))
		print_nbr(type, va_arg(arg_ptr, int), print_byte);
	else if (ft_strchr("uxX", type))
		print_nbr(type, va_arg(arg_ptr, unsigned int), print_byte);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		print_byte;

	if (!is_valid_format(format))
		return (-1);
	va_start(arg_ptr, format);
	print_byte = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			convert_to(*format, arg_ptr, &print_byte);
		}
		else
		{
			print_char(*format, &print_byte);
		}
		format++;
	}
	va_end(arg_ptr);
	return (print_byte);
}
