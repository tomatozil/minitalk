/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:25:08 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 17:25:14 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *s, int *print_byte)
{
	if (!s)
		*print_byte += write(1, "(null)", 6);
	else
		*print_byte += write(1, s, ft_strlen(s));
}
