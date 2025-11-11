/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:34:35 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/11 18:57:07 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_sleep(t_philo *philo)
{
	ft_print_action(philo, "is sleeping");
	usleep(philo->rules->time_to_sleep * 1000);
}

static void	ft_think(t_philo *philo)
{
	ft_print_action(philo, "is thinking");
	usleep(200);
}

void	ft_eat(t_philo *philo)
{
	if (philo->rules->num_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			usleep(500);
	}
	else
	{
		if (philo->id % 2 != 0)
			usleep(1000);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a right fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a left fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a left fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a right fork");
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_print_action(philo, "is eating");
	usleep(philo->rules->time_to_eat * 1000);
	philo->eat_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);

	while (1)
	{
		pthread_mutex_lock(&philo->rules->dead_mutex);
		if (philo->rules->dead)
		{
			pthread_mutex_unlock(&philo->rules->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->dead_mutex);

		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
