/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:34:14 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/24 04:49:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	*clue_list(char *str, int *clues);
int check_if_possible(int *clues);

int	main(int arg, char *args[])
{
	int final_matrix[16];
	int clues[16];

	clue_list(args[1], clues);
	if (!(check_if_possible(clues)))
		printf("Error");
}

//Use the input to create int unidimensional matrix
int *clue_list(char *str, int *clues)
{
	int index;
	int *ptr;

	ptr = clues;
	index = 0;
	while (index <= 15)
	{
		*(clues + index) = *str - 48;
	   	str = str + 2;
		index++;
	}
	return (ptr);
}

//Check if the input is possible
int	check_if_possible(int *clues)
{
	int aux;
	int index;
	
	index = 0;
	aux = 0;
	while(index < 16)
	{
		if ((index < 4) || (index > 6 && index < 11))
		{
			if ((*(clues + index) + *(clues + 4 + index) > 5) 
					|| (*(clues + index) + *(clues + 4 + index) < 3))
			{
				return (0);
			}
		}
		aux = aux + *(clues + index);
		index++;
	}
	if (aux > 36 || aux < 30)
	{
		return (0);
	}
	return (1);
}
