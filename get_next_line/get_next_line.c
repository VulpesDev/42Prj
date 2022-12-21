/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/21 16:27:00 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	static char	*result;
	//static int	new_line_point = 0;
	
	result = 0;
	while (!ft_strchr(buff, '\n'))
	{
		if (!read(fd, buff, BUFFER_SIZE))
			break ;
		result = ft_strjoin(result, buff);
		//ft_strlcpy(result, buff + new_line_point, ft_strchr(buff + new_line_point, '\n') - (buff + new_line_point) + 2);
	}
	//result = ft_strjoin(result, buff, ft_strchr(buff, '\n') - (buff) + 2);
	return (result);
}

int	main(void)
{
	int fd = open("hey", O_RDONLY);
	char	*s;
	int i = 0;


	while (i < 1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	close(fd);
	
	return (0);
}