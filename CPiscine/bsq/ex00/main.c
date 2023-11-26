/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:48:38 by vgarcia-          #+#    #+#             */
/*   Updated: 2019/12/04 23:31:27 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		main(int argc, char **argv)
{
	char	**map;
	int		*format;
	int		*sol;

	sol = (int *)malloc(sizeof(int) * 3 + 1);
	format = (int *)malloc(sizeof(int) * 4 + 1);
	argv++;
	while (argc > 0)
	{
		while (!(ft_checking(*argv)) && argc > 1)
		{
			write(1, "map error", 9);
			argc--;
			argv++;
		}
		if (argc == 1)
			return (0);
		format = ft_format(*argv, format);
		map = (char **)malloc(sizeof(char *) * (*format) + 1);
		ft_load_map(map, format, *argv);
		sol = ft_solve_map(map, format);
		ft_show_map(map, sol, format);
		argc--;
		argv++;
	}
}
