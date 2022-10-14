/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:25:34 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 17:25:48 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void	print_char(char c, int *print_byte);
void	print_str(char *s, int *print_byte);
void	print_nbr(char type, unsigned long nbr, int *print_type);
int		ft_printf(const char *format, ... );

#endif
