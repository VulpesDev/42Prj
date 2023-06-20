/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:43:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 11:02:25 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

int			Contact::Get_id(void)
{
	return (_id);
}

void		Contact::Set_id(int id)
{
	_id = id;
}

void	Contact::display(void) const
{
	std::cout << std::setw(10) << _id << "|";
	std::cout << std::setw(10) << (_first_name.length() > 10 ? _first_name.substr(0, 9).append(".") : _first_name.substr(0, 10)) << "|";
	std::cout << std::setw(10) << (_last_name.length() > 10 ? _last_name.substr(0, 9).append(".") : _last_name.substr(0, 10)) << "|";
	std::cout << std::setw(10) << (_nick_name.length() > 10 ? _nick_name.substr(0, 9).append(".") : _nick_name.substr(0, 10)) << std::endl;
}

void	Contact::assign(void)
{
	string	fname;
	string	lname;
	string	nname;
	string	phn;
	string	dsec;
	
	std::cout << "First Name: ";
	std::getline(std::cin, fname);
	std::cout << std::endl << "Last Name: ";
	std::getline(std::cin, lname);
	std::cout << std::endl << "Nickname: ";
	std::getline(std::cin, nname);
	std::cout << std::endl << "Phone Number: ";
	std::getline(std::cin, phn);
	std::cout << std::endl << "Darkest Secret: ";
	std::getline(std::cin, dsec);
	this->_first_name = fname;
	this->_last_name = lname;
	this->_nick_name = nname;
	this->_phone_number = phn;
	this->_darkest_secret = dsec;
	std::cout << std::endl;
	return ;
}

void	Contact::display_detail(void) const
{
	std::cout << "First Name: " << _first_name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nick_name << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest Secret: " << _darkest_secret << std::endl << std::endl;
}

Contact::Contact (void)
{
	_id = 0;
	return;
}

Contact::~Contact (void)
{
	return;
}