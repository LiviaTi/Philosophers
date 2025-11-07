/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:02:30 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 17:40:12 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init_rules(t_rules *rules)
{
	int	i;

	i = 0;
	rules->dead = 0;
	rules->start_time = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->num_philos);
	if (!rules->forks)
		return (ft_print_error(rules));
	while (i < rules->num_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (ft_print_error(rules));
		i++;
	}
	if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
		return (ft_print_error(rules));
	return (1);
}
