/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_subject_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:40:05 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/05 17:35:14 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//* SUBJECT FUNCTIONS
void	s(t_stack *stack)
{
	int	temp;

	if (stack->stacked <= 1)
		return ;
	temp = stack->stack_ar[stack->stacked - 1];
	stack->stack_ar[stack->stacked - 1] = stack->stack_ar[stack->stacked - 2];
	stack->stack_ar[stack->stacked - 2] = temp;
}

void	p(t_stack *stack, t_stack *stack_receive)
{
	push(stack_receive, stack->stack_ar[stack->stacked - 1]);
	pop(stack);
}

void	r(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->stacked;
	if (i < 1)
		return ;
	temp = stack->stack_ar[i - 1];
	while (--i)
	{
		stack->stack_ar[i] = stack->stack_ar[i - 1];
	}
	stack->stack_ar[0] = temp;
}

void	revr(t_stack *stack)
{
	int	temp;
	int	i;

	i = -1;
	temp = stack->stack_ar[0];
	while (++i < stack->stacked - 1)
	{
		stack->stack_ar[i] = stack->stack_ar[i + 1];
	}
	stack->stack_ar[stack->stacked - 1] = temp;
}
