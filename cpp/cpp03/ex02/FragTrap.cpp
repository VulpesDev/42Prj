/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:50 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 11:04:18 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::highFivesGuys( void )
{
	std::cout << _name << " is requesting high-fives" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hit_points <= 0 || _energy_poitns <= 0)
	{
		std::cout << _name << " can't do anything"
		<< std::endl << "hit_points: " << _hit_points << " energy: " << _energy_poitns
		<< std::endl << std::endl;
		return ;
	}
	_energy_poitns--;
	std::cout << "FragTrap " << _name << " attacks "
	<< target << ", causing " << _attack_damage
	<< " points of damage!" << std::endl;
}

FragTrap::FragTrap( void )
{
	_name = "Unndamed";
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name )
{
	_name = name;
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << _name << " destructor" << std::endl;
	return ;	
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap " << _name << " copy constructor" << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
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
