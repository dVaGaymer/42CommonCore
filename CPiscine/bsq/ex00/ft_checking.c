/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:06:38 by vgarcia-          #+#    #+#             */
/*   Updated: 2019/12/04 23:15:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_check_map(char *i_map, char vac, char obs)
{
	int		i;
	int		rowlen;
	int		rowlen_f;

	i = 0;
	rowlen = 0;
	rowlen_f = 0;
	while (i_map[rowlen_f] != '\n')
		rowlen_f++;
	while (i_map[i] != '\0')
	{
		if (i_map[i] != vac && i_map[i] != obs && i_map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_checking(char *file_name)
{
	char	*ctr_l;
	int		len;
	int		i;

	if (*file_name == '\0')
		return (0);
	len = 0;
	ctr_l = open_file(file_name);
	while (ctr_l[len] != '\n')
		len++;
	i = 0;
	while (i < len)
	{
		if (ctr_l[i] < ' ' || ctr_l[i] > '~')
			return (0);
		if (i < (len - 4) && (ctr_l[i] < '0' || ctr_l[i] > '9'))
			return (0);
		i++;
	}
	if (ctr_l[len - 3] == ctr_l[len - 2] || ctr_l[len - 3] == ctr_l[len - 1]
			|| ctr_l[len - 2] == ctr_l[len - 1])
		return (0);
	if (ft_check_map(ctr_l + len + 1, ctr_l[len - 3], ctr_l[len - 2]) == 0)
		return (0);
	return (1);
}

char	*open_file(char *file_name)
{
	char	*buffer;
	int		fd;
	int		cnt;

	cnt = 0;
	buffer = (char *)malloc(sizeof(char) + 1);
	fd = open(file_name, O_RDONLY);
	while (read(fd, buffer, 1))
		cnt++;
	close(fd);
	free(buffer);
	buffer = (char *)malloc(sizeof(char) * cnt + 1);
	fd = open(file_name, O_RDONLY);
	read(fd, buffer, cnt);
	close(fd);
	return (buffer);
}
