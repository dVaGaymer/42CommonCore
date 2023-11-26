/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:52:06 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 05:40:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char *ptr;

	ptr = str;
	while(*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			*str = *str + 32;
		str++;
	}
	return (ptr);
}

int	main(void)
{
	char b[] = "IKJjdkdalkjdLSKJdlk()/Dad284";
	write(1, ft_strlowcase(b), 50);
}
