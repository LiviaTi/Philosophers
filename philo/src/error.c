/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:28 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/12 00:13:27 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_destroy_forks(t_rules *rules)
{
	int	i;

	if (!rules->forks)
		return ;
	i = 0;
	while (i < rules->num_philos)
		pthread_mutex_destroy(&rules->forks[i++]);
	free(rules->forks);
	rules->forks = NULL;
}

static void	ft_destroy_philo_mutexes(t_rules *rules, t_philo *philos)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (i < rules->num_philos)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(philos);
}

void	ft_cleanup(t_rules *rules, t_philo *philos)
{
	if (!rules)
		return ;
	ft_destroy_forks(rules);
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->dead_mutex);
	ft_destroy_philo_mutexes(rules, philos);
}

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
