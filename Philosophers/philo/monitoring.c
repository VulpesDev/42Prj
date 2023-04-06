#include "philo.h"

void	*monitoring(void *vars)
{
	int	i;
	t_var *var;

	var = (t_var *)vars;
	while (1)
	{
		i = -1;
		while (++i < var->rules->num_philo)
		{
			if ((int)(timestamp_ms(var->rules->time_start)
				- var->philo[i].hunger) > var->rules->time_die)
			{
				var->rules->end = 1;
				message(timestamp_ms(var->rules->time_start), &var->philo[i], " died\n");
				return (NULL);
			}
			else if (var->rules->has_eat
				&& var->philo[i].times_ate >= var->rules->num_eat)
			{
				var->rules->end = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}