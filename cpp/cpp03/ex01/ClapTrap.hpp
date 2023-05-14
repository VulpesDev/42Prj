/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:21:20 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/10 10:56:10 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points = 10;
		int			_energy_poitns = 10;
		int			_attack_damage = 0;
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap(const ClapTrap &other);
		ClapTrap&	operator=(const ClapTrap &other);
};

#endif