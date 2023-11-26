/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:54:06 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 19:59:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	space(int num, int zero, t_info *si)
{
	int		aux;
	char	c;

	if (num <= 0)
		return;
	aux = -1;
	c = 32;
	if (zero)
		c = 48;
	while (++aux < num)
		si->t += write(1, &c, 1);
}
