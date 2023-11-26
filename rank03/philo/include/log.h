/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:08:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 22:20:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "log.h"
# include "philo.h"
# include "philo_utils.h"

void	log_args_print(t_args philo);
void	log_state(t_args *args, t_philo *philo, t_philo_action action);

#endif
