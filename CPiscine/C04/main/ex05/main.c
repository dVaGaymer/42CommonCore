/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 08:45:16 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/01 00:29:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main()
{
	char a[] = " 	\t\r      --+-+--HHOLH ALO HA K k";
	char b[] = "HOLA";
	printf(" %d ", ft_atoi_base(a, b));
}
