/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:48:51 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/04 23:24:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_load_map(char **map, int *format, char *file_name)
{
	char	*buff;
	int		fd;
	int		cnt;
	int		aux;

	aux = 0;
	cnt = 0;
	buff = (char *)malloc(sizeof(char));
	fd = open(file_name, O_RDONLY);
	while (*buff != '\n')
		read(fd, buff, 1);
	read(fd, buff, 1);
	while (*buff != '\n')
		read(fd, buff, 1 + (0 * cnt++));
	free(buff);
	close(fd);
	while (aux < *format)
		*(map + aux++) = (char *)malloc(sizeof(char) * cnt + 1);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, 1);
	aux = 0;
	while (*buff != '\n')
		read(fd, buff, 1);
	while (aux++ < *format)
		read(fd, *(map++), cnt + 1);
	close(fd);
}
