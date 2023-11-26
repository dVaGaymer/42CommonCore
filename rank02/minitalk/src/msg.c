/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:34:45 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/10 03:39:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "common.h"
#include "msg.h"

void	msg_signaler(pid_t spid, char *msg)
{
	while (*msg)
	{
		iterate_bin(spid, *msg);
		msg++;
	}
}

void	iterate_bin(pid_t spid, char c)
{
	char	cnt;

	cnt = 8;
	while (cnt >= 0)
	{
		if (c & 1 << cnt)
			kill(spid, SIGUSR1);
		else
			kill(spid, SIGUSR2);
		cnt--;
		usleep(500);
	}
}

char	next_char(int cpid)
{
	char	num;
	char	c;

	c = 1;
	num = 0;
	if (!cpid)
	{
		while (num++ <= 8)
		{
			if (!sleep(30))
				return (10);
		}
	}
	else
	{
		while (num++ <= 8 && c)
		{
			c = sleep(2);
			kill(cpid, SIGUSR1);
		}
	}	
	return (c);
}
