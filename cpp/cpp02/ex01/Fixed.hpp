/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:48:33 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/05 19:41:52 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	const static int	_fbits = 8;
public:
	//*Raw functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	//*Convert functions
	float	toFloat( void ) const;
	int		toInt( void ) const;
	//*Constructors
	Fixed( void );
	Fixed( const int n );
	Fixed( const float n );
	Fixed( const Fixed &f );
	Fixed&	operator=( const Fixed &other );
	~Fixed();
	//*Overload
	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif