/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/22 17:28:29 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#define BUFFER_SIZE 4096

//last line doesn't show (code does not work when no more \n)
//free result (careful for over assigning)
//free buff when chars_read == 0
char	*get_next_line(int fd)
{
	static char	*buff;
	char	*result;
	int	chars_read;
	
	result = 0;
	chars_read = 0;
	if (!buff){
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		buff[read(fd, buff, BUFFER_SIZE)] = 0;
	}
	while (!ft_strchr(buff, '\n'))
	{
		result = ft_strjoin(result, buff, ft_strlen(buff) + 1);
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read <= 0)
			return (0);
		buff[chars_read] = 0;
	}
	if (ft_strchr(buff, '\n'))
	{
		result = ft_strjoin(result, buff, ft_strchr(buff, '\n') - buff + 2);
		buff = ft_strchr(buff, '\n') + 1;
		return (result);
	}
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