/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:59 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:07:57 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class	HumanB{

	public:
	void	attack();
	void	setWeapon(Weapon *weapon);
	HumanB(std::string name);
	~HumanB();
	
	private:
	std::string	_name;
	Weapon		*_weapon;


};

#endif