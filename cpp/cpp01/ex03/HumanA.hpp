/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:54:47 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:04:47 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class	HumanA{

	public:
	void	attack();
	void	setWeapon(Weapon *weapon);
	HumanA(std::string name, Weapon *weapon);
	~HumanA();
	
	private:
	std::string	_name;
	Weapon		*_weapon;


};

#endif