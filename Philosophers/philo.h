/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:40:14 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/22 11:59:04 by tvasilev         ###   ########.fr       */
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
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <sys/time.h>

typedef struct s_default_data
{
	int	num_philo;
	int	num_forks;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	ec_eat;
	long long int s_time_ms;
	struct timeval  tv;
	pthread_mutex_t *th_mutx;
}				t_default_data;

typedef struct{
	pthread_t ph_id;
	t_default_data *data;
	pthread_mutex_t	*th_mutx;
	int		 		*eat_status;
	int				*stop;
}	t_phil_vars;

int	handle_errors(int argc);

int	ft_atoi(const char *nptr);

int	ft_usleep(__useconds_t usec, t_phil_vars* vars);

long long int calc_secs(struct timeval tv, long long s_time_ms);

void	ph_eat(void *v);

#endif