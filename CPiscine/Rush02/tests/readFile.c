/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:21:42 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/30 16:45:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int fd;
	int dic_size;
	char *c;
	int sz;

	dic_size = 2;
	c = (char*)malloc(dic_size*sizeof(char));
	fd = open("hola.txt", O_RDONLY);
	if (fd < 0)
		write(1, "error", 5);
	read(fd, c, dic_size);
	while (*(c + dic_size - 2) != '\0')
	{
		free(c);
		dic_size++;
		c = (char*)malloc(dic_size*sizeof(char));
		sz = read(fd, c, dic_size);
		write(1, c, sz);
	}
	printf("%d", dic_size);
}
