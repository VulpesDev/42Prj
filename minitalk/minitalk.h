/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:56:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/20 12:23:34 by tvasilev         ###   ########.fr       */
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
# define SLEEP_TIME 150

int		str_bin(int ch);

void	wait_func(int w_sig);

int		check_pid(char *str);

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

typedef struct s_send_vars{
	int		i;
	int		limit;
	char	*sdup;
}				t_send_vars;

#endif