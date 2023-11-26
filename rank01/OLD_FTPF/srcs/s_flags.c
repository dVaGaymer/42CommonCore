/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 03:33:35 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 21:02:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char	*apply_s_flags(char *str, const char *pos, t_info *si, t_flags *sf)
{
	init_flag_struct(pos, sf, si);
	if (!sf->prc)
		str = "";
	if (sf->prc)
		str = ft_substr(str, 0, sf->prc);
	if (sf->neg)
		ft_putstr_fd(str, 1);
	space(sf->width - ft_strlen(str), sf->zero, si);
	if (!sf->neg)
		ft_putstr_fd(str,  1);
	si->t += ft_strlen(str);
	return (str);
}
