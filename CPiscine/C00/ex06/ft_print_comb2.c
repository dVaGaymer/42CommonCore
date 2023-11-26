/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:08:22 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/27 05:48:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;
	char	num_to_print[5];

	num1 = 0;
	num2 = 1;
	num_to_print[2] = ' ';
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			num_to_print[0] = 48 + (num1 / 10);
			num_to_print[1] = 48 + (num1 % 10);
			num_to_print[3] = 48 + (num2 / 10);
			num_to_print[4] = 48 + (num2 % 10);
			write(1, &num_to_print, 5);
			if (num1 != 98)
				write(1, ", ", 2);
			num2++;
		}
		num1++;
		num2 = num1 + 1;
	}
}

int	main()
{
	ft_print_comb2();
}
