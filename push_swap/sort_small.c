/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:07:36 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/06 15:29:16 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_3(t_stack *stack_a)
{
	if (sorted(stack_a))
		return ;
	if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 0))
		rra(stack_a);
	else if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 1))
		ra(stack_a);
	else if (stack_a->stack_ar[0] != find_num(stack_a, 1))
		rra(stack_a);
	if (sorted(stack_a))
	{
		to_print(" ");
		return ;
	}
	sa(stack_a);
	to_print(" ");
}

void	sort_3_m(t_stack *stack_a)
{
	if (sorted(stack_a))
		return ;
	if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 0))
		rra(stack_a);
	else if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 1))
		ra(stack_a);
	else if (stack_a->stack_ar[0] != find_num(stack_a, 1))
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	sa(stack_a);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	number_i;

	i = -1;
	if (sorted(stack_a))
		return ;
	number_i = find_num_i(stack_a, 0);
	while (++i < 2)
	{
		while (stack_a->stack_ar[stack_a->stacked - 1] != find_num(stack_a, 0))
		{
			if (number_i >= stack_a->stacked / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	sort_3_m(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	to_print(" ");
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	number_i;

	if (sorted(stack_a))
		return ;
	number_i = find_num_i(stack_a, 0);
	while (stack_a->stack_ar[stack_a->stacked - 1] != find_num(stack_a, 0))
	{
		if (number_i >= stack_a->stacked / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	sort_3_m(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	to_print(" ");
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stacked <= 3)
		sort_3(stack_a);
	else if (stack_a->stacked == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->stacked == 5)
		sort_5(stack_a, stack_b);
}
