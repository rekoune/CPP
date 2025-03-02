#include "PhoneBook.hpp"

bool    isNumber(std::string str){
    int i;

    i = 0;
    if (str[i] == '+')
        i++;
    for( ; str[i]; i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

std::string getInput(std::string message, bool isNum)
{
    std::string input;

    while(true){
        std::cout << message;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !isNum)
            break;
        else if (!input.empty() && isNum && isNumber(input))
            break;
        else
            std::cout << "\tInvalid input, Please try again !" << std::endl;
    }
    return (input);
}

Contact    getUserInfo()
{
    Contact     newContact;
    
    newContact.setFirstName     (getInput("\tFirst Name      : ", false));
    newContact.setLastName      (getInput("\tLast Name       : ", false));
    newContact.setNickName      (getInput("\tNickName        : ", false));
    newContact.setPhoneNumber   (getInput("\tPhone Number    : ", true));
    newContact.setDarkestSecret (getInput("\tDarkest Secrect : ", false));
    std::cout << "\tNew Contact added Successfully" << std::endl;
    return (newContact);                                      
}

int main()
{
    PhoneBook phoneBook;
    Contact tset;
    std::string userInput;

    std::cout << "\t==================================================" << std::endl;
    std::cout << "\t= Enter one of three commands :                  =" << std::endl;
    std::cout << "\t=       ADD    : To add a new Contact.           =" << std::endl;
    std::cout << "\t=       SEARCH : To search for a Contact.        =" << std::endl;
    std::cout << "\t=       EXIT   : To exit from the PhoneBook.     =" << std::endl;
    std::cout << "\t==================================================" << std::endl;
    std::cout << std::endl;
    while(true)
    {
        std::cout << "\t\tEnter a Command ->  ";
        std::getline(std::cin, userInput);
        if (std::cin.eof())
            break;
        if (!userInput.compare("EXIT"))
            break;
        else if (!userInput.compare("ADD")){
            phoneBook.addContact(getUserInfo());
        }
        else if (!userInput.compare("SEARCH"))
            phoneBook.getAllContacts();
        else
            std::cout << "\tInvalid Command, Please enter a valid one !" << std::endl;
    }
}
