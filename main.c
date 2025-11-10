/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:34:53 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo	*philos;

	if (!ft_parse_args(argc, argv, &rules))
		return (1);
	if (!ft_init_rules(&rules))
		return (1);
	philos = ft_init_philos(&rules);
	if (!philos)
		return (ft_print_error(&rules));
	rules.start_time = ft_get_time();
	if (!ft_create_threads(&rules, philos))
	{
		return (ft_print_error(&rules));
		return (1);
	}
	ft_join_threads(&rules, philos);
	ft_cleanup(&rules, philos);
	return (0);
}
