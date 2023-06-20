/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:29:41 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/28 16:13:37 by tvasilev         ###   ########.fr       */
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
	private:
		int			_id;
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		int			Get_id(void);
		void		Set_id(int id);
		
		void		display(void) const;
		void		display_detail(void) const;
		void		assign(void);
		Contact(void);
		~Contact(void);
};

#endif