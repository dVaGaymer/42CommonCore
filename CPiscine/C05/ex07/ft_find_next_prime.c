/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:04:15 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/01 01:30:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	int index;

	index = 3;
	if (nb % 2 == 0)
		return (0);
	while (index < nb / 2)
	{
		if (nb % index == 0)
			return (0);
		index += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (is_prime(nb))
		return (nb);
	while (!(is_prime(nb + 1)))
		nb++;
	return (nb + 1);
}
