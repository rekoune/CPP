# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
    : BTCData(BTCDataLoader("data.csv")){};

BitcoinExchange::BitcoinExchange(const String& inputFileName)
    : BTCData(BTCDataLoader("data.csv")) {
    this->inputFileName = inputFileName;
};

BitcoinExchange::BitcoinExchange( const BitcoinExchange& original)
    : BTCData(BTCDataLoader("data.csv")){
    *this = original;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& original){
    this->inputFileName = original.inputFileName;
    this->BTCData = original.BTCData;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){};

bool BitcoinExchange::isAlldigit(String& str){
    for(size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

bool    BitcoinExchange::checkDate(String& date, String& line){
    std::stringstream stringStream(date);
    String dateArray[4];
    long     day;
    long     month;
    int     i = 0;

    while (std::getline(stringStream, dateArray[i], '-')){
        if (dateArray[i].empty() || !isAlldigit(dateArray[i]) || i == 3){
            resultStream << "Error: bad input => " << line << "\n";
            return (false);
        }
        i++;
    }
    if (dateArray[0].length() != 4 || dateArray[1].length() != 2 || dateArray[2].length() != 2){
        resultStream << "Error: bad input => " << line << "\n";
        return (false);
    }
    month = std::strtol(dateArray[1].c_str(), NULL, 10); 
    day = std::strtol(dateArray[2].c_str(), NULL, 10);
    if (month <= 0 || month > 12 || day <= 0 || day > 31 || (month == 2 && day > 29)){
        resultStream << "Error: bad input => " << line << "\n";
        return (false);
    }
    this->date = date;
    return (true);
}

bool    BitcoinExchange::checkValue(String& value, String& line){
    char    *rest;
    double  number;

    number =  std::strtod(value.c_str(), &rest);
    if (number < 0){
        resultStream << "Error: not a positive number.\n";
        return (false);
    }
    else if (rest[0] != '\0'){
        resultStream << "Error: bad input => " << line << "\n";
        return (false);
    }
    else if ( number > 1000){
        resultStream << "Error: too large a number.\n";
        return (false);
    }
    this->value = number;
    return (true);

}

void    BitcoinExchange::checkLine( String& line){
    std::stringstream stringStream(line);
    String  data[4];
    int i = 0;

    if (line.empty())
        return;
    if (line.at(line.length() - 1) == ' '){
        resultStream << "Error: bad input => " << line << "\n";
        return;
    }
    while(std::getline(stringStream, data[i], ' ')){ 
        if (data[i].empty() || (i == 1 && data[i] != "|") || i == 3){
            resultStream << "Error: bad input => " << line << "\n";
            return;
        }
        i++;
    }
    if (i != 3){
        resultStream << "Error: bad input => " << line << "\n";
        return;
    }
    if(checkDate(data[0], line)){
        if (checkValue(data[2], line))
           calculateValue();
    }
}

void BitcoinExchange::calculateValue( void){
    std::map<String, float>::iterator it;
    std::map<String, float> BTCMap;
    double resultValue;

    BTCMap = BTCData.getBTCMap();
    it = BTCMap.find(date);
    if (it == BTCMap.end()){
        if (date < BTCMap.begin()->first){
            resultStream << "Error: invalid date " << date << "\n";
            return;
        }
        it = BTCMap.upper_bound(date);
        resultValue = (--it)->second * value;
    }
    else
        resultValue = it->second * value;
    resultStream << date << " => " << value << " = " << resultValue << "\n";
}

bool    BitcoinExchange::loadInputData (){
    std::ifstream inputFile(inputFileName);
    if (!BTCData.loadDataToMap())
        exit(1);
    if (!inputFile.is_open())
        return (false);
    String line;
    std::getline(inputFile, line);
    if (line != "date | value")
        resultStream << "Error: messing \"date | value\" at the begining\n";
    while(std::getline(inputFile, line)){
        checkLine(line);
    }
    inputFile.close();
    return (true);
}

void BitcoinExchange::printResult(void ){
    std::cout << resultStream.str();
}