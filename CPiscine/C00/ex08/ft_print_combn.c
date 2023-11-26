/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:16:13 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/20 13:07:48 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show_list(int a[], int size);
void	add_to_list(int a[], int n, int x);

void	ft_print_combn(int n)
{
	int digits[n];
	int index;

	index = 0;
	while (index < n)
	{
		digits[index] = index;
		index++;
	}
	show_list(digits, n);
	while (digits[0] != (10 - n))
	{
		add_to_list(digits, n - 1, 9);
		show_list(digits, n);
		if (digits[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
	}
}

void	add_to_list(int a[], int n, int x)
{
	if (a[n] == x)
	{
		add_to_list(a, n - 1, x - 1);
		a[n] = a[n - 1] + 1;
	}
	else
	{
		a[n]++;
	}
}

void	show_list(int a[], int size)
{
	int		index;
	char	digit;

	index = 0;
	while (index < size)
	{
		digit = 48 + a[index];
		write(1, &digit, 1);
		index++;
	}
}
