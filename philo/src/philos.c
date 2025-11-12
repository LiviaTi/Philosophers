/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:23 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/11 19:19:01 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_init_philos(t_rules *rules)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * rules->num_philos);
	if (!philos)
		return (NULL);

	i = 0;
	while (i < rules->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].last_meal = rules->start_time;
		philos[i].rules = rules;
		philos[i].left_fork = &rules->forks[i];
		if (i == rules->num_philos - 1)
			philos[i].right_fork = &rules->forks[0];
		else
			philos[i].right_fork = &rules->forks[i + 1];
		if (pthread_mutex_init(&philos[i].meal_mutex, NULL) != 0)
		{
			int j = i - 1;
			while (j >= 0)
			{
				pthread_mutex_destroy(&philos[j].meal_mutex);
				j = j - 1;
			}
			free(philos);
			return (NULL);
		}
		i = i + 1;
	}
	return (philos);
}

int	ft_create_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]) != 0)
			return (0);
		usleep(100);
		i++;
	}
	return (1);
}

void	ft_join_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i = i + 1;
	}
}
