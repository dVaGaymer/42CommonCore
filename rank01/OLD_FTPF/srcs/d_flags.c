/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 02:05:58 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 21:49:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char	*apply_d_flags(char *str, const char *pos, t_info *si, t_flags *sf)
{
	int	pr;
	int	len;
	int	t;

	init_flag_struct(pos, sf, si);
	pr = (sf->prc == -1) ? 0 : sf->prc;
	len = *str == '-' ? ft_strlen(str) - 1 : ft_strlen(str);
	t = (pr > len) ? pr : len;
	if (!sf->neg && *str == '-')
		write(1, str, 1);
	if (!sf->neg)
		space(sf->width - t, sf->zero, si);
	space(t - len, 1, si);
	if (!sf->neg && *str == '-')
		ft_putstr_fd((*(str) == 48) && !sf->prc ? " " : str + 1, 1);
	else
		ft_putstr_fd((*(str) == 48) && !sf->prc ? " " : str, 1);
	if (sf->neg)
		space(sf->width - t, 0, si);
	si->t = *str == '-' ? si->t + len + 1 : si->t + len;
	return (str);
}
