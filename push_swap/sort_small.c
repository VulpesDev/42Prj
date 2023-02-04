/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:07:36 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 10:57:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a, t_stack *stack_b)
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