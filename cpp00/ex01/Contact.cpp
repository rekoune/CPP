# include "Contact.hpp"

void Contact::setFirstName(std::string firstName){
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName){
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName){
    this->nickName = nickName;
}

void Contact::setDarkestSecret(std::string darkestSecret){
    this->darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber){
    this->phoneNumber = phoneNumber;
}

std::string Contact::getFirstName()
{
    return (this->firstName);
}
std::string Contact::getLastName()
{
    return (this->lastName);
}
std::string Contact::getNickName()
{
    return (this->nickName);
}
std::string Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}
std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

void    Contact::getAllInfo()
{
    std::cout << "\tFirst Name     : " << firstName << std::endl;
    std::cout << "\tLast Name      : " << lastName << std::endl;
    std::cout << "\tNickName       : " << nickName << std::endl;
    std::cout << "\tPhone Number   : " << phoneNumber << std::endl;
    std::cout << "\tDarkest Secret : " << darkestSecret << std::endl;
}