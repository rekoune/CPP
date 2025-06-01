# include "Serializer.hpp"

int main (){
    Data student1 = {"Ahmed", 15};
    Data *student2 = new Data;

    student2->studentName = "Ali";
    student2->FinalNote = 12;

    uintptr_t studentInt1 = Serializer::serialize(&student1);
    uintptr_t studentInt2 = Serializer::serialize(student2);

    Data* studentPtr1 = Serializer::deserialize (studentInt1);
    Data* studentPtr2 = Serializer::deserialize (studentInt2);

    std::cout << "student1 address: " << &student1 << std::endl;
    std::cout << "studentName = " << student1.studentName << ", student note = " << student1.FinalNote << std::endl;
    std::cout << "Serializing..." << std::endl;
    std::cout << "studentInt1 = " << studentInt1 << std::endl;
    std::cout << "Deserializing..." << std::endl;
    std::cout << "studentPt1 address: " << studentPtr1 <<std::endl;
    std::cout <<  "studentName = " << studentPtr1->studentName << ", student note = " << studentPtr1->FinalNote << std::endl;

    std::cout << "=========================================" << std::endl;

    std::cout << "student2 address: " << student2 << std::endl;
    std::cout << "studentName = " << student2->studentName << ", student note = " << student2->FinalNote << std::endl;
    std::cout << "Serializing..." << std::endl;
    std::cout << "studentInt2 = " << studentInt2 << std::endl;
    std::cout << "Deserializing..." << std::endl;
    std::cout << "studentPtr2 address: " << studentPtr2 <<std::endl;
    std::cout <<  "studentName = " << studentPtr2->studentName << ", student note = " << studentPtr2->FinalNote << std::endl;
    delete student2;
} 