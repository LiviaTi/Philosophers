/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:23 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/12 02:27:37 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_init_philo(t_philo *philo, int i, t_rules *rules)
{
	philo->id = i + 1;
	philo->eat_count = 0;
	philo->last_meal = rules->start_time;
	philo->rules = rules;
	philo->left_fork = &rules->forks[i];
	if (i == rules->num_philos - 1)
		philo->right_fork = &rules->forks[0];
	else
		philo->right_fork = &rules->forks[i + 1];
}

void	ft_destroy_mutexes(t_philo *philos, int i)
{
	int	j;

	j = i - 1;
	while (j >= 0)
	{
		pthread_mutex_destroy(&philos[j].meal_mutex);
		j--;
	}
}

t_philo	*ft_init_philos(t_rules *rules)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * rules->num_philos);
	if (!philos)
		return (NULL);
	while (i < rules->num_philos)
	{
		ft_init_philo(&philos[i], i, rules);
		if (pthread_mutex_init(&philos[i].meal_mutex, NULL) != 0)
		{
			ft_destroy_mutexes(philos, i);
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

int	ft_create_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL,
				ft_routine, &philos[i]) != 0)
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
