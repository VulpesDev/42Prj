/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:35:03 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 11:10:10 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points = 100;
		int			_energy_poitns = 100;
		int			_attack_damage = 30;
	public:
		void	highFivesGuys( void );
		void	attack(const std::string& target);
		FragTrap( void );
		FragTrap( std::string name );
		~FragTrap( void );
		FragTrap(const FragTrap &other);
		FragTrap&	operator=(const FragTrap &other);
};

#endif
