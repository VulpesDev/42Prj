/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/24 18:16:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO bubble sort for only one stack first
//TODO then make bubble/2
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	sorted;
	while (!sorted)
	{
		sorted = 1;
		while (stack_a->stacked > 0)
		{
			while (stack_a->stack_ar[stack_a->stacked - 1] > stack_a->stack_ar[stack_a->stacked - 2])
			{
				sa(stack_a);
				sorted = 0;
			}
			pb(stack_b, stack_a);
		}
	}
}

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
		sort(&stack_a, &stack_b);
		display(stack_a);
		display(stack_b);
	}
	return (0);
}
