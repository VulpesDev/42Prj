/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:34:34 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/31 12:58:47 by tvasilev         ###   ########.fr       */
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
	while ((!ft_strchr(*buff, '\n') && **buff != *"") || **buff == '\0')
	{
		result = ft_strjoin(result, *buff, ft_strlen(*buff) + 1);
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
	if (ft_strchr(*buff, '\n'))
	{
		result = ft_strjoin(result, *buff, ft_strchr(*buff, '\n') - *buff + 2);
		ft_strlcpy(*buff, ft_strchr(*buff, '\n') + 1,
			ft_strlen(ft_strchr(*buff, '\n')));
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
