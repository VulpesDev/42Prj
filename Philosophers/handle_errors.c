/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:43:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/12 12:54:44 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(void)
{
	write(STD_ERROR, "Error\n", 6);
	write(1, STR_INSTRUCTIONS, STR_INSTRUCTIONS_I);
	return (0);
}

int	handle_errors(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return print_error();
	return (1);
}