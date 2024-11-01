#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
    return Account::_nbAccounts;
}

int Account::getTotalAmount() {
    return Account::_totalAmount;
}

int Account::getNbWithdrawals() {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
        << ";total:" << _totalAmount
        << ";deposits:" << _totalNbDeposits
        << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

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
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
        << ";amount:"<< this->_amount
        << ";closed"<< std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    this->_nbDeposits += 1;
    this->_amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
        << ";p_amount:" << this->_amount - deposit
        << ";deposit:" << deposit
        << ";amount:"<< this->_amount
        << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
        << ";p_amount:" << this->_amount;
    if (withdrawal > this->_amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals += 1;
    this->_amount -= withdrawal;
    std::cout << ";withdrawal:" << withdrawal
        << ";amount:"<< this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
        << ";amount:"<< this->_amount
        << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::cout << "[19920104_091532] ";
}

