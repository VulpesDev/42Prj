/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:51:12 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 11:15:55 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>


class Weapon{

	public:
	const char	*getType();
	void		setType( std::string new_type );
	Weapon(std::string type);
	Weapon();
	~Weapon();

	private:
	std::string	_type;
};

#endif