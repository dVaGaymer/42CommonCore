/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 02:11:31 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/01 00:13:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ascii_sort(char *s1, char *s2);
void	print_params(char **argv);

int		main(int argc, char **argv)
{
	char	*aux;
	int		i;
	int		j;

	j = 1;
	i = 1;
	while (i < argc - 1)
	{
		while (j < argc)
		{
			if (ascii_sort(*(argv + i), *(argv + j)) > 0)
			{
				aux = argv[j];
				argv[j] = argv[i];
				argv[i] = aux;
			}
			j++;
		}
		j = ++i;
	}
	print_params(argv);
}

int		ascii_sort(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (*(s1 + index) != '\0')
	{
		if (*(s1 + index) != *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		index++;
	}
	return (0);
}

void	print_params(char **argv)
{
	char	**arg_ptr;
	int		index;

	index = 0;
	arg_ptr = argv + 1;
	while (*arg_ptr != 0)
	{
		while (*(*arg_ptr + index) != 0)
		{
			write(1, (*arg_ptr + index), 1);
			index++;
		}
		index = 0;
		write(1, "\n", 1);
		arg_ptr++;
	}
}
