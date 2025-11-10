/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:47:43 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:52:03 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_death(t_philo *philo)
{
	long	current_time;

	current_time = ft_get_time();
	if ((current_time - philo->last_meal) > philo->rules->time_to_die)
	{
		pthread_mutex_lock(&philo->rules->print_mutex);
		if (!philo->rules->dead)
		{
			philo->rules->dead = 1;
			printf("[%ld ms] Philosopher %d died\n",
				current_time - philo->rules->start_time, philo->id);
		}
		pthread_mutex_unlock(&philo->rules->print_mutex);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	while (!rules->dead)
	{
		i = 0;
		while (i < rules->num_philos && !rules->dead)
		{
			if (ft_check_death(&rules->philos[i]))
				break;
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
