/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:40:31 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/29 12:46:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strlen(char *str);

int	main()
{
	char a[] = "0123456djkaskbbfla789";
#ifdef yo
	printf("|%d|", ft_strlen(a));
#endif
#ifdef test
	printf("|%lu|", strlen(a));
#endif

}
