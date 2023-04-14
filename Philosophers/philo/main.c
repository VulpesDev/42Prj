/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:27:50 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/14 16:44:42 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	mon_id;
	t_var		vars;

	philos = NULL;
	if (handle_errors(argc))
		return (1);
	initialize_rules(&rules, argc, argv);
	if (initialize_all_philo(&philos, &rules))
		return (1);
	vars.philo = philos;
	vars.rules = &rules;
	pthread_create(&mon_id, NULL, &monitoring, &vars);
	join_all_philo(philos, &rules);
	pthread_join(mon_id, NULL);
	destroy_all_philo(&philos, &rules);
	return (0);
}
