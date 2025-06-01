# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef std::string String;

struct Data{
    String  studentName;
    float   FinalNote;
};

class Serializer{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer( Serializer & original);
        ~Serializer();
        Serializer& operator=( Serializer & original);
};


# endif