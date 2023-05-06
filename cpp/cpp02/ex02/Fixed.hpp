/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:48:33 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/06 12:28:21 by tvasilev         ###   ########.fr       */
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
	const static int	_fbits;
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
		//Comparison
	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;
		//Arithmetics
	Fixed&	operator+( const Fixed& other );
	Fixed&	operator-( const Fixed& other );
	Fixed&	operator*( const Fixed& other );
	Fixed&	operator/( const Fixed& other );
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );
		//Specials
	static Fixed&		min( Fixed& one, Fixed& other );
	static const Fixed&	min( const Fixed& one, const Fixed& other );
	static Fixed&		max( Fixed& one, Fixed& other );
	static const Fixed&	max( const Fixed& one, const Fixed& other );

};

#endif