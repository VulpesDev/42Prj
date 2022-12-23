/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/23 12:42:34 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#define BUFFER_SIZE 4096

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	*fbuff;
	char	*result;
	int	chars_read;
	
	result = 0;
	chars_read = 0;
	if (!buff){
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		chars_read = read(fd, buff, BUFFER_SIZE);
		buff[chars_read] = 0;
		fbuff = buff;
	}
	while (!ft_strchr(buff, '\n'))
	{
		result = ft_strjoin(result, buff, ft_strlen(buff) + 1);
		chars_read = read(fd, buff, BUFFER_SIZE);
		buff[chars_read] = 0;
		if (chars_read <= 0)
		{
			buff = NULL;
			free(fbuff);
			if (*result == *"")
			{
				free(result);
				return (NULL);
			}
			return (result);
		}
	}
	if (ft_strchr(buff, '\n'))
	{
		result = ft_strjoin(result, buff, ft_strchr(buff, '\n') - buff + 2);
		buff = ft_strchr(buff, '\n') + 1;
	}
	return (result);
}

int	main(void)
{
	int fd = open("hey", O_RDONLY);
	char	*s;
	int i = 0;

	while (i < 10)
	{
		s = get_next_line(fd);
		printf("%s", s ? s : "<NULL>");
		free(s);
		i++;
	}
	close(fd);
	return (0);
}