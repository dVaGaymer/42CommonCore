/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:03:53 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:27:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_util.h"

t_bool	is_redirect(char *s)
{
	return (is_drl(s) || is_drr(s) || is_rl(s) || is_rr(s));
}