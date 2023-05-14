/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:13:15 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/07 14:18:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) 
{
	Point A(7.0f, 7.0f);
	std::cout << "X: " << A.x() << " Y: " << A.y() << std::endl; 
	Point B(11.0f, 1.0f);
	std::cout << "X: " << B.x() << " Y: " << B.y() << std::endl;  
	Point C(2.0f, 2.0f);
	std::cout << "X: " << C.x() << " Y: " << C.y() << std::endl;  
	Point P(4.0f, 4.9f);
	std::cout << "X: " << P.x() << " Y: " << P.y() << std::endl;
	std::cout << std::endl;

	std::cout << (bsp(A, B, C, P) ? "Yes" : "No") << std::endl;
	return 0;
}