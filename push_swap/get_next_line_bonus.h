/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:30 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 14:02:58 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *s);
size_t	ft_strlcpy1(char *dst, const char *src, size_t size);
char	*ft_strchr1(const char *s, int c);
char	*ft_strjoin1(char *s1, const char *s2, size_t size);

#endif