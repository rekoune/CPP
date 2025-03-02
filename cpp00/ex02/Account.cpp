# include "Account.hpp"
# include <iostream>
# include <ctime>
# include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){

}

Account::Account( int initial_deposit ){
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _nbAccounts++;
    _displayTimestamp();
    std::cout  << "index:"   << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

Account::~Account( void ){
   _displayTimestamp();
    std::cout << "index:"   << _accountIndex
              << ";amount:" << _amount
              << ";closed"  << std::endl;
}

void Account::displayAccountsInfos( void )
{
   _displayTimestamp();
    std::cout << "accounts:"     << _nbAccounts
              << ";total:"       << _totalAmount
              << ";deposits:"    << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void	Account::displayStatus( void ) const{
   _displayTimestamp();
    std::cout << "index:"        << _accountIndex
              << ";amount:"      << _amount
              << ";deposits:"    << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}

int		Account::checkAmount( void ) const{
    return (_amount);
}
void	Account::makeDeposit( int deposit ){
    _amount += deposit;
   _displayTimestamp();
    std::cout << "index:"        << _accountIndex
              << ";p_amount:"    << (_amount - deposit) 
              << ";deposit:"     << deposit
              << ";amount:"      << _amount
              << ";nb_deposits:" << ++_nbDeposits 
              << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}  

bool	Account::makeWithdrawal( int withdrawal ){
   _displayTimestamp();
    std::cout << "index:"     << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (_amount <= 50){
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal
              << ";amount:"         << (_amount -= withdrawal)
              << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    return (true);
}

 int	Account::getNbAccounts( void ){
    return (_nbAccounts);
}

 int	Account::getTotalAmount( void ){
    return (_totalAmount);
}

 int	Account::getNbDeposits( void ){
    return (_totalNbDeposits);
}

 int	Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp( void ){
    std::time_t currentTime = std::time(nullptr);
    std::tm* readableTime = std::localtime(&currentTime);

    std::cout << std::put_time(readableTime, "[%Y%m%d_%H%M%S] ");
}