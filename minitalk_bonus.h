/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:28:27 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/14 16:28:43 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define PID_MAX 100000

typedef struct s_info
{
	pid_t	pid;
	char	*str;
}	t_info;

#endif
