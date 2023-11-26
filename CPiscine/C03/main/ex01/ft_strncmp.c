/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 04:34:35 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/28 10:51:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while ((*(s1 + index) != '\0') && (index < n))
	{
		if (*(s1 + index) > *(s2 + index) || *(s1 + index) < *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		index++;
	}
	if (*(s1 + index) == '\0' && (index < n))
		return (*(s1 + index) - *(s2 + index));
	return (0);
}
