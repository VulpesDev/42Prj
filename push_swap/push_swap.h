/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:33:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/22 14:59:17 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_MAX_COUNT 10
# define STACK_SIZE 1000

typedef struct s_stack{
	int	stack_ar[STACK_SIZE];
	int	stacked;
}			t_stack;
int		handle_errors(int argc, char **argv);
void	display(t_stack stack);
void	push(t_stack *stack, int value);
void	pop(t_stack *stack);
long	ft_atol(const char *nptr); // checks for numbers that 
//										have the same length as max and min

#endif