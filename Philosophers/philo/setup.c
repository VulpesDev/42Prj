/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:44:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/14 16:45:06 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_rules(t_rules *rules, int argc, char **argv)
{
	rules->num_philo = ft_atoi(argv[1]);
	rules->num_forks = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		rules->num_eat = ft_atoi(argv[5]);
		rules->has_eat = 1;
	}
	else
		rules->has_eat = 0;
	rules->time_start = get_time_ms();
	rules->end = 0;
	return (0);
}

int	initialize_philo(t_philo *philo, t_rules *rules, int id, t_philo *prevph)
{
	philo->id = id;
	philo->hunger = timestamp_ms(rules->time_start);
	philo->times_ate = 0;
	philo->left_fork = malloc(sizeof(pthread_mutex_t) * 2);
	if (!philo->left_fork)
		return (1);
	pthread_mutex_init(philo->left_fork, NULL);
	prevph->right_fork = philo->left_fork;
	philo->var = malloc(sizeof(t_var) * 2);
	if (!philo->var)
		return (1);
	philo->var->rules = rules;
	philo->var->philo = philo;
	return (0);
}

int	initialize_all_philo(t_philo **philo, t_rules *rules)
{
	int		i;

	*philo = malloc((rules->num_philo + 1) * sizeof(t_philo));
	if (!*philo)
		return (1);
	i = -1;
	while (++i < rules->num_philo)
	{
		if (i == 0)
			initialize_philo(&((*philo)[i]), rules, i,
				&((*philo)[rules->num_philo - 1]));
		else
			initialize_philo(&((*philo)[i]), rules, i, &((*philo)[i - 1]));
		pthread_create(&((*philo)[i]).thread_id, NULL, &think, (*philo)[i].var);
	}
	return (0);
}

void	join_all_philo(t_philo *philos, t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philo)
		pthread_join(philos[i].thread_id, NULL);
}

void	destroy_all_philo(t_philo **philos, t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philo)
	{
		pthread_mutex_destroy((*philos)[i].left_fork);
		free((*philos)[i].left_fork);
		free((*philos)[i].var);
	}
	free(*philos);
}
