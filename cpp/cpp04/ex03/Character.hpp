/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:40:34 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 12:18:30 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	inventory[4];
	public:
		Character( std::string name );
		Character( const Character & other );
		Character&	operator=( const Character & other );
		~Character( void ) override;
		std::string const & getName( void ) const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif