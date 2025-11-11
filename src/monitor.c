/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:47:43 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/11 16:53:38 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


static int	ft_check_death(t_philo *philo)
{
	long	current_time;
	long	diff;

	pthread_mutex_lock(&philo->meal_mutex);
	current_time = ft_get_time();
	diff = current_time - philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mutex);

	if (diff > philo->rules->time_to_die)
	{
		pthread_mutex_lock(&philo->rules->dead_mutex);
		if (!philo->rules->dead)
		{
			philo->rules->dead = 1;
			pthread_mutex_unlock(&philo->rules->dead_mutex);
			pthread_mutex_lock(&philo->rules->print_mutex);
			printf("[%ld ms] Philosopher %d died\n",
				current_time - philo->rules->start_time, philo->id);
			pthread_mutex_unlock(&philo->rules->print_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->rules->dead_mutex);
	}
	return (0);
}

static int	ft_all_ate(t_rules *rules)
{
	int	i;

	if (rules->num_eat <= 0)
		return (0);
	i = 0;
	while (i < rules->num_philos)
	{
		if (rules->philos[i].eat_count < rules->num_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&rules->dead_mutex);
	rules->dead = 1;
	pthread_mutex_unlock(&rules->dead_mutex);
	pthread_mutex_lock(&rules->print_mutex);
	printf("All philosophers have eaten %d times. Simulation ended.\n",
		rules->num_eat);
	pthread_mutex_unlock(&rules->print_mutex);
	return (1);
}

void	*ft_monitor(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	while (1)
	{
		i = 0;
		while (i < rules->num_philos)
		{
			if (ft_check_death(&rules->philos[i]))
				return (NULL);
			i++;
		}
		if (ft_all_ate(rules))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}