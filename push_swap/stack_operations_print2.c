/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_print2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:03:02 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/03 12:03:00 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	to_print("ra\n");
	r(stack_a);
}

void	rb(t_stack *stack_b)
{
	to_print("rb\n");
	r(stack_b);
}

void	rra(t_stack *stack_a)
{
	to_print("rra\n");
	revr(stack_a);
}

void	rrb(t_stack *stack_b)
{
	to_print("rrb\n");
	revr(stack_b);
}
