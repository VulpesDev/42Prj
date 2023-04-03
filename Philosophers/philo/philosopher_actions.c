#include "philo.h"

void	*think(void *variables)
{
	t_var	*var;
	t_rules rules;
	t_philo philo;

	var = (t_var*)variables;
	rules = var->rules;
	philo = var->philo;
	message(timestamp_ms(rules.time_start), philo, "is thinking\n");
	eat(rules, philo);
	return (NULL);
}

void	eat(t_rules rules, t_philo philo)
{
	pthread_mutex_lock(&philo.left_fork);
	message(timestamp_ms(rules.time_start), philo, "has taken a fork\n");
	pthread_mutex_lock(&philo.right_fork);
	message(timestamp_ms(rules.time_start), philo, "has taken a fork\n");
	philo.hunger = rules.time_die;
	if (ft_sleep(rules, rules.time_eat))
		return ;
	pthread_mutex_unlock(&philo.left_fork);
	pthread_mutex_unlock(&philo.right_fork);
	phsleep(rules, philo);
}

void	phsleep(t_rules rules, t_philo philo)
{
	message(timestamp_ms(rules.time_start), philo, "is sleeping\n");
	if (ft_sleep(rules, rules.time_sleep))
		return ;
}