/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:30 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/24 19:32:43 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, const char *s2, size_t size);

char	*ft_strdup(char *s);

#endif