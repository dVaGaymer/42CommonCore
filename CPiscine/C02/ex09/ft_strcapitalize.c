/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:54:29 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 07:09:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	char *ptr;

	ptr = str;
	while (*str != '\0')
	{
		if ((*str >= 97 && *str <= 122) 
				&& (((*(str - 1) <= 64 || *(str - 1) >= 123) 
						|| (*(str - 1) >= 91 && *(str - 1) <= 96)) 
					&& !(*(str - 1) >= 48 && *(str - 1) <= 57)))
			*str = *str - 32;
		str++;
	}
	return (ptr);
}

int main()
{
	char c[] = "k dad afdskf fds.,..344f d89 89dasd da2j-ds/das";
	ft_strcapitalize(c);
	write(1, c, 46);
}
