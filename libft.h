/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:16:30 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/28 15:33:18 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int	ft_isalpha(unsigned char c);

int	ft_isdigit(unsigned char c);

int	ft_isalnum(unsigned char c);

int	ft_isprint(unsigned char c);

char*	ft_strchr(char c, char* s);

char*	ft_strrchr(char c, char* s);

int	ft_tolower(unsigned char c);

int	ft_toupper(unsigned char c);

#endif
