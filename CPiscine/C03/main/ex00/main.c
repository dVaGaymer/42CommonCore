/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:37:24 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/28 10:41:39 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main()
{
	char a[] = "asd";
	char b[] = "asdJ";

#ifdef yo
	printf(" %d ", ft_strcmp(a, b));
#endif
#ifdef test
	printf(" %d ", strcmp(a, b));
#endif
}
