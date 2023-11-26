/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:06:45 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/21 17:13:46 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_stronly(char *str, char *only)
{
	if (!str || !only)
		return (0);
	while (*str)
	{
		if (!ft_strchr(only, *str))
			return (0);
		str++;
	}
	return (1);
}
