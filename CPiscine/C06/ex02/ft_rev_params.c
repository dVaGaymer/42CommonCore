/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_rev_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 01:46:53 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/30 23:54:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		index;
	char	**arg_ptr;

	while (argc > 1)
	{
		index = 0;
		arg_ptr = argv + argc - 1;
		while (*(*arg_ptr + index) != 0)
		{
			write(1, (*arg_ptr + index), 1);
			index++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
