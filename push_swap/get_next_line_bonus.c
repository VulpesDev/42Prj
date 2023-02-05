/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 14:05:32 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*freeing_shit(char **buff, char *result, int free_result)
{
	free(*buff);
	*buff = NULL;
	if (free_result)
	{
		free(result);
	}
	return (NULL);
}

static char	*helper(int fd, char **buff, char *result, int *chars_read)
{
	while ((!ft_strchr1(*buff, '\n') && **buff != *"") || **buff == '\0')
	{
		result = ft_strjoin1(result, *buff, ft_strlen1(*buff) + 1);
		*chars_read = read(fd, *buff, BUFFER_SIZE);
		(*buff)[*chars_read] = 0;
		if (*chars_read < 0)
			return (freeing_shit(buff, result, 1));
		if (*chars_read == 0)
		{
			if (*result == *"")
				return (freeing_shit(buff, result, 1));
			return (result);
		}
	}
	if (ft_strchr1(*buff, '\n'))
	{
		result = ft_strjoin1(result, *buff, ft_strchr1(*buff, '\n')
				- *buff + 2);
		ft_strlcpy1(*buff, ft_strchr1(*buff, '\n') + 1,
			ft_strlen1(ft_strchr1(*buff, '\n')));
	}
	if (result == 0)
		return (freeing_shit(buff, result, 1));
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff[FOPEN_MAX];
	char		*result;
	int			chars_read;

	result = 0;
	chars_read = 0;
	if (fd == -1)
		return (freeing_shit(&(buff[0]), result, 0));
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!buff[fd])
	{
		buff[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff[fd])
			return (NULL);
		chars_read = read(fd, buff[fd], BUFFER_SIZE);
		if (chars_read < 0)
			return (freeing_shit(&(buff[fd]), result, 0));
		buff[fd][chars_read] = 0;
	}
	return (helper(fd, &(buff[fd]), result, &chars_read));
}
