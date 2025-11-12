/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:46:10 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/10 19:36:49 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
		return (0);
	return (1);
}

static int	ft_validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || ft_atol(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_assign_rules(int argc, char **argv, t_rules *rules)
{
	rules->num_philos = ft_atol(argv[1]);
	rules->time_to_die = ft_atol(argv[2]);
	rules->time_to_eat = ft_atol(argv[3]);
	rules->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		rules->num_eat = ft_atol(argv[5]);
	else
		rules->num_eat = -1;
}

int	ft_parse_args(int argc, char **argv, t_rules *rules)
{
	if (!ft_check_argc(argc))
		return (ft_print_error(NULL));
	if (!ft_validate_args(argc, argv))
		return (ft_print_error(NULL));
	ft_assign_rules(argc, argv, rules);
	return (1);
}
