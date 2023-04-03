/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:40:14 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/03 16:20:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define STD_ERROR 2
# define STR_INSTRUCTIONS "\nCorrect execution:\n\
./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n\n"
# define STR_INSTRUCTIONS_I 134
# include "libft.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <sys/time.h>

typedef struct s_rules
{
	int	num_philo;
	int	num_forks;
	int num_eat;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int time_start;
	int end;
}			t_rules;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	int				hunger;
	int				times_ate;
}			t_philo;

typedef struct s_var
{
	t_rules	rules;
	t_philo	philo;
}			t_var;


void	message(long milliseconds, t_philo philo, const char *str);

long	get_time_ms();

long	timestamp_ms(long program_start);

int		handle_errors(int argc);

void	*think(void *variables);

void	eat(t_rules rules, t_philo philo);

void	phsleep(t_rules rules, t_philo philo);

int		ft_sleep(t_rules rules, long ms);

#endif