/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_print2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:03:02 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 13:16:41 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	//ft_printf("ra\n");
	to_print("ra\n");
	r(stack_a);
}

void	rb(t_stack *stack_b)
{
	//ft_printf("rb\n");
	to_print("rb\n");
	r(stack_b);
}

void	rra(t_stack *stack_a)
{
	//ft_printf("rra\n");
	to_print("rra\n");
	revr(stack_a);
}

void	rrb(t_stack *stack_b)
{
	//ft_printf("rrb\n");
	to_print("rrb\n");
	revr(stack_b);
}
