/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:17:03 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 16:23:35 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	client_handler(int sig)
{
	static int	index;
	static int	push = 7;

	if (sig == SIGUSR2)
	{
		ft_printf("sent well. SUCCESS!");
		exit(0);
	}
	else
	{
		if (g_info.str[index] >> push & 1)
			kill(g_info.pid, SIGUSR1);
		else
			kill(g_info.pid, SIGUSR2);
		push--;
		if (push == -1)
		{
			push = 7;
			index++;
		}
	}
}

int	ft_atoi(const char *str)
{
	int		cnt;
	int		sign;
	long	ret;

	cnt = 0;
	sign = 1;
	ret = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		cnt++;
		str++;
		if ((cnt > 19 && sign == -1) || (ret < 0 && sign == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((cnt > 19 && sign == 1) || (ret < 0 && sign == 1))
			return ((int)9223372036854775807);
	}
	return ((int)ret * sign);
}

int	main(int ac, char **av)
{

	if (ac != 3)
	{
		ft_printf("Write again. Correct format: [PID] [MESSAGE]\n");
		return (1);
	}
	g_info.pid = ft_atoi(av[1]);
	if (g_info.pid > PID_MAX)
	{
		ft_printf("Wrong PID value. Bye\n");
		return (1);
	}
	g_info.str = av[2];
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	kill(g_info.pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}
