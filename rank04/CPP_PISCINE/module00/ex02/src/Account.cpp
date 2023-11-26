#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	(void)_amount;
	(void)_nbDeposits;
	(void)_nbWithdrawals;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	Account::_nbAccounts--;
	Account::_totalAmount -= this->checkAmount();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "ammount:" << this->checkAmount() << ";";
	std::cout << "closed\n";
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << "\n";
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused\n";
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << "\n";
	return (true);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << "\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		*local;

	time = std::time(nullptr);
	local = std::localtime(&time);
	std::cout << "[" << local->tm_year + 1900;
	if (local->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << local->tm_mon + 1;
	if (local->tm_mday < 10)
		std::cout << "0";
	std::cout << local->tm_mday << "_";
	if (local->tm_hour < 10)
		std::cout << "0";
	std::cout << local->tm_hour;
	if (local->tm_min < 10)
		std::cout << "0";
	std::cout << local->tm_min;
	if (local->tm_sec < 10)
		std::cout << "0";
	std::cout << local->tm_sec << "]";
}
