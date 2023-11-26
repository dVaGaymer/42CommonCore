/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:57:46 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/27 05:47:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int digit_1;
	int digit_2;
	int digit_3;

	digit_1 = 48;
	digit_2 = digit_1 + 1;
	digit_3 = digit_2 + 1;
	while (digit_1 <= 55)
	{
		while (digit_2 <= 56)
		{
			while (digit_3 <= 57)
			{
				write(1, &digit_1, 1);
				write(1, &digit_2, 1);
				write(1, &digit_3, 1);
				write(1, ", ", 2);
				digit_3++;
			}
			digit_3 = ++digit_2;
		}
		digit_2 = ++digit_1;
		digit_3 = ++digit_2;
	}
}

int main()
{
	ft_print_comb();
}
