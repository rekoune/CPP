# include "main.hpp"

void    replace(std::string& text, std::string& target, std::string& replacement){
    size_t position;

    position = text.find(target);
    while (position != std::string::npos && !target.empty()){
        text.erase(position, target.length());
        text.insert(position, replacement);
        position = text.find(target, position + replacement.length());
    }
}

void readFile(char **& avRef, std::ifstream & inFile){
    std::string line(avRef[1]);
    std::ofstream outFile(line.append(".replace"));
}

int main(int ac, char **av){
    (void)av;
    (void)ac;
    std::string str = "abdellah rekoune test hona\n";
    std::string str1 = "rekoune";
    std::string str2 = "";
    if (ac == 4){
        std::ifstream oldFile(av[1]);
        if (!oldFile)
            std::cerr << "Error: Could not open the file!" << std::endl;
    }
    else
        std::cerr << "Invalid Number Of Arguments" << std::endl;
    std::cout << str << std::endl;
}