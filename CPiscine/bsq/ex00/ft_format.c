/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:56:13 by vgarcia-          #+#    #+#             */
/*   Updated: 2019/12/04 23:17:03 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	*ft_format(char *file_name, int *format)
{
	char	*line;
	int		fd;
	int		cnt;

	cnt = -1;
	format = (int *)malloc(sizeof(int) * 4);
	line = (char *)malloc(sizeof(char));
	fd = open(file_name, O_RDONLY);
	while (*line != '\n')
	{
		read(fd, line, 1);
		cnt++;
	}
	close(fd);
	free(line);
	line = (char *)malloc(sizeof(char) * cnt);
	fd = open(file_name, O_RDONLY);
	read(fd, line, cnt);
	close(fd);
	*format = ft_atoi(line, cnt - 4);
	*(format + 1) = *(line + (cnt - 3));
	*(format + 2) = *(line + (cnt - 2));
	*(format + 3) = *(line + (cnt - 1));
	return (format);
}

int	ft_atoi(char *num, int size)
{
	int	cnt;
	int int_num;

	int_num = 0;
	cnt = 0;
	if (size == 0)
		return ((*num) - 48);
	while (cnt <= size)
	{
		int_num = (int_num * 10) + (*(num + cnt) - 48);
		cnt++;
	}
	return (int_num);
}
