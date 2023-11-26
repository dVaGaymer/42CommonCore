/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:50:47 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 04:41:31 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	str_to_hex(char *str, int n);
void	num_to_hex(int c);
void	print_dir(void *dir);
void	print_str(char	*dir, int n);

void	ft_print_memory(void *addr, unsigned int size)
{//imprima solo size caracteres && direcciones de memoria
	int i;
	int p_dir;
	
	i = 0;
	while (i < (size - 16))
	{
			//write(1, "(Hex_Dir): ", 11);
		print_dir(addr + i);
		str_to_hex((addr + i), 16);
		write(1, "\n", 1);
		i = i + 16;
	}
	write(1, "(Hex_Dir): ", 11);
	str_to_hex(addr + i, size - i);
	write(1, "\n", 1);
}

void	num_to_hex(int c) //up to 255
{
	char dig_1;
	char dig_2;

	dig_1 = ((c / 16) % 16);
	dig_2 = (c % 16);
	if (dig_1 > 9)
		dig_1 = 97 + (dig_1 - 10);
	else
		dig_1 = 48 + dig_1;
	if (dig_2 > 9)
		dig_2 = 97 + (dig_2 - 10);
	else
		dig_2 = 48 + dig_2;
	write(1, &dig_1, 1);
	write(1, &dig_2, 1);
}

void	str_to_hex(char *str, int n)
{
	int i;
	int j;

	i = 0;
	while ((*(str + i) != '\0') && (i < n))
	{
		j = 0;
		while (j < 2)
		{
			num_to_hex(*(str + i));
			i++;
			j++;
		}
		write(1, " ", 1);
	}
	print_str(str, n);
}

void	print_str(char *dir, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		if (*(dir + i) < 32 || *(dir + i) > 126)
			write(1, ".", 1);
		else
			write(1, (dir + i), 1);
		i++;
	}
}


void	print_dir(void *dir)
{
	int int_dir;

	int_dir = (int) dir;
	printf(" %d %p", int_dir, dir);
}

int main(void)
{
	char a[] = "hola adios xd me lla da dng\nadw cr sajdjjg hola kaka dlao alvaro";
	ft_print_memory(a, 28);
}
