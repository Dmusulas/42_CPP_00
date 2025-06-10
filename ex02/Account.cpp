/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:26 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 19:50:00 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

static std::string _getLogFileName(void) {
    std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);

    std::ostringstream oss;
    oss << (localTime->tm_year + 1900) << std::setw(2) << std::setfill('0')
        << (localTime->tm_mon + 1) << std::setw(2) << std::setfill('0')
        << localTime->tm_mday << "_" << std::setw(2) << std::setfill('0')
        << localTime->tm_hour << std::setw(2) << std::setfill('0')
        << localTime->tm_min << std::setw(2) << std::setfill('0')
        << localTime->tm_sec << ".log";

    return oss.str();
}

void Account::_displayTimestamp(void) {
    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
    std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);

    logFile << "[" << (localTime->tm_year + 1900) << std::setw(2)
            << std::setfill('0') << (localTime->tm_mon + 1) << std::setw(2)
            << std::setfill('0') << localTime->tm_mday << "_" << std::setw(2)
            << std::setfill('0') << localTime->tm_hour << std::setw(2)
            << std::setfill('0') << localTime->tm_min << std::setw(2)
            << std::setfill('0') << localTime->tm_sec << "]";
    logFile.close();
}

void Account::displayAccountsInfos(void) {
    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
    _displayTimestamp();
    logFile << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
    logFile.close();
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;

    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
    _displayTimestamp();
    logFile << " index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
    logFile.close();
}

Account::~Account(void) {
    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
    _displayTimestamp();
    logFile << " index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
    logFile.close();
}

void Account::makeDeposit(int deposit) {
    if (deposit > 0) {
        std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
        _displayTimestamp();
        logFile << " index:" << _accountIndex << ";p_amount:" << _amount;
        _amount += deposit;
        _totalAmount += deposit;

        ++_nbDeposits;
        ++_totalNbDeposits;
        logFile << ";deposit:" << deposit << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
        logFile.close();
    }
}

bool Account::makeWithdrawal(int withdrawal) {
    bool status;
    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);

    _displayTimestamp();
    status = false;
    logFile << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal <= _amount && withdrawal > 0) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;

        ++_nbWithdrawals;
        ++_totalNbWithdrawals;
        status = true;
        logFile << ";withdrawal:" << withdrawal << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    } else {
        logFile << ";withdrawal:refused" << std::endl;
    }
    logFile.close();

    return status;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
    std::ofstream logFile(_getLogFileName().c_str(), std::ios::app);
    _displayTimestamp();
    logFile << " index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
    logFile.close();
}
