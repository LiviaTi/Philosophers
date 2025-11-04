/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:46:10 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/04 19:19:56 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

int	parse_args(int argc, char **argv, t_rules *rules)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ft_print_error(NULL));
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (ft_print_error(NULL));
		if (ft_atol(argv[i]) <= 0)
			return (ft_print_error(NULL));
		i++;
	}
	rules->num_philos = ft_atol(argv[1]);
	rules->time_to_die = ft_atol(argv[2]);
	rules->time_to_eat = ft_atol(argv[3]);
	rules->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		rules->num_eat = ft_atol(argv[5]);
	else
		rules->num_eat = -1;
	return (1);
}
