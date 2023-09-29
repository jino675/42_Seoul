// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <iostream>

class Account {


public:

	typedef Account		t;


	static int	getNbAccounts(void) {
		return (_nbAccounts);
	}
	static int	getTotalAmount(void) {
		return (_totalAmount);
	}

	static int	getNbDeposits(void) {
		return (_totalNbDeposits);
	}
	static int	getNbWithdrawals(void) {
		return (_totalNbWithdrawals);
	}

	static void	displayAccountsInfos(void) {
		std::time_t	now = std::time(NULL);
		char		buffer[16];

		std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
		std::cout << "[" << buffer << "] accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" \
					<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
	}

	Account(int initial_deposit);
	~Account(void);

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account(void);
};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
