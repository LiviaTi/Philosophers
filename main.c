/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:49 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/04 16:19:42 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;

	if (!parse_args(argc, argv, &rules))
		return (1);
	
	printf("✅ Arguments OK!\n");
	printf("Number of philosophers: %d\n", rules.num_philos);
	printf("Time to die: %ld\n", rules.time_to_die);
	printf("Time to eat: %ld\n", rules.time_to_eat);
	printf("Time to sleep: %ld\n", rules.time_to_sleep);

	if (rules.num_eat == -1)
		printf("Number of times each philosopher must eat: (no limit)\n");
	else
		printf("Number of times each philosopher must eat: %d\n", rules.num_eat);

	return (0);
}

