/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:46:00 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 17:36:41 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_print_error(t_rules *rules)
{
	int	i;

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

void	ft_cleanup(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	if (rules->forks)
	{
		while (i < rules->num_philos)
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

long	ft_get_time(void)
{
	struct timeval	current_time;
	long			time_ms;

	time_ms = 0;
	gettimeofday(&current_time, NULL);
	time_ms = ((long)current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time_ms);
}

void	ft_print_action(t_philo *philo, char *txt)
{
	long	time;

	time = 0;
	pthread_mutex_lock(&philo->rules->print_mutex);
	time = ft_get_time() - philo->rules->start_time;
	printf("%ld %d %s\n", time, philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}

