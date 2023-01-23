/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_print2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:03:02 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/23 18:04:25 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	ft_printf("ra\n");
	r(stack_a);
}

void	rb(t_stack *stack_b)
{
	ft_printf("rb\n");
	r(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack_a)
{
	ft_printf("rra\n");
	revr(stack_a);
}

void	rrb(t_stack *stack_b)
{
	ft_printf("rrb\n");
	revr(stack_b);
}
