/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:47:13 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 12:55:57 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_warning(void)
{
	ft_printf("\n----------\n");
	ft_printf("Error!\n");
	ft_printf("Incorrect input!\n\n");
	ft_printf("Here is a list of parameters you can use:\n");
	ft_printf("  m- Mandelbrot\n");
	ft_printf("  j- Julia\n");
	ft_printf("    j r<0/500> i<0/500>\n");
	ft_printf("  t- Tricorn\n");
	ft_printf("----------\n\n");
	return (-1);
}

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
