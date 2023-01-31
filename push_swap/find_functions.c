/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:35:12 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 11:23:49 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small(t_stack *stack)
{
	int	i;
	int	result;

	i = 0;
	result = stack->stack_ar[stack->stacked - 1];
	while (i < stack->stacked - 1)
	{
		if (stack->stack_ar[i] < result)
			result = stack->stack_ar[i];
		i++;
	}
	return (result);
}

int	find_small_i(t_stack *stack)
{
	int	i;
	int	small_i;

	i = 0;
	small_i = stack->stacked - 1;
	while (i < stack->stacked - 1)
	{
		if (stack->stack_ar[i] < stack->stack_ar[small_i])
			small_i = i;
		i++;
	}
	return (small_i);
}

int	find_big(t_stack *stack)
{
	int	i;
	int	result;

	i = 0;
	result = stack->stack_ar[stack->stacked - 1];
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] > result)
			result = stack->stack_ar[i];
		i++;
	}
	return (result);
}

int	find_big_i(t_stack *stack)
{
	int	i;
	int	big_i;

	i = 0;
	big_i = stack->stacked - 1;
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] > stack->stack_ar[big_i])
			big_i = i;
		i++;
	}
	return (big_i);
}

unsigned int	find_total(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->stacked)
		i++;
	return (i);
}

int	find_closest(t_stack *stack, int point, int len)
{
	int	start;
	int	end;

	start = 0;
	end = stack->stacked - 1;
	while (stack->stack_ar[start] > point)
		start++;
	while (stack->stack_ar[end] > point)
		end--;
	end = stack->stacked - end;
	return (end > start);
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
			break;
	}
	if ((stack->stacked - 1) - top < bot)
		return (1);
	return (0);
}

int	find_small_i_big_than(t_stack *stack, int bigger)
{
	int	i;
	int	small_i;

	i = 0;
	while (stack->stack_ar[i] <= bigger && i < stack->stacked)
		i++;
	small_i = i;
	i = 0;
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] < stack->stack_ar[small_i] && stack->stack_ar[i] > bigger)
			small_i = i;
		i++;
	}
	return (small_i);
}