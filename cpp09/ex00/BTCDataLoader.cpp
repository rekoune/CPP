# include "BTCDataLoader.hpp"

BTCDataLoader::BTCDataLoader(){};

BTCDataLoader::BTCDataLoader( String dbName ){
    this->dbName = dbName;
};

BTCDataLoader::BTCDataLoader( const BTCDataLoader& original){
    *this = original;
}

BTCDataLoader& BTCDataLoader::operator=( const BTCDataLoader& original){
    if (this != &original){
        this->dbName = original.dbName;
        this->BTCMap = original.BTCMap;
    }
    return (*this);
}
BTCDataLoader::~BTCDataLoader(){};

bool BTCDataLoader::loadDataToMap( void ){
    std::ifstream dbFile(dbName);
    if (!dbFile.is_open()){
        std::cerr << "Error: could not open the database file" << std::endl;
        return false;
    }
    String line;
    String date;
    String value;
    std::getline(dbFile, line);
    while(std::getline(dbFile, line)){
        std::stringstream stringStream(line);
        getline(stringStream, date, ',');
        getline(stringStream, value);
        BTCMap.insert(std::pair<String, float>(date, std::strtod(value.c_str(), NULL)));
    }
    dbFile.close();
    return (true);
} 

 std::map<String, float> BTCDataLoader::getBTCMap (void){
    return (this->BTCMap);
 }