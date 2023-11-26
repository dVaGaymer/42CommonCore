/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:28:55 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/20 13:28:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int aux;
	int cnt;
	int total_size;

	cnt = 0;
	total_size = size;
	while (size >= total_size / 2 + 1)
	{
		aux = *(tab + cnt);
		*(tab + cnt) = *(tab + size - 1);
		*(tab + size - 1) = aux;
		cnt++;
		size--;
	}
}
