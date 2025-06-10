/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:26 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 19:28:51 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);

    std::cout << "[" << (localTime->tm_year + 1900) << std::setw(2)
              << std::setfill('0') << (localTime->tm_mon + 1) << std::setw(2)
              << std::setfill('0') << localTime->tm_mday << "_" << std::setw(2)
              << std::setfill('0') << localTime->tm_hour << std::setw(2)
              << std::setfill('0') << localTime->tm_min << std::setw(2)
              << std::setfill('0') << localTime->tm_sec << "]";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    if (deposit > 0) {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
        _amount += deposit;
        _totalAmount += deposit;

        ++_nbDeposits;
        ++_totalNbDeposits;
        std::cout << ";deposit:" << deposit << ";amount:" << _amount
                  << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool Account::makeWithdrawal(int withdrawal) {
    bool status;

    _displayTimestamp();
    status = false;
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal <= _amount && withdrawal > 0) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;

        ++_nbWithdrawals;
        ++_totalNbWithdrawals;
        status = true;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    } else {
        std::cout << ";withdrawal:refused" << std::endl;
    }

    return status;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}
