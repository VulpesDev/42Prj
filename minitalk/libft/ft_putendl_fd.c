/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:03:43 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 14:20:11 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], sizeof(char));
	write(fd, "\n", 1);
}
