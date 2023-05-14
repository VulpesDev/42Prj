/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:48:34 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/06 17:12:11 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	return ;
}

Point::Point( const Point &other )
{
	*this = other;
}

Point&	Point::operator=( const Point &other )
{
	if(this != &other)
	{
		const_cast<Fixed&>(this->_x) = other.x();
		const_cast<Fixed&>(this->_y) = other.y();
	}
	
	return (*this);
}

Fixed	Point::x( void ) const
{
	return (_x);
}

Fixed	Point::y( void ) const
{
	return (_y);
}

Point::~Point( void )
{
	return ;
}
