/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 05:56:38 by alopez-g          #+#    #+#             */
/*   Updated: 2019/11/28 04:04:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int cnt;
	int current_check;
	int aux;

	current_check = 0;
	cnt = 0;
	while (current_check < size)
	{
		while (cnt < size)
		{
			if (*(tab + current_check) > *(tab + cnt))
			{
				aux = *(tab + current_check);
				*(tab + current_check) = *(tab + cnt);
				*(tab + cnt) = aux;
			}
			cnt++;
		}
		cnt = ++current_check;
	}
}

int main()
{
	int h[] = {2,3,4,5,1,9,0};
	ft_sort_int_tab(h, 7);
	printf("%d%d%d%d%d%d%d", h[0],h[1],h[2],h[3],h[4],h[5],h[6]);
}
