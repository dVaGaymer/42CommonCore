/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:54:14 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 13:57:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main()
{
	char a[10] = "dasdasdasd";
	char b[] = "d";
#ifdef yo
	printf("yost: %s | ", ft_strncat(a, b, 0));
#endif
#ifdef test
	printf("test: %s | ", strncat(a, b, 0));
#endif
}
