/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:52:06 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/02 14:37:11 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	to_print("sa\n");
	s(stack_a);
}

void	sb(t_stack *stack_b)
{
	to_print("sb\n");
	s(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	to_print("ss\n");
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	to_print("pa\n");
	p(stack_b, stack_a);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	to_print("pb\n");
	p(stack_a, stack_b);
}

