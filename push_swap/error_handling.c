/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:42:34 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/09 12:19:36 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

//checks if the string is numeric
//keeping in mind the spaces, tabs... and the signs
static int	is_str_number(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (str[i] == '+' || str[i] == '-'
		|| str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			num++;
		i++;
	}
	if (num > 0)
		return (1);
	else
		return (0);
}

static int	is_duplicate(int i, int argc, char **str)
{
	int	k;

	k = 0;
	while (k < argc && k != i)
	{
		if (!ft_strncmp(str[i], str[k], ft_strlen(str[i]) + ft_strlen(str[k])))
		{
			return (0);
		}
		k++;
	}
	return (1);
}

//checks the signs and the length of the number, ignoring the 0s in front
static int	is_valid_string(char *str)
{
	int		i;
	int		signs;
	int		n_count;

	i = 0;
	signs = 0;
	n_count = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		signs++;
		i++;
	}
	if (signs > 1)
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i++] <= '9')
		n_count++;
	if (n_count > INT_MAX_COUNT)
		return (0);
	return (1);
}

int	handle_errors(int argc, char **argv)
{
	int		i;
	long	atol;

	i = 0;
	if (argc <= 1)
		return (0);
	while (++i < argc)
	{
		if (*argv[i] == '\0')
			return (print_error());
		if (!is_str_number(argv[i]))
			return (print_error());
		if (!is_duplicate(i, argc, argv))
			return (print_error());
		atol = ft_atol(argv[i]);
		if (atol > INT_MAX || atol < INT_MIN || !is_valid_string(argv[i]))
			return (print_error());
	}
	return (1);
}
