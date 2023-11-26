/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:54:40 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/10 07:27:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "msg.h"

void	char_confirm(int sig)
{
	signal(sig, char_confirm);
	usleep(125);
}

void	msg_confirm(int sig)
{
	ft_putstr("\e[1;32mServer recieved your message!!\e[0m\n");
	signal(sig, msg_confirm);
	exit(0);
}

void	send_int(int spid, int cpid)
{
	iterate_bin(spid, (char)((cpid >> 24) & 0xFF));
	iterate_bin(spid, (char)((cpid >> 16) & 0xFF));
	iterate_bin(spid, (char)((cpid >> 8) & 0xFF));
	iterate_bin(spid, (char)((cpid >> 0) & 0xFF));
}

int	main(int argc, char **argv)
{
	pid_t	spid;
	pid_t	cpid;

	cpid = getpid();
	if (argc != 3 || **(argv + 2) == 0 || **(argv + 1) == 0)
	{
		ft_putstr("usage: client server_pid string_to_send \n");
		return (1);
	}
	signal(SIGUSR2, msg_confirm);
	signal(SIGUSR1, char_confirm);
	spid = (pid_t)ft_atoi(*(argv + 1));
	if (spid <= 0 || spid > 99999)
	{
		ft_putstr("Invalid server PID\n");
		return (1);
	}
	iterate_bin(spid, 0);
	send_int(spid, cpid);
	send_int(spid, ft_strlen(*(argv + 2)));
	msg_signaler(spid, *(argv + 2));
	iterate_bin(spid, -1);
	usleep(100000);
	ft_putstr("\e[38;31mServer probably didn't recieve your message\e[0m\n");
	return (0);
}
