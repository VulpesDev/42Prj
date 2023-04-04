#include "philo.h"

void	message(long milliseconds, t_philo *philo, const char *str)
{
	printf("%ld #%d %s\n", milliseconds, philo->id+1, str);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (long)(tv.tv_usec / 1000);
}

long	timestamp_ms(long program_start)
{
	return (get_time_ms() - program_start);
}

int		ft_sleep(t_rules *rules, long ms)
{
	long t;

	t = 0;
	while (t < ms)
	{
		if (rules->end)
			return (1);
		t++;
		usleep(1000);
	}
	return (0);
}
