/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:26:57 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 11:02:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->_len = 0;
	this->_current_contact = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	Contact contact;

	contact.assign();
	contact.Set_id(this->_current_contact);
	this->_contact[this->_current_contact] = contact;
	this->_current_contact++;
	if (this->_len < 8)
		this->_len++;
	if (this->_current_contact > 7)
		this->_current_contact = 0;
}

void	PhoneBook::display(void)
{
	std::cout << std::setw(10) << "ID" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < this->_len; ++i)
	{
		_contact[i].display();
	}
	std::cout << std::endl;
}

void	PhoneBook::search(void)
{
	int	index;

	index = 0;
	display();
	std::cout << "Enter index: ";
	std::cin >> index;
	while (std::cin.fail())	
	{
		std::cout << "Error" << std::endl;
		std::cout << "Enter index: ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> index;
	}
	if (index < 0 || index > 7 || index >= this->_len)
		std::cout << "Invalid index!" << std::endl;
	else
		_contact[index].display_detail();
}