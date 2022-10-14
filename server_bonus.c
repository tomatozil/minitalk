/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:27:12 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 18:25:29 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
void init_talk(const siginfo_t *siginfo, pid_t *client_pid, \
		int *character)
{
	*client_pid = siginfo->si_pid;
	(*character)++;
	kill(*client_pid, SIGUSR1);
	return ;
}

void    server_handler(int sig, siginfo_t *siginfo, void *context)
{
	static pid_t    client_pid;
	static int  character = -1;
	static int  bits;

	(void)context;
	if (character == -1)
		return init_talk(siginfo, &client_pid, &character);
	character = character << 1 | (sig == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (character == (int) '\0')
		{
			kill(client_pid, SIGUSR2);
			character = -1;
		}
		else
		{
			write(1, &character, 1);
			character = 0;
		}
		bits = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig_struct;

	ft_printf("pid: %d\n", getpid());
	sig_struct.sa_flags = SA_SIGINFO;
	sig_struct.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &sig_struct, NULL);
	sigaction(SIGUSR2, &sig_struct, NULL);
	while (1)
		pause();
	return (0);
}
