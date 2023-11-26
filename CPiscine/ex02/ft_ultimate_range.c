/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 04:17:43 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/02 04:48:43 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_length;

	if (max > min)
		range_length = max - min;
	else
		return (-1);
	*range = (int *)malloc(sizeof(int *) * range_length);
	return (0);
}
