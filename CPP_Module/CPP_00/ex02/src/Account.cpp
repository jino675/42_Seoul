/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:46:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/29 19:44:32 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)\
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" \
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit) : 
_accountIndex(_nbAccounts), _amount(initial_deposit),
_nbDeposits(0), _nbWithdrawals(0)
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];

	++_nbAccounts;
	_totalAmount += _amount;
	
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account(void) : 
_accountIndex(_nbAccounts), _amount(0),
_nbDeposits(0), _nbWithdrawals(0)
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];

	++_nbAccounts;
	
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];
	
	--_nbAccounts;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];
	
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << ";deposits:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];
	
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawals:";
	if (_amount < withdrawal) {
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	std::time_t	now = std::time(NULL);
	char		buffer[16];
	
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << buffer << "] index:" << _accountIndex << ";amount:" << _amount << ";deposits:" \
				<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}
