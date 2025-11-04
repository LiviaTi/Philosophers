/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:48:50 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/04 16:30:17 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>

typedef struct s_rules
{
	int		num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_eat;
}			t_rules;

long	ft_atol(char *str);
int		ft_print_error(void);
int		ft_isnumber(char *str);
int		ft_parse_args(int argc, char **argv, t_rules *rules);

#endif