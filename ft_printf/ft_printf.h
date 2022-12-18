/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:14:09 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/18 18:01:28 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

int	ft_convertion(const char *c, va_list valist);

int	ft_printf(const char *s, ...);

int	ft_putchari_fd(char c, int fd);

int	ft_putstri_fd(char *s, int fd);

int	ft_putnbri_fd(int n, int fd);

int	ft_putusnbr_fd(unsigned int n, int fd);

int	ft_puthexu_fd(int n, int fd);

int	ft_puthexl_fd(int n, int fd);

int	ft_putp_fd(uintptr_t n, int fd);

int	ft_putp_tohex_fd(uintptr_t n, int fd);

#endif