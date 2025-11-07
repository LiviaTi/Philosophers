/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:23 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 15:29:23 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philos(t_rules *rules)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * rules->num_philos);
	if (!philos)
		return (NULL);
	while (i < rules->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].last_meal = 0;
		philos[i].rules = rules;
		philos[i].left_fork = &rules->forks[i];
		if (i == rules->num_philos - 1)
			philos[i].right_fork = &rules->forks[0];
		else
			philos[i].right_fork = &rules->forks[i + 1];
		i++;
	}
	return (philos);
}
