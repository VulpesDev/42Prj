/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:16:30 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/28 16:59:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isprint(int c);

char*	ft_strchr(char c, const char* s);

char*	ft_strrchr(char c, const char* s);

int	ft_tolower(int c);

int	ft_toupper(int c);

int	ft_isascii(int c);

#endif
