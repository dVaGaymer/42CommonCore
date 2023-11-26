/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:58:09 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 14:01:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main()
{
	char	dest[7] = "0123";
	char	src[] = "4567";
#ifdef yo
	printf("|%s|yo", ft_strcat(dest, src));
#endif
#ifdef test
	printf("|%s|test", strcat(dest, src));
#endif
}
