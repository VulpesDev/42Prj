/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:06:03 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/06 12:45:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

int	comp_func(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	text_2_cmd_h(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (comp_func(str, "ra") == 10)
		r(stack_a);
	else if (comp_func(str, "rb") == 10)
		r(stack_b);
	else if (comp_func(str, "rra") == 10)
		revr(stack_a);
	else if (comp_func(str, "rrb") == 10)
		revr(stack_b);
	else if (comp_func(str, "rr") == 10)
	{
		r(stack_a);
		r(stack_b);
	}
	else if (comp_func(str, "rrr") == 10)
	{
		revr(stack_a);
		revr(stack_b);
	}
	else
		return (0);
	return (1);
}

int	text_2_cmd(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (comp_func(str, "sa") == 10)
		s(stack_a);
	else if (comp_func(str, "sb") == 10)
		s(stack_b);
	else if (comp_func(str, "ss") == 10)
	{
		s(stack_a);
		s(stack_b);
	}
	else if (comp_func(str, "pa") == 10)
		p(stack_b, stack_a);
	else if (comp_func(str, "pb") == 10)
		p(stack_a, stack_b);
	else
		return (text_2_cmd_h(str, stack_a, stack_b));
	return (1);
}

void	read_and_do(t_stack *stack_a, t_stack *stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s != NULL)
	{
		if (!text_2_cmd(s, stack_a, stack_b))
		{
			free(s);
			get_next_line(-1);
			write(2, "Error!", 7);
			return ;
		}
		free(s);
		s = get_next_line(0);
	}
	if (sorted(stack_a) && stack_b->stacked < 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stacked = 0;
	stack_b.stacked = 0;
	if (!handle_errors(argc, argv))
		return (0);
	else
	{
		while (--argc >= 1)
			push(&stack_a, ft_atoi(argv[argc]));
		stack_a = convert_to_seq(stack_a);
		read_and_do(&stack_a, &stack_b);
	}
	return (0);
}
