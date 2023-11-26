/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:37:50 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/01 01:27:08 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int cnt;

	cnt = 1;
	while (nb > 0)
		cnt = cnt * nb--;
	return (cnt);
}
