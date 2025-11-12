/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/12 02:21:52 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static int	ft_setup_rules(int argc, char **argv, t_rules *rules)
{
	if (!ft_parse_args(argc, argv, rules))
		return (0);
	if (!ft_init_rules(rules))
		return (0);
	rules->start_time = ft_get_time();
	return (1);
}

static t_philo	*ft_setup_philos(t_rules *rules)
{
	t_philo	*philos;
	int		i;

	philos = ft_init_philos(rules);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < rules->num_philos)
		philos[i++].last_meal = rules->start_time;
	rules->philos = philos;
	return (philos);
}

int	ft_one_philo_case(t_rules *rules)
{
	printf("[0 ms] Philosopher 1 has taken a left fork\n");
	usleep(rules->time_to_die * 1000);
	printf("[%ld ms] Philosopher 1 died\n", rules->time_to_die);
	ft_cleanup(rules, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor;

	philos = NULL;
	if (!ft_setup_rules(argc, argv, &rules))
		return (1);
	if (rules.num_philos == 1)
		return (ft_one_philo_case(&rules));
	philos = ft_setup_philos(&rules);
	if (!philos || !ft_create_threads(&rules, philos)
		|| pthread_create(&monitor, NULL, ft_monitor, &rules) != 0)
	{
		ft_print_error(&rules);
		ft_cleanup(&rules, philos);
		return (1);
	}
	pthread_join(monitor, NULL);
	ft_join_threads(&rules, philos);
	ft_cleanup(&rules, philos);
	return (0);
}
