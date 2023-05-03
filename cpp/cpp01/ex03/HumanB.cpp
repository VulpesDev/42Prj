/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:07:56 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}

HumanB::HumanB(std::string name)
{
	_name = name;
}

HumanB::~HumanB()
{
	return ;
}