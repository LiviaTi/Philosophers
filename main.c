/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/06 15:49:48 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo *philos;

	if (!parse_args(argc, argv, &rules))
		return (1);
	if (!init_rules(&rules))
		return(1);
	philos = init_philos(&rules);
	if (!philos)
		return (ft_print_error(&rules));
	printf("Número de filósofos: %d\n", rules.num_philos);
	printf("Tempo de morrer: %ld\n", rules.time_to_die);
	printf("Tempo de comer: %ld\n", rules.time_to_eat);
	printf("Tempo de dormir: %ld\n", rules.time_to_sleep);
	printf("Número de refeições: %d\n", rules.num_eat);
	cleanup(&rules, philos);
	return (0);
}

