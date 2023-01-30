/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:52:06 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 13:16:40 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	//ft_printf("sa\n");
	to_print("sa\n");
	s(stack_a);
}

void	sb(t_stack *stack_b)
{
	//ft_printf("sb\n");
	to_print("sb\n");
	s(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	//ft_printf("ss\n");
	to_print("ss\n");
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	//ft_printf("pa\n");
	to_print("pa\n");
	p(stack_b, stack_a);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	//ft_printf("pb\n");
	to_print("pb\n");
	p(stack_a, stack_b);
}
