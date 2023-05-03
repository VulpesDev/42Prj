/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:16:42 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 14:34:09 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class	Harl{

	public:
	void	complain( std::string level);

	private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error ( void );

};

#endif