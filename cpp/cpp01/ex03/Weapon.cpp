/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:10:44 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:05:51 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"
#include<iostream>

const char*	Weapon::getType()
{
	return _type.data();
}

void		Weapon::setType(std::string new_type)
{
	_type = new_type;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::Weapon()
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}
