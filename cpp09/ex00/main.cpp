# include "BTCDataLoader.hpp"


int main (){
    std::map<String, float> map;
    String token = "0";

    map["1"] = 1;
    map["3"] = 2;
    map["6"] = 3;
    std::map<String, float>::iterator it = map.find(token);

    if (map.begin()->first > token){
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if (it == map.end()){
        it = map.upper_bound(token);
        if (it == map.end())
            std::cout <<" a = " <<  (--map.end())->second << std::endl;
        else{
            std::cout << "b = " << (--it)->second << std::endl;

        }
    }
    else
        std::cout << " c = " << it->second << std::endl;
}
