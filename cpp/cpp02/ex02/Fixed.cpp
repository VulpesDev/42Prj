/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/06 12:39:29 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fbits = 8;

//*Constructors
Fixed::Fixed( const int n )
{
	_value = n << _fbits;
}

Fixed::Fixed( const float n )
{
	_value = roundf(n * (float)(1 << _fbits));
}

Fixed::Fixed( void )
{
	_value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::~Fixed( void )
{
	return ;
}

//*Convert functions
int		Fixed::toInt( void ) const
{
	return ((int)((float)this->_value / (float)(1 << _fbits)));
}

float		Fixed::toFloat( void ) const
{
	return (((float)this->_value / (float)(1 << _fbits)));
}

//*Overload functions
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << (float)((float)obj._value / (float)(1 << obj._fbits));
	return (os);
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if(this != &other){
		_value = other._value;
	}
	
	return (*this);
}
	//Comparison
bool	Fixed::operator>( const Fixed& other ) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return (this->_value != other._value);
}

	//Arithmetics
Fixed&	Fixed::operator+( const Fixed& other )
{
	Fixed	f(this->toFloat() + other.toFloat());
	*this = f;
	return (*this);
}

Fixed&	Fixed::operator-( const Fixed& other )
{
	Fixed	f(this->toFloat() - other.toFloat());
	*this = f;
	return (*this);
}

Fixed&	Fixed::operator*( const Fixed& other )
{
	Fixed	f((float)(this->toFloat() * other.toFloat()));
	*this = f;
	return (*this);
}

Fixed&	Fixed::operator/( const Fixed& other )
{
	Fixed	f(this->toFloat() / other.toFloat());
	*this = f;
	return (*this);
}

Fixed&	Fixed::operator++( void )
{
	_value += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);
	this->_value += 1;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);
	this->_value -= 1;
	return (tmp);
}

	//Specials
Fixed&	Fixed::min( Fixed& one, Fixed& other )
{
	return (one._value > other._value ? other : one);
}

const Fixed&	Fixed::min( const Fixed& one, const Fixed& other )
{
	return (one._value > other._value ? other : one);
}

Fixed&	Fixed::max( Fixed& one, Fixed& other )
{
	return (one._value < other._value ? other : one);

}

const Fixed&	Fixed::max( const Fixed& one, const Fixed& other )
{
	return (one._value < other._value ? other : one);
}

//*Raw functions
int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}