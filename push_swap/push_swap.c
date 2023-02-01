/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/01 12:06:49 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	big_of_two;
	int	number;
	int	number_i;
	int	smalln;
	int	at_back;
	unsigned int	len;
	int	ratio;
	int	point;
	int	magic_num;

	if (sorted(stack_a))
		return ;
	number = find_num(stack_a, 1);
	number_i = find_num_i(stack_a, 0);
	len = stack_a->stacked;
	if (!sorted(stack_a) && stack_a->stack_ar[0] == number)
		ra(stack_a);
	if (len < 60)
		magic_num = 2;
	else if (len < 250)
		magic_num = 4;
	else
		magic_num = 8;
	ratio = number / magic_num;
	point = ratio;

	while (stack_a->stacked)
	{
		if (sorted(stack_a))
				break ;
		i = -1;
		while (++i < stack_a->stacked)
		{
			if (!is_val_under(stack_a, point))
				break ;
			if (sorted(stack_a))
				break ;
			if (stack_a->stack_ar[stack_a->stacked - 1] > stack_a->stack_ar[0] && stack_a->stack_ar[stack_a->stacked - 1] != number)
				if (find_small_point(stack_a, point))
					ra(stack_a);
				else
					rra(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1] < point)
			{
				pb(stack_b, stack_a);
				if (stack_b->stack_ar[stack_b->stacked - 1] - (point - ratio) > (point - (point - ratio)) / 2)
					rb(stack_b);
			}
			else if (find_small_point(stack_a, point))
				ra(stack_a);
			else
				rra(stack_a);
		}
		point += ratio;
	}
	at_back = stack_a->stacked;
	number = find_num(stack_b, 1);
	if (number < find_num(stack_a, 1))
		big_of_two = find_num(stack_a, 1);
	else
		big_of_two = number;
	if (!sorted(stack_a) && stack_a->stack_ar[0] == big_of_two)
		rra(stack_a);
	i = 0;
	while (i < at_back)
	{
		if (stack_a->stack_ar[0] > number)
			rra(stack_a);
		i++;
	}
	
	while (stack_b->stacked)
	{
		while (stack_b->stack_ar[stack_b->stacked - 1] < number)
		{
			number = find_num(stack_b, 1);
		if (number < find_num(stack_a, 1))
			big_of_two = find_num(stack_a, 1);
		else
			big_of_two = number;
		number_i = find_num_i(stack_b, 1);
			if ((big_of_two == stack_a->stack_ar[0] || stack_b->stack_ar[stack_b->stacked - 1] > stack_a->stack_ar[0])
				&& stack_b->stack_ar[stack_b->stacked - 1] != number)
			{
				at_back++;
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			if (stack_b->stack_ar[stack_b->stacked - 2] == number)
				sb(stack_b);
			else if (number_i >= stack_b->stacked / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		i = 0;
		while (i < at_back && !sorted(stack_a))
		{
			if (stack_b->stacked)
				smalln = find_num(stack_b, 0);
			else
				smalln = -2147483648;
			number = find_num(stack_b, 1);
			if ((stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1]
				&& stack_a->stack_ar[0] - stack_a->stack_ar[stack_a->stacked - 1] > number - stack_a->stack_ar[stack_a->stacked - 1]))
				rra(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 0) && stack_a->stack_ar[stack_a->stacked - 1] < smalln)
				ra(stack_a);
			i++;
		}
	}
	i = 0;
	while (i < at_back && !sorted(stack_a))
	{
		if (stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1] && !stack_b->stacked)
				rra(stack_a);
		i++;
	}
	to_print(" ");
}
#include<stdio.h>
int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	stack_a.stacked = 0;
	stack_b.stacked = 0;
	if (!handle_errors(argc, argv))
		return (0);
	else
	{
		while (--argc >= 1)
		{
			push(&stack_a, ft_atoi(argv[argc]));
		}
		stack_a = convert_to_seq(stack_a);
		sort(&stack_a, &stack_b);
	}
	return (0);
}
