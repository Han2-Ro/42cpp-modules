#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return Account::_totalAmount;
}

int Account::getNbWithdrawals() {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
        << ";amount:"<< this->_amount
        << ";created" << std::endl;
}

Account::~Account() {
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;
}

void Account::makeDeposit(int deposit) {
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_totalNbWithdrawals += 1;
    if (withdrawal > this->_amount)
        return false;
    Account::_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    return true;
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {}

void Account::_displayTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    std::cout << '['
              << 1900 + ltm->tm_year
              << 1 + ltm->tm_mon
              << ltm->tm_mday
              << '_'
              << ltm->tm_hour
              << ltm->tm_min
              << ltm->tm_sec
              << "] ";
}

