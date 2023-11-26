/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:17:32 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 16:30:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	put_nbr(size_t n, int bs_cnt, char *base, char **str);
int		check_repeated(char *tab, int cnt);

char	*ft_putnbr_base(size_t nbr, char *base)
{
	size_t	base_cnt;
	int		valid;
	char	*str;

	str = (char *)malloc(sizeof(char));
	valid = 1;
	base_cnt = 0;
	while (*(base + base_cnt) != '\0')
	{
		if (*(base + base_cnt) == 43 || *(base + base_cnt) == 45)
			valid = !valid;
		base_cnt++;
	}
	if (base_cnt > 1 && valid && check_repeated(base, base_cnt))
		put_nbr(nbr, base_cnt, base, &str);
	return (str);
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

void	put_nbr(size_t n, int bs_cnt, char *base, char **str)
{
	char	dig;
	long	num;
	char	*temp;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num >= bs_cnt)
		put_nbr(num / bs_cnt, bs_cnt, base, str);
	dig = *(base + num % bs_cnt);
	temp = *str;
	*str = ft_strjoin(*str, ft_chartostr(dig));
	if (temp)
		free(temp);
}
