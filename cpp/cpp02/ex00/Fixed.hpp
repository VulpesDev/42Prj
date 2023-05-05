/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:48:33 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 17:21:51 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					_value;
	const static int	_fbits = 8;
public:
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	Fixed( void );
	Fixed( const Fixed &f);
	Fixed&	operator=(const Fixed &other);
	~Fixed();
};

#endif