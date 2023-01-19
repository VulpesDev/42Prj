/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:56:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/19 19:57:40 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# define BYTE_SIZE 8

int	str_bin(int ch);

typedef struct s_vars{
	int		i;
	char	byte[BYTE_SIZE];
	int		in_num;
	int		len;
	char	*result;
	int		k;
	int		pid_mode;
	int		pid_c;
}				t_vars;

#endif