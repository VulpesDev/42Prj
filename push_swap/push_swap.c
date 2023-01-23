/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/23 13:39:32 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	stack_a.stacked = 0;
	stack_b.stacked = 0;
	if (!handle_errors(argc, argv))
		return (0);
	else
	{
		while (--argc >= 1)
		{
			push(&stack_a, ft_atoi(argv[argc]));
		}
	}
	return (0);
}
