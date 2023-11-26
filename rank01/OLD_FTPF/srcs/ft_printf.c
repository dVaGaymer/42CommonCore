/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 00:41:39 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 20:50:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int		ft_printf(const char *in, ...)
{
	va_list	lst;
	va_list	cp_lst;
	t_info si;
	t_flags sf;
	
	init_info(&si);
	va_start(si.ap, in);
	while(*(in + si.i))
	{
		if (*(in + si.i) == 37)
			find_mod(in + si.i + 1, lst, &si, &sf);
		else
		{
			si.t++;
			write(1, in + si.i, 1);
		}
		si.i++;
	}
	va_end(lst);
	va_end(cp_lst);
	return (si.t);
}

void	init_info(t_info *si)
{
	si->i = 0;
	si->t = 0;
	si->flags = "-0.*123456789";
	si->mods = "cspdiuxX";
}
