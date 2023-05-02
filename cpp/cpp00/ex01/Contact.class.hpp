/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:29:41 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/29 14:15:43 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <string>
# include <iomanip>
# include <iostream>

using	std::string;
class	Contact
{
	public:
		int			id;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		
		void		display(void) const;
		void		display_detail(void) const;
		void		assign(void);
		Contact(void);
		~Contact(void);
};

#endif