/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:00:04 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/06 13:25:18 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], sizeof(char));
	write(fd, (void *)0, 1);
}