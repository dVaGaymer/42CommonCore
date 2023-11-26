/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 04:26:08 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 21:46:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

static void check(int x, int y);

int	main()
{
	void	*p, *a,  *b, *c;
	int		verga = 0, bueno = 0;

	p = malloc(1);
	a = malloc(1);
	b = malloc(1);
	c = malloc(1);

	printf("\033[1;33m------PENE--------------S--------------------\n\033[1;0m");

	printf(".s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%.s_HOLA\n", "reverga");
	verga =		ft_printf("VERGA: _HOLA_%.s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("5s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%5s_HOLA\n", "reverga");
	verga =		ft_printf("VERGA: _HOLA_%5s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("15s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%15s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%15s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-5s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%-5s_HOLA\n", "reverga");
	verga =		ft_printf("VERGA: _HOLA_%-5s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".5s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%.5s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%.5s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".5s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%.5s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%.5s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("15.3 | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%15.3s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%15.3s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-15.3s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%-15.3s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%-15.3s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-5.3s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%-5.3s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%-5.3s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2.3s | reverga\n");
	bueno =    printf(    "BUENO: _HOLA_%2.3s_HOLA\n", "reverga");
 	verga =		ft_printf("VERGA: _HOLA_%2.3s_HOLA\n", "reverga");
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2.3s | NULL\n");
	bueno =    printf(    "BUENO: _HOLA_%2.3s_HOLA\n", NULL);
 	verga =		ft_printf("VERGA: _HOLA_%2.3s_HOLA\n", NULL);
	check(bueno, verga);
	write(1, "\n", 1);


	printf("\033[1;33m--------------------C--------------------\n\033[1;0m");

	printf("2c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%2c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%2c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-23c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%-23c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%-23c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("5c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%5c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%5c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-23c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%-23c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%-23c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-23c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%-23c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%-23c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("07c | 100\n");
	bueno =    printf(    "BUENO: _HOLA_%07c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%07c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("20c | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%20c_HOLA\n", 100);
 	verga =		ft_printf("VERGA: _HOLA_%20c_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("c | NULL\n");
	bueno =    printf(	  "BUENO: _HOLA_%c_HOLA\n", NULL);
 	verga =		ft_printf("VERGA: _HOLA_%c_HOLA\n", NULL);
	check(bueno, verga);
	write(1, "\n", 1);



	printf("\033[1;33m--------------------DIU--------------------\n\033[1;0m");

	printf("5.10 | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%*.*d_HOLA\n", 5, 10, 100);
	verga =    ft_printf( "VERGA: _HOLA_%*.*d_HOLA\n", 5, 10, 100);
	check(bueno, verga);
	write(1, "\n", 1);
	
	printf("3d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%3d_HOLA\n", 100);
	verga =    printf(	  "VERGA: _HOLA_%3d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%2d_HOLA\n", 100);
	verga =    ft_printf(	  "VERGA: _HOLA_%2d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".5d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%.5d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%.5d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".3d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%.3d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%.3d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".2d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%.2d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%.2d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2.5d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%2.5d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%2.5d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2.3d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%2.3d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%2.3d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("2.2d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%2.2d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%2.2d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("3.5d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%3.5d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%3.5d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("3.3d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%3.3d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%3.3d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("3.5d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%3.5d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%3.5d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("5.7d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%5.7d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%5.7d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-5.3d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%-5.3d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%-5.3d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("-5.5d | 100\n");
	bueno =    printf(	  "BUENO: _HOLA_%-5.5d_HOLA\n", 100);
	verga =    ft_printf( "VERGA: _HOLA_%-5.5d_HOLA\n", 100);
	check(bueno, verga);
	write(1, "\n", 1);
	
	printf("50.0d | 0\n");
	bueno =    printf(	  "BUENO: _HOLA_%50.0d_HOLA\n", 0);
	verga =    ft_printf( "VERGA: _HOLA_%50.0d_HOLA\n", 0);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("05d | 5\n");
	bueno =    printf(	  "BUENO: _HOLA_%05d_HOLA\n", 5);
	verga =    ft_printf( "VERGA: _HOLA_%05d_HOLA\n", 5);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("05d | -5\n");
	bueno =    printf(	  "BUENO: _HOLA_%05d_HOLA\n", -5);
	verga =    ft_printf( "VERGA: _HOLA_%05d_HOLA\n", -5);
	check(bueno, verga);
	write(1, "\n", 1);

	printf(".5d | -5\n");
	bueno =    printf(	  "BUENO: _HOLA_%.5d_HOLA\n", -5);
	verga =    ft_printf( "VERGA: _HOLA_%.5d_HOLA\n", -5);
	check(bueno, verga);
	write(1, "\n", 1);


	printf("\033[1;33m--------------------P--------------------\n\033[1;0m");

	bueno =    printf(	  "BUENO: _HOLA_%p_HOLA\n", 456);
	verga =    ft_printf( "VERGA: _HOLA_%p_HOLA\n", 456);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%15.18p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%15.18p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%12p_HOLA\n", 789);
	verga =    ft_printf( "VERGA: _HOLA_%12p_HOLA\n", 789);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%.28p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%.28p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%.10p_HOLA\n", 1234);
	verga =    ft_printf( "VERGA: _HOLA_%.10p_HOLA\n", 1234);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%.12p_HOLA\n", a);
	verga =    ft_printf( "VERGA: _HOLA_%.12p_HOLA\n", a);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%2.15p_HOLA\n", b);
	verga =    ft_printf( "VERGA: _HOLA_%2.15p_HOLA\n", b);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%12.3p_HOLA\n", c);
	verga =    ft_printf( "VERGA: _HOLA_%12.3p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%12.12p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%12.12p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%13.5p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%13.5p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%13.13p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%13.13p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%3.15p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%3.15p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%15.7p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%15.7p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%-5.13p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%-5.13p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%-15.5p_HOLA\n", p);
	verga =    ft_printf( "VERGA: _HOLA_%-15.5p_HOLA\n", p);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%9.2p_HOLA\n", 1234);
	verga =    ft_printf( "VERGA: _HOLA_%9.2p_HOLA\n", 1234);
	check(bueno, verga);
	write(1, "\n", 1);

	bueno =    printf(	  "BUENO: _HOLA_%9.2p_HOLA\n", 1234);
	verga =    ft_printf( "VERGA: _HOLA_%9.2p_HOLA\n", 1234);
	check(bueno, verga);
	write(1, "\n", 1);

	printf("_%d_", printf("%42lc", '"'));
}

static void	check(int x, int y)
{
	if (x == y)
		printf("\033[1;32m---OK---\n\033[1;0m");
	else
		printf("\033[1;31m---KO---\n\033[1;0m");

}
