/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:22 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/10 10:57:01 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (_hit_points <= 0 || _energy_poitns <= 0)
	{
		std::cout << _name << " can't do anything"
		<< std::endl << "hit_points: " << _hit_points << " energy: " << _energy_poitns
		<< std::endl << std::endl;
		return ;
	}
	_energy_poitns--;
	std::cout << "ClapTrap " << _name << " attacks "
	<< target << ", causing " << _attack_damage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
}

ClapTrap::ClapTrap( void )
{
	_name = "Unnamed";
	std::cout << _name << " constructed" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name )
{
	_name = name;
	std::cout << _name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << _name << " destructor" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << _name << " copy constructor" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
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
