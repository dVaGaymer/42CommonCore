/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:28:43 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/25 06:07:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_str_is_alpha(char *str)
{	//devuelve 1 si cadena vacia
	while (*str != '\0')
	{
		if (!((*str >= 97 && *str <= 122) || (*str >= 65 && *str <= 90)))
			return (0);
		str++;
	}
	return(1); 
}

int main()
{
	char x[] = "";
	printf("%d",ft_str_is_alpha(x));
}
