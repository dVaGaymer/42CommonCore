/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:02:46 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 05:52:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int index;
	int src_len;
	
	src_len = 0;
	index = 0;
	while (*(src + index) != '\0' && size > 1)
	{
		*(dest + index) = *(src + index);
		size--;
		index++;
		src_len++;
	}
	if (size >= 1)
		*(dest + index) = '\0';
	return (src_len);
}

int main()
{
	char c[] = "hola";
	char x[10];

	ft_strlcpy(x, c, 4);
	write(1,&x, 4);
}

