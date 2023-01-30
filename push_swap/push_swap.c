/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 15:16:33 by tvasilev         ###   ########.fr       */
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

int	sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->stacked - 1)
		if (stack->stack_ar[i] < stack->stack_ar[i + 1])
			return (0);
	return (1);
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

int	is_val_under(t_stack *stack, int point)
{
	int	i;

	i = 0;
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] < point)
			return (1);
		i++;
	}
	return (0);
}

void	to_print(char *str)
{
	static char	*result;
	static int	skip;

	if(!skip)
	{
		if (result)
		{
			if ((!ft_strncmp(str, "ra", 2) && !ft_strncmp(result, "rb", 2))
			|| (!ft_strncmp(str, "rb", 2) && !ft_strncmp(result, "ra", 2)))
			{
				ft_printf("rr\n");
				skip++;
			}
			else if ((!ft_strncmp(str, "rra", 3) && !ft_strncmp(result, "rrb", 3))
			|| (!ft_strncmp(str, "rrb", 3) && !ft_strncmp(result, "rra", 3)))
			{
				ft_printf("rrr\n");
				skip++;
			}
			else
				ft_printf("%s", result);
			free(result);
		}
	}
	else
	{
		skip++;
		if (skip > 1)
			skip = 0;
		free(result);
	}
	result = ft_strdup(str);
	if (*result == ' ')
		free(result);
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

t_stack	convert_to_seq(t_stack stack)
{
	// unsigned int	len;
	// unsigned int	counter;
	// int	lastnum;

	// counter = 0;
	// len = find_total(stack);
	// while (counter < (signed int)len)
	// {
	// 	lastnum = stack->stack_ar[find_small_i(stack)];
	// 	if (lastnum < 0)
	// 		stack->stack_ar[find_small_i(stack)] = counter;
	// 	else
	// 		stack->stack_ar[find_small_i_big_than(stack, counter - 1)] = counter;
	// 	counter++;
	// }
	t_stack	new;
	int	len;
	int	counter;
	int	small_i;
	
	len = find_total(&stack);
	counter = 0;
	small_i = find_small_i(&stack);
	while (counter < len)
	{
		new.stack_ar[small_i] = counter;
		small_i = find_small_i_big_than(&stack, stack.stack_ar[small_i]);
		new.stacked++;
		counter++;
	}
	return (new);
}

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
	int	half_count;
	int	half;
	int	closest;
	int	first;
	int	magic_num;

	number = find_big(stack_a);
	number_i = find_small_i(stack_a);
	len = find_total(stack_a);
	if (!sorted(stack_a) && stack_a->stack_ar[0] == number)
		ra(stack_a);
	if (len < 60)
		magic_num = 2;
	else if (len < 250)
		magic_num = 4;
	else
		magic_num = 8;
	ratio = number / magic_num;
	half_count = (len / magic_num) / 2;
	point = ratio;
	first = 1;

	while (stack_a->stacked)
	{
		if (sorted(stack_a))
				break ;
		i = -1;
		half = 0;
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
				if (half > half_count && !first)
					rb(stack_b);
				half++;
			}
			else if (find_small_point(stack_a, point))
				ra(stack_a);
			else
				rra(stack_a);
		}
		first = 0;
		point += ratio;
	}
	at_back = stack_a->stacked;
	number = find_big(stack_b);
	if (number < find_big(stack_a))
		big_of_two = find_big(stack_a);
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
			number = find_big(stack_b);
		if (number < find_big(stack_a))
			big_of_two = find_big(stack_a);
		else
			big_of_two = number;
		number_i = find_big_i(stack_b);
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
				smalln = find_small(stack_b);
			else
				smalln = -2147483648;
			number = find_big(stack_b);
			if ((stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1]
				&& stack_a->stack_ar[0] - stack_a->stack_ar[stack_a->stacked - 1] > number - stack_a->stack_ar[stack_a->stacked - 1]))
				rra(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1] == find_small(stack_a) && stack_a->stack_ar[stack_a->stacked - 1] < smalln)
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
		//display(stack_a);
	}
	return (0);
}
