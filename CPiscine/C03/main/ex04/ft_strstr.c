/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 06:12:28 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/28 06:29:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = str;
	if (*to_find == 0)
		return (ptr);
	while (*(str + i) != '\0')
	{
		j = 0;
		if (*(str + i) == *(to_find + j))
		{
			while ((*(str + i + j) == *(to_find + j)) && (*(str + i + j) != 0))
				j++;
			if (*(to_find + j) == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
