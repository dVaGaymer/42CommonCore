/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:26:41 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/19 20:03:07 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		digit_number(long nb);
void		print_tab(char tab[], int size);

void	ft_putnbr(int nb)
{
	long	nbl;
	long	number;
	int		digits;
	long	aux;
	char	char_digits[digit_number(nb)];

	nbl = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nbl = nbl * -1;
	}
	digits = digit_number(nbl) - 1;
	number = nbl;
	aux = number;
	while (digits >= 0)
	{
		number = aux % 10;
		aux = aux / 10;
		char_digits[digits] = 48 + number;
		digits--;
	}
	print_tab(char_digits, digit_number(nbl));
}

void	print_tab(char tab[], int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		write(1, tab + index, 1);
		index++;
	}
}

int		digit_number(long nb)
{
	int aux;
	int counter;
	int number;

	if (nb < 0)
		nb = nb * -1;
	number = nb;
	counter = 0;
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int		main(void)
{
	ft_putnbr(-2147483648);
}
