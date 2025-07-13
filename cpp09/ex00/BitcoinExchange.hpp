# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange {
    public:
        BitcoinExchange ();
        BitcoinExchange (const BitcoinExchange& original);
        BitcoinExchange& operator=(const BitcoinExchange& original);
        ~BitcoinExchange();
};

# endif