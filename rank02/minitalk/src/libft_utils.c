/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:45:15 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/04 19:59:31 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
}

void	ft_putnbr(pid_t num)
{
	long	aux;
	char	c;

	aux = (long)num;
	if (aux < 0)
	{
		aux *= -1;
		c = 45;
		write(1, &c, 1);
	}
	if (aux > 9)
		ft_putnbr(aux / 10);
	c = aux % 10 + 48;
	write(1, &c, 1);
}

int	ft_atoi(char *s_num)
{
	int	i_num;

	i_num = 0;
	while (*s_num)
	{
		i_num = i_num * 10 + (*s_num - 48);
		s_num++;
	}
	return (i_num);
}
