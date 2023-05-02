/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:50:22 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/02 18:20:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>


class	Zombie
{
	public:
		void	announce(void);
		void	setName(std::string name);
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		
	private:
		std::string	name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif