/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:44:24 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/12 15:49:33 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"

int	main( void )
{
	Ice	ic;
	Cure cur;

	std::cout << ic.getType() << std::endl;
	std::cout << cur.getType() << std::endl;
	return (0);
}