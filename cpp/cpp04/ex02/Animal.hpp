/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:16:27 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/12 13:51:41 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
		Animal( void );
		Animal( const Animal& other );
		Animal&	operator=( const Animal& other);
		virtual ~Animal( void );
};

#endif