/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:46:00 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:48 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_print_error(t_rules *rules)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	if (rules && rules->forks)
	{
		while (i < rules->num_philos)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;	
		}
		free (rules->forks);
		rules->forks = NULL;
		pthread_mutex_destroy(&rules->print_mutex);
	}
	return (0);
}

void	cleanup(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	if (rules->forks)
	{
		while (i < rules->num_eat)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;
		}
		free(rules->forks);
		rules->forks = NULL;
	}
	pthread_mutex_destroy(&rules->print_mutex);
	if (philos)
	{
		free(philos);
		philos = NULL;
	}
}
