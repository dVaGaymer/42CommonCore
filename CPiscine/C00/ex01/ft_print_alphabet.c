/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:19:10 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/14 20:34:43 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		char_counter;

	char_counter = 97;
	while (char_counter <= 122)
	{
		write(1, &char_counter, 1);
		char_counter++;
	}
}
