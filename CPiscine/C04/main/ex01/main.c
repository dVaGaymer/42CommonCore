/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 08:01:18 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 12:47:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_putstr(char *str);

int	main()
{
	char a[] = "012345";

#ifdef yo
	ft_putstr(a);
#endif
}