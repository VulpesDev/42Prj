/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:31:47 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/28 19:09:24 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" <<
		_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	time = std::time(NULL);
	std::tm *const pTInfo = std::localtime(&time);
	std::cout << "["
	<< std::setfill('0') << std::setw(4) << 1900 + pTInfo->tm_year << std::setfill('0')
	<< std::setfill('0') << std::setw(2) << pTInfo->tm_mon 
	<< std::setfill('0') << std::setw(2) << pTInfo->tm_mday
	<< "_"
	<< std::setfill('0') << std::setw(2) << pTInfo->tm_hour
	<< std::setfill('0') << std::setw(2) << pTInfo->tm_min
	<< std::setfill('0') << std::setw(2) << pTInfo->tm_sec
	<< "]";	
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
	<< ";deposit:" << deposit << ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_nbWithdrawals++;
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
	<< ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
	<< ";nb_deposits:" << _nbWithdrawals
	<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}