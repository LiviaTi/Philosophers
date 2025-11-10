/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:34:35 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:36:29 by liferrei         ###   ########.fr       */
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
	usleep(100);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_print_action(philo, "has taken a fork");
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ft_print_action(philo, "has taken a fork");
	ft_print_action(philo, "is eating");
	philo->last_meal = ft_get_time();
	usleep(philo->rules->time_to_eat * 1000);
	philo->eat_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->rules->dead)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
