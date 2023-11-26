/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 05:58:53 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 13:57:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = dest;
	while (*dest != '\0')
		dest++;
	while (*(src + i) != '\0' && nb > 0)
	{
		*(dest + i) = *(src + i);
		nb--;
		i++;
	}
	*(dest + i) = '\0';
	return (ptr);
}
