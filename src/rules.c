/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:02:30 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:29:23 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_destroy_forks(t_rules *rules, int last)
{
	while (last-- > 0)
		pthread_mutex_destroy(&rules->forks[last]);
	free(rules->forks);
	rules->forks = NULL;
	return (ft_print_error(rules));
}

static int	ft_init_forks(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->num_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (ft_destroy_forks(rules, i));
		i++;
	}
	return (1);
}

static int	ft_init_print_mutex(t_rules *rules)
{
	if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
		return (ft_destroy_forks(rules, rules->num_philos));
	return (1);
}

int	ft_init_rules(t_rules *rules)
{
	rules->dead = 0;
	rules->start_time = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->num_philos);
	if (!rules->forks)
		return (ft_print_error(rules));
	if (!ft_init_forks(rules))
		return (0);
	if (!ft_init_print_mutex(rules))
		return (0);
	return (1);
}

