/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:22:58 by vgarcia-          #+#    #+#             */
/*   Updated: 2019/12/04 23:41:03 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_min(char a, char b, char c)
{
	int		min;

	min = 0;
	if (a < b && a < c)
		min = a;
	else if (b < c)
		min = b;
	else
		min = c;
	return (min + 1);
}

int	*ft_solve_pos(char **map)
{
	int		*sol;
	int		x;
	int		y;

	sol = (int *)malloc(sizeof(int) * 3);
	sol[0] = 0;
	sol[1] = 0;
	sol[2] = map[0][0] - 48;
	y = 1;
	x = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '\n')
				map[y][x] = ft_min(map[y - 1][x], map[y][x - 1], map[y - 1][x - 1]);
			if (map[y][x] - 48 > sol[2])
			{
				sol[2] = map[y][x] - 48;
				sol[0] = y++;
				sol[1] = x++;
			}
			x++;
		}
		y++;
	}
	return (sol);
}

int	*ft_solve_map(char **map, int *format)
{
	int		x;
	int		y;

	y = 0;
	while (*(map + y) != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == (char)format[1])
				map[y][x] = '1';
			else if (map[y][x] == (char)format[2])
				map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (ft_solve_pos(map));
}
