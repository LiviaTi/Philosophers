/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:46:00 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:32:26 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	num;
	int		i;
	long	sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long	ft_get_time(void)
{
	struct timeval	current_time;
	long			seconds_ms;
	long			microseconds_ms;
	long			total_time_ms;

	gettimeofday(&current_time, NULL);
	seconds_ms = (long)current_time.tv_sec * 1000;
	microseconds_ms = current_time.tv_usec / 1000;
	total_time_ms = seconds_ms + microseconds_ms;
	return (total_time_ms);
}

void	ft_print_action(t_philo *philo, char *txt)
{
	long	time;

	time = 0;
	pthread_mutex_lock(&philo->rules->print_mutex);
	time = ft_get_time() - philo->rules->start_time;
	if (!philo->rules->dead)
		printf("[%ld ms] Philosopher %d %s\n", time, philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
