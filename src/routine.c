/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:34:35 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 17:09:40 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_action(philo, "has taken a left fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print_action(philo, "has taken a right fork");
	print_action(philo, "is eating");
	philo->last_meal = get_time();
	usleep(philo->rules->time_to_eat * 1000);
	philo->eat_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
