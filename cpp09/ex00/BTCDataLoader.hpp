# ifndef BTCDATALOADER_HPP
# define BTCDATALOADER_HPP

# include <string>
# include <map>
# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>

typedef std::string String;


class BTCDataLoader {
    private:
        BTCDataLoader ();
        String dbName;
        std::map<String, float> BTCMap;
    public:
        BTCDataLoader (String dbName);
        BTCDataLoader (const BTCDataLoader& original);
        BTCDataLoader& operator=(const BTCDataLoader& original);
        ~BTCDataLoader();
        bool loadDataToMap ( void );
        std::map<String, float> getBTCMap (void);
};


# endif