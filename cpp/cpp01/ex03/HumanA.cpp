/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:05:11 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:05:07 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void	HumanA::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}

HumanA::HumanA(std::string name, Weapon *weapon)
{
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA()
{
	return ;
}
