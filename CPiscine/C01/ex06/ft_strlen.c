/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:11:51 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/20 13:27:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str != '\0')
	{
		str++;
		cnt++;
	}
	return (cnt);
}
