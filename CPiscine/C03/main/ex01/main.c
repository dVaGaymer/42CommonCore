/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:41:57 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/28 10:52:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main()
{
	char a[] = "";
	char b[] = "adsdas";

#ifdef yo
	printf(" %d ", ft_strncmp(a, b, 5));
#endif
#ifdef test
	printf(" %d ", strncmp(a, b, 5));
#endif
}
