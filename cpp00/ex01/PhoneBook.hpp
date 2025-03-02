# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        void    printChar(std::string str);
        bool    isNumber(std::string str);
    public:
        void    addContact(Contact newContact);
        void    getContact(int index);
        void    getAllContacts();
        void    getSearchDetails(Contact contact, int index);
        static  int contactsCount;
};

# endif