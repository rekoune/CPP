# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include "BTCDataLoader.hpp"
# include <fstream>

class BitcoinExchange {
    private:
        BitcoinExchange ();
        std::stringstream   resultStream;
        double              value;
        String              date;
        String              inputFileName;
        BTCDataLoader       BTCData;

    public:
        BitcoinExchange (const String& inputFileName);
        BitcoinExchange (const BitcoinExchange& original);
        BitcoinExchange& operator=(const BitcoinExchange& original);
        bool    loadInputData();
        void    checkLine(String& line);
        bool    checkDate (String& date, String& line);
        bool    checkValue (String& value, String& line);
        bool    isAlldigit (String& str);
        void    printResult( void);
        void    calculateValue (void);
        ~BitcoinExchange();
};

# endif