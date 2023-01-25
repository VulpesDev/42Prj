/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/25 17:19:27 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	sorted;
	int	i;
	int	smallest;
	int	midpoint;
	int	smallest_i;

	while (stack_a->stacked)
	{
		midpoint = 0;
		smallest = stack_a->stack_ar[stack_a->stacked - 1];
		i = 0;
		while (i < stack_a->stacked)
		{
			midpoint += stack_a->stack_ar[i];
			if (stack_a->stack_ar[i] < smallest)
			{
				smallest = stack_a->stack_ar[i];
				smallest_i = i;
			}
			i++;
		}
		midpoint /= i;
		while (stack_a->stack_ar[stack_a->stacked - 1] > smallest && stack_a->stack_ar[stack_a->stacked - 1] > midpoint)
		{
			if (stack_a->stack_ar[stack_a->stacked - 1] <= midpoint)
				pb(stack_b, stack_a);
			if (smallest_i >= stack_a->stacked / 2)
					ra(stack_a);
			else
					rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	while (stack_b->stacked)
	{
		smallest = stack_b->stack_ar[stack_b->stacked - 1];
		i = 0;
		while (i < stack_b->stacked - 1)
		{
			if (stack_b->stack_ar[i] > smallest)
			{
				smallest = stack_b->stack_ar[i];
				smallest_i = i;
			}
			i++;
		}
		while (stack_b->stack_ar[stack_b->stacked - 1] < smallest)
		{
			if (stack_b->stack_ar[stack_b->stacked - 2] == smallest)
				sb(stack_b);
			else if (smallest_i >= stack_b->stacked / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		
		pa(stack_a, stack_b);
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
	}
	return (0);
}
