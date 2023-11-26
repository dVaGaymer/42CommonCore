/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:48:07 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/23 11:39:59 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int	digit(int n)
{
	int	d;
	d = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

float	ft_atof(const char *str)
{
	float	num;
	float	dnum;
	int	sign;
	int	d;

	num = 0;
	dnum = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	str = *str == '.' ? str + 1 : str;
	if (ft_isdigit(*str))
		dnum = ft_atoi(str);;
	d = digit(dnum);
	while (d-- > 0)
		dnum = dnum / 10;
	return (sign * (num + dnum));
}
