/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:48:50 by liferrei          #+#    #+#             */
/*   Updated: 2025/11/07 17:50:10 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_rules
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_eat;
	int				dead;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}			t_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}					t_philo;

int		ft_parse_args(int argc, char **argv, t_rules *rules);
long	ft_atol(char *str);
int		ft_isnumber(char *str);
int		ft_print_error(t_rules *rules);
int		ft_init_rules(t_rules *rules);
t_philo	*ft_init_philos(t_rules *rules);
int		ft_create_threads(t_rules *rules, t_philo *philos);
void	ft_join_threads(t_rules *rules, t_philo *philos);
void	*ft_routine(void *arg);
void	ft_eat(t_philo *philo);
long	ft_get_time(void);
void	ft_print_action(t_philo *philo, char *txt);
void	ft_cleanup(t_rules *rules, t_philo *philos);

#endif