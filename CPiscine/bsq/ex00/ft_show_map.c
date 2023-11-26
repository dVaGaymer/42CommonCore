/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:50:50 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/04 23:27:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_show_map(char **map, int *sol, int *format)
{
	int i;
	int j;
	int aux;

	aux = *sol;
	*sol = *(sol + 1);
	*(sol + 1) = aux;
	(*(sol + 2))--;
	i = 0;
	while (*(map + i) != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '\n')
				map[i][j] = *(format + 1);
			if (map[i][j] == '0')
				map[i][j] = *(format + 2);
			if ((j <= *sol && j >= (*sol - *(sol + 2)))
					&& (i <= *(sol + 1) && i >= (*(sol + 1) - *(sol + 2))))
				write(1, (format + 3), 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		i++;
	}
}
