# include "main.hpp"

void    replace(std::string& text, std::string target, std::string replacement){
    size_t position;

    position = text.find(target);
    while (position != std::string::npos && !target.empty()){
        text.erase(position, target.length());
        text.insert(position, replacement);
        position = text.find(target, position + replacement.length());
    }
}

void readFile(char **& avRef, std::ifstream & inFile){
    std::string fileContent(avRef[1]);
    std::ostringstream buffer;
    std::ofstream outFile(fileContent.append(".replace"));

    if (!outFile){
        std::cerr << "Error: Could not open the file!" << std::endl;
        inFile.close();
        exit(1);
    }
    buffer << inFile.rdbuf();
    fileContent = buffer.str();
    replace(fileContent, avRef[2] , avRef[3]);
    outFile << fileContent;
    outFile.close();
}

int main(int ac, char **av){
    if (ac == 4){
        std::ifstream inFile(av[1]);
        if (!inFile){
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
        readFile(av, inFile);
    }
    else
        std::cerr << "Invalid Number Of Arguments" << std::endl;
}