/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:35:12 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/05 12:11:08 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_num(t_stack *stack, int big)
{
	int	i;
	int	result;
	int	len;

	i = 0;
	if (stack->stacked <= 0)
		return (0);
	result = stack->stack_ar[stack->stacked - 1];
	len = stack->stacked - 1;
	while (i < len)
	{
		if (stack->stack_ar[i] < result && !big)
			result = stack->stack_ar[i];
		else if (stack->stack_ar[i] > result && big)
			result = stack->stack_ar[i];
		i++;
	}
	return (result);
}

int	find_num_i(t_stack *stack, int big)
{
	int	i;
	int	num_i;
	int	len;

	i = 0;
	num_i = stack->stacked - 1;
	len = stack->stacked - 1;
	while (i < len)
	{
		if (stack->stack_ar[i] < stack->stack_ar[num_i] && !big)
			num_i = i;
		else if (stack->stack_ar[i] > stack->stack_ar[num_i] && big)
			num_i = i;
		i++;
	}
	return (num_i);
}

int	find_small_point(t_stack *stack, int point)
{
	int	top;
	int	bot;

	top = stack->stacked - 1;
	bot = 0;
	while (bot < stack->stacked - 1)
	{
		if (stack->stack_ar[bot++] < point)
			break ;
	}
	while (top >= 0)
	{
		if (stack->stack_ar[top--] < point)
			break ;
	}
	if ((stack->stacked - 1) - top < bot)
		return (1);
	return (0);
}

int	find_small_i_big_than(t_stack *stack, int bigger)
{
	int	i;
	int	num_i;
	int	len;

	i = 0;
	len = stack->stacked;
	while (stack->stack_ar[i] <= bigger && i < len)
		i++;
	num_i = i;
	i = 0;
	while (i < len)
	{
		if (stack->stack_ar[i] < stack->stack_ar[num_i]
			&& stack->stack_ar[i] > bigger)
			num_i = i;
		i++;
	}
	return (num_i);
}
