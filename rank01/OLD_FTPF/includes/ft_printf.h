/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 03:56:27 by alopez-g          #+#    #+#             */
/*   Updated: 2020/02/29 20:50:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_flags
{
	int neg;
	int	width;
	int	zero;
	int	prc;
	int	ptr;
}				t_flags;
typedef struct	s_info
{
	int		i;
	int		t;
	char	*flags;
	char	*mods;
	va_list	ap;
	char	*str;
}				t_info;
int		ft_printf(const char *in, ...);
void	init_info(t_info *si);
void	find_mod(const char *pos, va_list ap, t_info *si, t_flags *sf);
char	mod_finder(const char *pos, t_info *sinfo, t_flags *flags);
char	*ft_chartostr(unsigned char c);
char	*ft_putnbr_base(size_t nbr, char *base);
int		check_repeated(char *tab, int cnt);
void	put_nbr(size_t n, int bs_cnt, char *base, char **str);

void	space(int num, int zero, t_info *si);

void	init_flag_struct(const char *pos, t_flags *sf, t_info *si);
void	apply_c_flags(char c, const char *pos, t_info *si, t_flags *sf);
char	*apply_s_flags(char *str, const char *pos, t_info *si, t_flags *sf);
char	*apply_d_flags(char *str, const char *pos, t_info *si, t_flags *sf);
char	*apply_p_flags(char *str, const char *pos, t_info *si, t_flags *sf);
