/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 23:32:33 by alopez-g          #+#    #+#             */
/*   Updated: 2019/12/04 23:34:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FUNCTIONS_H
# define FUNCTIONS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_checking(char *file_name);
int		*ft_format(char *file_name, int *format);
int		ft_atoi(char *num, int size);
void	ft_load_map(char **map, int *format, char *file_name);
void	ft_show_map(char **map, int *sol, int *format);
int		*ft_solve_map(char **map, int *format);
int		ft_check_map(char *i_map, char vac, char obs);
int		ft_checking(char *file_name);
char	*open_file(char *file_name);
#endif
