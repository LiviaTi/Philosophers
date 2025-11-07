/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 17:39:11 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo	*philos;
	int		i;

	i = 0;
	if (!ft_parse_args(argc, argv, &rules))
		return (1);
	if (ft_init_rules(&rules))
		return (1);
	philos = ft_init_philos(&rules);
	if (!philos)
		return (ft_print_error(&rules));
	rules.start_time = ft_get_time();
	while (i < rules.num_philos)
	{
		pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < rules.num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	ft_cleanup(&rules, philos);
	return (0);
}
