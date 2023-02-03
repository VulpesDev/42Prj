/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:07:36 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/03 17:47:58 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (sorted(stack_a))
		return ;
	if (stack_a->stack_ar[1] != find_num(stack_a, 1)
		&& stack_a->stack_ar[0] > stack_a->stack_ar[2])
		sa(stack_a);
	if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 1))
		while (!sorted(stack_a))
			ra(stack_a);
	else
		while (!sorted(stack_a))
			rra(stack_a);
	to_print(" ");
}