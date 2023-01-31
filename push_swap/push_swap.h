/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:33:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 11:24:29 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_MAX_COUNT 10
# define STACK_SIZE 2000
# include <stdlib.h>

typedef struct s_stack{
	int	stack_ar[STACK_SIZE];
	int	stacked;
}			t_stack;
int		handle_errors(int argc, char **argv);
long	ft_atol(const char *nptr);
//* BAISC STACK FUNCTIONS
void	display(t_stack stack);
void	push(t_stack *stack, int value);
void	pop(t_stack *stack);
//* SUBJECT FUNCTIONS
void	s(t_stack *stack);
void	p(t_stack *stack, t_stack *stack_receive);
void	r(t_stack *stack);
void	revr(t_stack *stack);
//* STACK OPS PRINT
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
//* FIND FUNCTIONS
int	find_small(t_stack *stack);
int	find_small_i(t_stack *stack);
int	find_big(t_stack *stack);
int	find_big_i(t_stack *stack);
unsigned int	find_total(t_stack *stack);
int	find_closest(t_stack *stack, int point, int len);
int	find_small_point(t_stack *stack, int point);
int	find_small_i_big_than(t_stack *stack, int bigger);
//* OTHER FUNCTIONS
void	to_print(char *str);
int	sorted(t_stack *stack);
int	is_val_under(t_stack *stack, int point);
t_stack	convert_to_seq(t_stack stack);
#endif