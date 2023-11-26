/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:01:22 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 13:37:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned  int size);

int	main()
{
	char a[20] = "01234";
	char b[] = "56789012345";
	int n = 11;
#ifdef yo
	printf(" |yost: %d| ", ft_strlcat(a, b, n));
	write(1, a, 10);
#endif

#ifdef test
	printf(" |test: %lu | ", strlcat(a, b, n));
	write(1, a, 10);
#endif
}
