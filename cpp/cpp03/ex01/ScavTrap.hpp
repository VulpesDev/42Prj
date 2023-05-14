/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:35:03 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 11:12:55 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points = 100;
		int			_energy_poitns = 50;
		int			_attack_damage = 20;
	public:
		void	guardGate( void );
		void	attack(const std::string& target);
		ScavTrap( void );
		ScavTrap( std::string name );
		~ScavTrap( void );
		ScavTrap(const ScavTrap &other);
		ScavTrap&	operator=(const ScavTrap &other);
};

#endif
