/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:59:21 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/30 23:35:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	**arg_ptr;
	int		index;

	index = 0;
	arg_ptr = argv + 1;
	while (*arg_ptr != 0 && argc != 0)
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
