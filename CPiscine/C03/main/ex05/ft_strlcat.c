/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 06:13:45 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 13:37:28 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len;
	int	src_len;
	int	total_len;
	int	cnt;

	cnt = 0;
	dest_len = 0;
	while (*dest++ != '\0')
		dest_len++;
	src_len = 0;
	while (*(src + src_len) != '\0')
		src_len++;
	total_len = (dest_len > size) ? size + src_len : dest_len + src_len;
	if (dest_len < size)
	{
		while (cnt < ((size - dest_len)))
		{
			*(dest + cnt - 1) = *(src + cnt - 1);
			cnt++;
		}
		*(dest + cnt - 1) = '\0';
	}
	return (total_len);
}
