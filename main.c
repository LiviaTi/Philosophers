/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/11 16:26:51 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor_thread;
	int			i;

	philos = NULL;
	i = 0;
	if (!ft_parse_args(argc, argv, &rules))
		return (1);
	if (!ft_init_rules(&rules))
	{
		ft_cleanup(&rules, philos);
		return (1);
	}
	rules.start_time = ft_get_time();
	philos = ft_init_philos(&rules);
	if (!philos)
	{
		ft_print_error(&rules);
		ft_cleanup(&rules, philos);
		return (1);
	}
	while (i < rules.num_philos)
	{
		philos[i].last_meal = rules.start_time;
		i++;
	}
	rules.philos = philos;
	if (!ft_create_threads(&rules, philos))
	{
		ft_print_error(&rules);
		ft_cleanup(&rules, philos);
		return (1);
	}
	usleep(500);
	if (pthread_create(&monitor_thread, NULL, ft_monitor, &rules) != 0)
	{
		ft_print_error(&rules);
		ft_cleanup(&rules, philos);
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	ft_join_threads(&rules, philos);
	ft_cleanup(&rules, philos);
	return (0);
}

