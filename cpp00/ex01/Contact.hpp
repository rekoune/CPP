# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getDarkestSecret();
        std::string getPhoneNumber();

        void        setFirstName(std::string firstName);
        void        setLastName(std::string lastName);
        void        setNickName(std::string nickName);
        void        setDarkestSecret(std::string darkestSecret);
        void        setPhoneNumber(std::string  phoneNumber);
        void        getAllInfo();
};

# endif