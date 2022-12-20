/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/20 18:22:23 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char	*result;
	static int	new_line_point = 0;

	result = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	ft_strlcpy(result, buff + new_line_point, ft_strchr(buff + new_line_point, '\n') - (buff + new_line_point) + 1);
	new_line_point += ft_strchr(buff + new_line_point, '\n') - (buff + new_line_point) + 1;
	printf("%s\n", result);
	free(result);
	return (void *)0;
}

int	main(void)
{
	int fd = open("hey", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}