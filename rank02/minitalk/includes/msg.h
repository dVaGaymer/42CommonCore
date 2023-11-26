/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:32:34 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/06 21:35:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

void	msg_signaler(pid_t spid, char *msg);
void	iterate_bin(pid_t spid, char c);
char	next_char(int cpid);

#endif
