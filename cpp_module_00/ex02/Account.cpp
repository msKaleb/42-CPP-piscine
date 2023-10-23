/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:34:54 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/23 13:10:12 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	std::cout << "[ timestamp ] " << "index:" << Account::_nbAccounts << ";amount:"
		<< _amount << ";created" << std::endl;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void) // from 0 to last ---------
{
	Account::_nbAccounts--;
	std::cout << "[ timestamp ] " << "index:" << this->_accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "[ timestamp ] accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	std::cout << "[ timestamp ] index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << "[ timestamp ] index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount + deposit
		<< ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
		
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	permitted = true;
	
	if (withdrawal > this->_amount)
		permitted = false;
		// return (false);
	if (permitted)
	{
		std::cout << "[ timestamp ] index:" << this->_accountIndex
			<< ";p_amount:" << this->checkAmount()
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount - withdrawal
			<< ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	}
	else
	{
		std::cout << "[ timestamp ] index:" << this->_accountIndex
			<< ";p_amount:" << this->checkAmount()
			<< ";withdrawal:refused" << std::endl;
			return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;