/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:50 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 10:49:13 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::guardGate( void )
{
	std::cout << _name << " is now in guard mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hit_points <= 0 || _energy_poitns <= 0)
	{
		std::cout << _name << " can't do anything"
		<< std::endl << "hit_points: " << _hit_points << " energy: " << _energy_poitns
		<< std::endl << std::endl;
		return ;
	}
	_energy_poitns--;
	std::cout << "ScavTrap " << _name << " attacks "
	<< target << ", causing " << _attack_damage
	<< " points of damage!" << std::endl;
}

ScavTrap::ScavTrap( void )
{
	_name = "Unndamed";
	std::cout << "ScavTrap " << _name << " constructed" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name )
{
	_name = name;
	std::cout << "ScavTrap " << _name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << _name << " destructor" << std::endl;
	return ;	
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap " << _name << " copy constructor" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << _name << " operator= called" << std::endl;
	if(this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_poitns = other._energy_poitns;
		_attack_damage = other._attack_damage;
	}
	
	return (*this);
}
