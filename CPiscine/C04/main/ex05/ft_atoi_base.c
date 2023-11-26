/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:36:45 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 13:12:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_valid(char *tab, int base);
int	string_to_num(char *tab, char *base, int num, int base_num);
int	in_base(char *tab, char c);

int	ft_atoi_base(char *str, char *base)
{
	int num;
	int sign;
	int base_num;

	num = 0;
	sign = 1;
	base_num = 0;
	while (*(base + base_num) != '\0')
		base_num++;
	while (*str == 32 || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str != 43 && *str != 45 && !(in_base(base, *str)))
		return (0);
	while (*str == 43 || *str == 45)
		sign = (*str++ == 45) ? sign * -1 : sign;
	return (string_to_num(str, base, num, base_num) * sign);
}

int	check_valid(char *tab, int base)
{
	int aux;
	int aux_base;

	aux_base = base;
	if (base <= 1)
		return (0);
	while (aux_base > 0)
	{
		if (*(tab + aux_base) == 43 || *(tab + aux_base) == 45)
			return (0);
		aux_base--;
	}
	while (base > 0)
	{
		aux = base - 1;
		while (aux >= 0)
			if (*(tab + base) == *(tab + aux--))
				return (0);
		base--;
	}
	return (1);
}

int	string_to_num(char *tab, char *base, int num, int base_num)
{
	int j;

	while (*tab != '\0' && in_base(base, *tab))
	{
		j = 0;
		while (*(base + j) != '\0' && check_valid(base, base_num))
		{
			num = (*tab == *(base + j)) ? (num * base_num) + j : num;
			j++;
		}
		tab++;
	}
	return (num);
}

int	in_base(char *tab, char c)
{
	while (*tab != '\0')
	{
		if (c == *tab)
			return (1);
		tab++;
	}
	return (0);
}
