/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:42:25 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/06 17:12:28 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point( void );
		~Point( void );
		Point(const float x, const float y);
		Point( const Point &other );
		Point&	operator=( const Point &other );
		Fixed	x( void ) const;
		Fixed	y( void ) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
