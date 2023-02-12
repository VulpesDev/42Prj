/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:40:14 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/12 14:38:23 by tvasilev         ###   ########.fr       */
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

typedef struct s_default_data
{
	int	num_philo;
	int	num_forks;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	ec_eat;
}				t_default_data;

int	handle_errors(int argc, char **argv);

int	ft_atoi(const char *nptr);

#endif