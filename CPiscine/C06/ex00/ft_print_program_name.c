/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:50:17 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/30 23:30:24 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char *arg_ptr;
	char nl;

	nl = 10;
	arg_ptr = argv[0] + 2;
	while (*arg_ptr != '\0' && argc == 1)
		write(1, arg_ptr++, 1);
	write(1, &nl, 1);
}
