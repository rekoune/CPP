# include "Harl.hpp"

void Harl::debug ( void ){
    std::cout << "This is the debug" << std::endl;
}

void Harl::info ( void ){
    std::cout << "This is the info" << std::endl;
}

void Harl::warning ( void ){
    std::cout << "This is the warning" << std::endl;
}

void Harl::error ( void ){
    std::cout << "This is the error" << std::endl;
}

void Harl::complain( std::string level ){
    void (Harl::*functionsPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++){
        if (level == levels[i]){
            (this->*functionsPtr[i])();
            return;
        }
    }
    std::cout << "Invalid Level!" << std::endl;
}