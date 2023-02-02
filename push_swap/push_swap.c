/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/02 17:01:32 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_magic_num(int len)
{
	if (len < 60)
		return (2);
	else if (len < 250)
		return (4);
	else
		return (8);
}

int	get_big_of_two(t_stack *stack, int number)
{
	if (number < find_num(stack, 1))
		return(find_num(stack, 1));
	else
		return (number);
}

void	choose_best_move(t_stack *stack, int point)
{
	if (find_small_point(stack, point))
		ra(stack);
	else
		rra(stack);
}

void	push_a_2_b(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	ratio;
	int	point;
	int	number;

	number = find_num(stack_a, 1);
	len = stack_a->stacked;
	ratio = number / get_magic_num(len);
	point = ratio;
	while (stack_a->stacked)
	{
		if (sorted(stack_a))
				break ;
		while (is_val_under(stack_a, point))
		{
			if (sorted(stack_a))
				break ;
			if (stack_a->stack_ar[stack_a->stacked - 1] > stack_a->stack_ar[0] && stack_a->stack_ar[stack_a->stacked - 1] != number)
				choose_best_move(stack_a, point);
			if (stack_a->stack_ar[stack_a->stacked - 1] <= point)
			{
				pb(stack_b, stack_a);
				if (stack_b->stack_ar[stack_b->stacked - 1] - (point - ratio) > (point - (point - ratio)) / 2)
					rb(stack_b);
			}
			else
				choose_best_move(stack_a, point);
		}
		point += ratio;
	}
}

void	push_b_2_a(t_stack *stack_a, t_stack *stack_b, int *at_back)
{
	int	i;
	int	big_of_two;
	int	smalln;
	int	number;
	int	number_i;

	number = find_num(stack_b, 1);
	while (stack_b->stacked)
	{
		while (stack_b->stack_ar[stack_b->stacked - 1] < number)
		{
			number = find_num(stack_b, 1);
			big_of_two = get_big_of_two(stack_a, number);
			number_i = find_num_i(stack_b, 1);
			if ((big_of_two == stack_a->stack_ar[0] || stack_b->stack_ar[stack_b->stacked - 1] > stack_a->stack_ar[0])
				&& stack_b->stack_ar[stack_b->stacked - 1] != number)
			{
				at_back[0] = at_back[0] + 1;
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			if (stack_b->stacked > 1)
			{
				if (stack_b->stack_ar[stack_b->stacked - 2] == number)
					sb(stack_b);
				else if (number_i >= stack_b->stacked / 2)
					rb(stack_b);
				else
					rrb(stack_b);
			}
		}
		pa(stack_a, stack_b);
		i = -1;
		while (i++ < *at_back && !sorted(stack_a))
		{
			if (stack_b->stacked)
				smalln = find_num(stack_b, 0);
			else
				smalln = -2147483648;
			number = find_num(stack_b, 1);
			if (stack_a->stacked > 0)
			{
				if ((stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1])
					&& ((stack_a->stack_ar[0] - stack_a->stack_ar[stack_a->stacked - 1]) > (number - stack_a->stack_ar[stack_a->stacked - 1])))
					rra(stack_a);
				if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 0) && stack_a->stack_ar[stack_a->stacked - 1] < smalln)
					ra(stack_a);
			}
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	number;
	int	number_i;
	int	at_back;

	if (sorted(stack_a))
		return ;
	number_i = find_num_i(stack_a, 0);
	if (!sorted(stack_a) && stack_a->stack_ar[0] == find_num(stack_a, 1))
		ra(stack_a);
	push_a_2_b(stack_a, stack_b);
	at_back = stack_a->stacked;
	number = find_num(stack_b, 1);
	i = 0;
	while (i < at_back)
	{
		if (stack_a->stack_ar[0] > number)
			rra(stack_a);
		i++;
	}
	push_b_2_a(stack_a, stack_b, &at_back);
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
