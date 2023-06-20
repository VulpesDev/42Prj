/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:14:41 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 12:54:26 by tvasilev         ###   ########.fr       */
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
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
	private:
		std::string	name;
};

void	randomChump(std::string name);

class Zombie	*newZombie(std::string name);

#endif
