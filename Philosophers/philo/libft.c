#include "philo.h"

static int	ft_pow(int num, int pow)
{
	if (pow != 0)
		return (num * ft_pow(num, pow - 1));
	return (1);
}

static int	calc_zeros(const char *nptr, int i)
{
	int	zeros;

	zeros = -1;
	while (nptr[i] >= '0' && nptr[i++] <= '9')
		zeros++;
	return (zeros);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	zeros;
	int	sign;
	int	result;
	int	signs;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	signs = 0;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		signs++;
		if (sign == -1 || signs > 1)
			return (0);
		if (nptr[i++] == '-')
			sign = -1;
	}
	zeros = calc_zeros(nptr, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result += (nptr[i++] - 48) * ft_pow(10, zeros--);
	return (result * sign);
}