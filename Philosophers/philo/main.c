#include "philo.h"

int	initialize_rules(t_rules *rules, int argc, char **argv)
{

	rules->num_philo = ft_atoi(argv[1]);
	rules->num_forks = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->num_eat = ft_atoi(argv[5]);
	rules->time_start = get_time_ms();
	rules->end = 0;
	return (0);
}

int	initialize_philo(t_philo *philo, t_rules rules, int id)
{
	philo->id = id;
	philo->hunger = rules.time_die;
	philo->times_ate = 0;
	return (0);
}

int initialize_all_philo(t_philo **philo, t_rules rules)
{
	int		i;
	t_var	var;

	var.rules = rules;
	*philo = malloc((rules.num_philo + 1) * sizeof(t_philo));
	if (!*philo)
		return (1);
	i = -1;
	while (++i < rules.num_philo)
	{
		var.philo = (*philo)[i];
		initialize_philo(&(*philo)[i], rules, i);
		pthread_create(&(*philo)[i].thread_id, NULL, &think, &var);
	}
	return (0);
}

void	join_all_philo(t_philo *philos, t_rules rules)
{
	int i;

	i = -1;
	while (++i < rules.num_philo)
	{
		pthread_join(philos[i].thread_id, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	philos = NULL;
	if (handle_errors(argc))
		return (1);
	initialize_rules(&rules, argc, argv);
	if (initialize_all_philo(&philos, rules))
		return (1);
	join_all_philo(philos, rules);
	return (0);	
}