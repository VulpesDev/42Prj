#include "philo.h"

void	ft_unlock_mutex(t_philo *philo, int state)
{
	if (state == 0)
		pthread_mutex_unlock(philo->left_fork);
	else if (state == 1)
		pthread_mutex_unlock(philo->right_fork);
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	wait_till_dead(t_rules *rules, t_philo *philo)
{
	usleep(1000);
	message(timestamp_ms(rules->time_start), philo, "has taken a fork\n");
	while (1)
	{
		if (rules->end)
			return ;
		usleep(1000);
	}
}

void	leat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (rules->end)
		return ft_unlock_mutex(philo, 2);
	message(timestamp_ms(rules->time_start), philo, "has taken a fork\n");
	philo->hunger = timestamp_ms(rules->time_start);
	pthread_mutex_lock(philo->left_fork);
	if (rules->end)
		return ft_unlock_mutex(philo, 0);
	message(timestamp_ms(rules->time_start), philo, "has taken a fork\n");
	message(timestamp_ms(rules->time_start), philo, "is eating\n");
	if (ft_sleep(rules, rules->time_eat))
		return ft_unlock_mutex(philo, 2);
	philo->times_ate++;
	ft_unlock_mutex(philo, 2);
	phsleep(rules, philo);
}

void	*think(void *variables)
{
	t_var	*var;
	t_rules *rules;
	t_philo *philo;

	var = (t_var*)variables;
	rules = var->rules;
	philo = var->philo;
	if (rules->end)
		return (NULL);
	message(timestamp_ms(rules->time_start), philo, "is thinking\n");
	if (rules->num_forks > 1)
	{
		if (philo->id == rules->num_philo-1)
			leat(rules, philo);
		else
			eat(rules, philo);
	}
	else
		wait_till_dead(rules, philo);
	return (NULL);
}

void	eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (rules->end)
		return ft_unlock_mutex(philo, 0);
	message(timestamp_ms(rules->time_start), philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	if (rules->end)
		return ft_unlock_mutex(philo, 2);
	message(timestamp_ms(rules->time_start), philo, "has taken a fork\n");
	philo->hunger = timestamp_ms(rules->time_start);
	message(timestamp_ms(rules->time_start), philo, "is eating\n");
	if (ft_sleep(rules, rules->time_eat))
		return ft_unlock_mutex(philo, 2);
	philo->times_ate++;
	ft_unlock_mutex(philo, 2);
	phsleep(rules, philo);
}

void	phsleep(t_rules *rules, t_philo *philo)
{
	message(timestamp_ms(rules->time_start), philo, "is sleeping\n");
	if (ft_sleep(rules, rules->time_sleep))
		return ;
	think(philo->var);
}