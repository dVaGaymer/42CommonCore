/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:03:10 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 20:55:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/*
**	check modifier and calls its flag applier
**	TODO change pos with modifier finder
*/

static void	zero_init_flags(t_flags *sf);

void	find_mod(const char *pos, va_list ap, t_info *si, t_flags *sf)
{
	char	*str;

	zero_init_flags(sf);
	if (mod_finder(pos, si, sf) == 'c')
		apply_c_flags((unsigned char)va_arg(si->ap, int), pos, si, sf);	
	else if (mod_finder(pos,  si, sf) == 's')
	{
		str = va_arg(si->ap, char *);
		if (!str)
			str = ("(null)");
		apply_s_flags(str, pos, si, sf);	
	}
	else if (mod_finder(pos, si, sf) == 'd' || mod_finder(pos, si, sf) == 'i')
		apply_d_flags(ft_itoa(va_arg(si->ap, int)), pos, si, sf);	
	else if (mod_finder(pos, si, sf) == 'u')
		apply_d_flags(ft_itoa((unsigned int)va_arg(si->ap, int)), pos, si, sf);	
	else if (mod_finder(pos, si, sf) == 'p')
		//apply p flags
		ft_putnbr_base((size_t)va_arg(si->ap, size_t), "0123456789abcdef");
	else if (mod_finder(pos, si, sf) == 'x')
		//apply p flags
		ft_putnbr_base(va_arg(si->ap, int), "0123456789abcdef");
	else if (mod_finder(pos, si, sf) == 'X')
		//apply p flags
		ft_putnbr_base(va_arg(si->ap, int), "0123456789ABCDEF");
}

/*
**	ignores flags until modifier found and returns it
*/
char	mod_finder(const char *pos, t_info *sinfo, t_flags *sflags)
{
	int	aux;

	aux = 0;
	while (ft_strchr(sinfo->flags, *(pos + aux)))
	{
		if (!(sflags->width) && sflags->prc == -1 && *(pos + aux) == 42)
			sflags->width = va_arg(sinfo->ap, int);
		else if (sflags->prc == -1 && *(pos + aux) == *(sinfo->flags + 2)
				&& *(pos + aux + 1) == 42)
				sflags->prc = va_arg(sinfo->ap, int);
		aux++;
	}
	if (ft_strchr(sinfo->mods, *(pos + aux)))
		return (*(pos + aux));
	return (0);
}

/*
**	converts char to 1-len string
*/
char	*ft_chartostr(unsigned char c)
{
	char	*str;

	str = (char *)malloc(sizeof(unsigned char) + 1);
	*str = c;
	*(str + 1) = 0;
	return (str);
}

static void	zero_init_flags(t_flags *sf)
{
	sf->neg = 0;
	sf->width = 0;
	sf->zero = 0;
	sf->prc = -1;
	sf->ptr = 0;
}
