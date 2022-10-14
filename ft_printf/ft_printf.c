//
// Created by jiyun on 2022/07/19.
//
#include "ft_printf.h"

int is_valid_format(const char *format)
{
	if (!format)
		return (0);
	while(*format)
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

void    convert_to(char type, va_list arg_ptr, int *print_byte)
{
	if (type == 'c')
		print_char(va_arg(arg_ptr, int), print_byte);
	else if (type == 's')
		print_str(va_arg(arg_ptr, char *), print_byte);
	else if (type == 'p')
		print_nbr(type, va_arg(arg_ptr, uintptr_t), print_byte);
	else if (type == '%')
		print_char('%', print_byte);
	else if (ft_strchr("di", type)) // 부호 있는 정수
		print_nbr(type, va_arg(arg_ptr, int), print_byte);
	else if (ft_strchr("uxX", type)) // 부호 없는 정수(10진법 혹은 16진법)
		print_nbr(type, va_arg(arg_ptr, unsigned int), print_byte);
}

int ft_printf(const char *format, ... )
{
	va_list arg_ptr;
	int     print_byte;

	/* 유효성 검사
	 * 1. NULL인지
	 * 2. %가 있다면, 그 뒤에 붙는 서식 지정자가 cspdiuxX 중에 있는지
	 */
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
		else /* 그냥 출력해야 할 문자열일 때 */
		{
			print_char(*format, &print_byte);
		}
		format++;
	}
	va_end(arg_ptr);
	return (print_byte);
}