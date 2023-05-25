/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:26:47 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/25 14:52:24 by tvasilev         ###   ########.fr       */
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
	public:
		Contact	contact[8];
		int		len;
		int		current_contact;
		void	add(void);
		void	display(void);
		void	search(void);
		PhoneBook();
		~PhoneBook(void);
};

#endif