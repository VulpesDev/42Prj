/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:26:47 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 10:44:31 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.class.hpp"
# include <string>
# include <iomanip>
# include <iostream>


using	std::string;
class	PhoneBook
{
	private:
		Contact	_contact[8];
		int		_len;
		int		_current_contact;
	
	public:
		void	add(void);
		void	display(void);
		void	search(void);
		PhoneBook();
		~PhoneBook(void);
};

#endif