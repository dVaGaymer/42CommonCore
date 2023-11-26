/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 05:28:45 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 20:19:43 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int	get_num(const char *start, t_info *si);


/*
**	Check flags 
**
*/
void	init_flag_struct(const char *pos, t_flags *sf, t_info *si)
{
	int	aux;

	aux = 0;
	while (ft_strchr(si->flags, *(pos + aux)))
	{
		if ((!(sf->width) && *(pos + aux) > 48 && *(pos + aux) <= 57 && sf->prc == -1))
			sf->width = get_num(pos + aux, si);
		else if (*(pos + aux) == *(si->flags))
			sf->neg = 1;
		else if (*(pos + aux) == *(si->flags + 1) && !(sf->width))
			sf->zero = 1;
		else if (sf->prc == -1 && *(pos + aux) == *(si->flags + 2))
		{
			sf->prc = 0;
			if (*(pos + aux + 1) >= 48 && *(pos + aux) <=57)
				sf->prc = get_num(pos + aux + 1, si);
		}
		aux++;
	}
	si->i = aux ? si->i + aux + 1: si->i + 1;
	if (sf->neg && sf->zero)
		sf->zero = 0;
}

static int	get_num(const char *start, t_info *si)
{
	int	aux;
	int	num;
	
	aux = 0;
	num = 0;
	while (*(start + aux) >= 48 && *(start + aux) <= 57)
	{
		num = num * 10 + (*(start + aux) - 48);
		aux++;
	}
	//si->i += aux;
	return (num);
}
