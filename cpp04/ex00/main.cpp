#include "./include/Animal.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"
#include "./include/Cat.hpp"
#include "./include/Dog.hpp"

int main() {
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();


    std::cout << "type = " << cat->getType() << " " << std::endl; 
    cat->makeSound();
    std::cout << "type = " << animal->getType() << " " << std::endl; 
    animal->makeSound();
    std::cout << "type = " << dog->getType() << " " << std::endl; 
    dog->makeSound();

    delete animal;
    delete cat;
    delete dog;

    std::cout << "====================" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "type = " << wrongAnimal->getType() << " " << std::endl; 
    wrongAnimal->makeSound();
    std::cout << "type = " << wrongCat->getType() << " " << std::endl; 
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;

return 0; }