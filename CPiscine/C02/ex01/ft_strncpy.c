/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:33:22 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/26 11:22:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (cnt < n)
	{
		*(dest + i) = '\0';
		i++;
		cnt++;
	}
	return ((dest + i - 1));
}

int main()
{
	char s[] = "hola_adios";
	char d[20]; 
	ft_strncpy(d, s, 4);
	printf("%s", d);
}
