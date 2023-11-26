/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:17:32 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 12:52:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(int n, int bs_cnt, char *base);
int		check_repeated(char *tab, int cnt);

void	ft_putnbr_base(int nbr, char *base)
{
	int base_cnt;
	int valid;

	valid = 1;
	base_cnt = 0;
	while (*(base + base_cnt) != '\0')
	{
		if (*(base + base_cnt) == 43 || *(base + base_cnt) == 45)
			valid = !valid;
		base_cnt++;
	}
	if (base_cnt > 1 && valid && check_repeated(base, base_cnt))
		put_nbr(nbr, base_cnt, base);
}

int		check_repeated(char *tab, int cnt)
{
	int aux;

	while (cnt > 0)
	{
		aux = cnt - 1;
		while (aux >= 0)
		{
			if (*(tab + cnt) == *(tab + aux))
				return (0);
			aux--;
		}
		cnt--;
	}
	return (1);
}

void	put_nbr(int n, int bs_cnt, char *base)
{
	char dig;
	long num;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num >= bs_cnt)
		put_nbr(num / bs_cnt, bs_cnt, base);
	dig = *(base + num % bs_cnt);
	write(1, &dig, 1);
}
