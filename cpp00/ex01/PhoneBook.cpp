#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact newContact)
{
    static int  contactIndex = 0;

    if (contactIndex > 7)
        contactIndex = 0;
    this->contacts[contactIndex] = newContact;
    if (contactsCount <= 7)
        contactsCount++;
    contactIndex++;
}
int PhoneBook::contactsCount = 0;

void PhoneBook::getContact(int index)
{
    this->contacts[index].getAllInfo();
}

void    PhoneBook::printChar(std::string str){
    size_t j;

    j = 0;
    if (str.size() < 10){
        j = 10 - str.size() ;
        for ( ; j > 0; j--)
            std::cout << " ";
    }
    for(size_t i = 0; i < 10 - j; i++){
        if (i == 9 && str.size() > 10)
            std::cout << ".";
        else if (i < str.size())
            std::cout << str[i];
    }
    std::cout << "|";
}

bool    PhoneBook::isNumber(std::string str){
    int i;

    i = 0;
    if (str.empty())
        return (false);
    if (str[i] == '+')
        i++;
    for( ; str[i]; i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

void    PhoneBook::getSearchDetails(Contact contact, int index)
{
    std::cout << "\t|         " << index << "|";
    printChar(contact.getFirstName());
    printChar (contact.getLastName()); 
    printChar(contact.getNickName());
    std::cout << std::endl;
}

void    PhoneBook::getAllContacts()
{
    std::string str;
    int         contactIndex;

    if (contactsCount){
        std::cout << "\t ================= PhoneBook ==============="<< std::endl;
        std::cout << "\t|   index  |First Name|Last  name| NickName |\n" << std::endl;
        for(int i = 0; i < contactsCount; i++){
            getSearchDetails(this->contacts[i], i);
        }
        std::cout << "\t ===========================================" << std::endl;
        while(true){
            std::cout << "\tEnter the Contact index : ";
            std::getline(std::cin, str);
            if (std::cin.eof())
                exit(0);
            if (!isNumber(str) || (contactIndex = std::atoi(str.c_str())) < 0 || contactIndex >= contactsCount)
                std::cout << "\tInvalid index, Please enter a valid one !" << std::endl;
            else{
                this->contacts[contactIndex].getAllInfo();
                break;
            }
        }
    }
    else
        std::cout << "\tThe Phone Book is Empty, Please Add Some Contacts !!" << std::endl;
}
