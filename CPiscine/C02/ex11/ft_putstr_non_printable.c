/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 01:18:05 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 07:13:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	char_to_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
			char_to_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}

void	char_to_hex(char c)
{
	char non_pr[3];
	non_pr[0] = 92;
	non_pr[1] = 48 + c / 16;
	if (c < 10)
		non_pr[2] = 48 + (c%16);
	else
		non_pr[2] = 97 + ((c % 16) - 10);
	write(1, non_pr, 3);
}

int	main()
{
	char c[] = "Co\\nuc\eou\ntu\n vas\tbienJA\aJAJAJA\eg?";
	ft_putstr_non_printable(c);
}
