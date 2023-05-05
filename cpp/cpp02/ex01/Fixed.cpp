/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/05 19:24:26 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fbits;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (float)(1 << _fbits));
}

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

int		Fixed::toInt( void ) const
{
	return ((int)((float)this->_value / (float)(1 << _fbits)));
}

float		Fixed::toFloat( void ) const
{
	return (((float)this->_value / (float)(1 << _fbits)));
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignemnt operator called" << std::endl;
	if(this != &other){
		_value = other._value;
	}
	
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << (float)((float)obj._value / (float)(1 << obj._fbits));
	return (os);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}