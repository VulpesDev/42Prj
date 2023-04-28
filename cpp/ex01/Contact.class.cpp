/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:43:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/24 13:24:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void	Contact::display(void) const
{
	std::cout << std::setw(10) << this->id << "|";
	std::cout << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9).append(".") : first_name.substr(0, 10)) << "|";
	std::cout << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9).append(".") : last_name.substr(0, 10)) << "|";
	std::cout << std::setw(10) << (nick_name.length() > 10 ? nick_name.substr(0, 9).append(".") : nick_name.substr(0, 10)) << std::endl;
}

void	Contact::assign(void)
{
	char	fname[1000];
	char	lname[1000];
	char	nname[1000];
	char	phn[1000];
	char	dsec[1000];
	
	std::cout << "First Name: ";
	std::cin >> fname;
	std::cout << std::endl << "Last Name: ";
	std::cin >> lname;
	std::cout << std::endl << "Nickname: ";
	std::cin >> nname;
	std::cout << std::endl << "Phone Number: ";
	std::cin >> phn;
	std::cout << std::endl << "Darkest Secret: ";
	std::cin >> dsec;
	
	this->first_name = fname;
	this->last_name = lname;
	this->nick_name = nname;
	this->phone_number = phn;
	this->darkest_secret = dsec;
	std::cout << std::endl;
	std::cout << std::endl;
	return ;
}

void	Contact::display_detail(void) const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl << std::endl;
}

Contact::Contact (void)
{
	this->id = 0;
	return;
}

Contact::~Contact (void)
{
	return;
}