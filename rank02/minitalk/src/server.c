/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:23:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/10 03:43:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "common.h"
#include "msg.h"

char	g_recieved = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_recieved = (g_recieved << 1) | 1;
	if (sig == SIGUSR2)
		g_recieved = g_recieved << 1;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
}

int	next_int(int pid)
{
	int	cpid;

	cpid = 0;
	next_char(pid);
	cpid = cpid | ((unsigned char)g_recieved << 24);
	next_char(pid);
	cpid = cpid | ((unsigned char)g_recieved << 16);
	next_char(pid);
	cpid = cpid | ((unsigned char)g_recieved << 8);
	next_char(pid);
	cpid = cpid | ((unsigned char)g_recieved << 0);
	return (cpid);
}

int	setup_reception(int *cpid, int *len, char **str)
{
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	ft_putstr("\033[0;36mWaiting...\033[0m\n");
	if (next_char(0) == 10)
		return (10);
	*cpid = next_int(0);
	*len = next_int(0);
	if (*cpid < 0 || *cpid > 99999 || *len < 0)
		return (0);
	*str = malloc(sizeof(char) * *len + 1);
	*(*str + *len) = 0;
	ft_putstr("\033[1;32mClient connected: \033[0m");
	return (1);
}

void	msg_reception(char *str, int cpid, int len, int c)
{
	int	e;

	if (c == 10)
		return ;
	e = 1;
	if (cpid < 0 || cpid > 99999 || len != -1 || !c || g_recieved == 0)
	{
		while (e)
			e = sleep(2);
		ft_putstr("\033[0;31mUnexpected client error \033[0m\n");
	}
	else
	{
		ft_putstr(str);
		ft_putstr("\n");
		kill(cpid, SIGUSR2);
	}
	if (str)
		free(str);
	g_recieved = 0;
}

int	main(void)
{
	int		cpid;
	char	*str;
	int		cnt;
	int		len;
	char	c;

	c = 0;
	ft_putstr("\e[48;5;33m-----PID: ");
	ft_putnbr((int)getpid());
	ft_putstr("-----\e[0m\n");
	while (c != 10)
	{
		cnt = 0;
		str = NULL;
		c = setup_reception(&cpid, &len, &str);
		while (c && g_recieved != -1 && g_recieved != 0 && len-- >= 0)
		{
			c = next_char(cpid);
			if (g_recieved != -1)
				*(str + cnt++) = g_recieved;
		}
		msg_reception(str, cpid, len, c);
	}
	ft_putstr("\033[0;31mClient didn't connect.\033[0m\n");
	return (0);
}
