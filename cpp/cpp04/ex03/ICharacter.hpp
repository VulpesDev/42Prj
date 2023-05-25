/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:37:53 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 12:07:21 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual void unequip(int idx) = 0;
		virtual void equip(AMateria* m) = 0;
		virtual std::string const & getName() const = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif	