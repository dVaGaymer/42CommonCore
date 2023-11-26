/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 05:24:18 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 20:16:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/*
**	Changes str to match flags
**	TODO use ptr -> fix in //flag_struct_utils.c
*/

void	apply_c_flags(char c, const char *pos, t_info *si, t_flags *sf)
{
	init_flag_struct(pos, sf, si);
	if (sf->neg)
		write(1, &c, 1);
	space(sf->width - 1, sf->zero, si);
	if (!sf->neg)
		write(1, &c, 1);
	si->t += 1;
}
