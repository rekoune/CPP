#include "./include/Animal.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"
#include "./include/Cat.hpp"
#include "./include/Dog.hpp"
#include "./include/Brain.hpp"


int main() {
    
    int     animalNumber = 4;
    Animal* animals[animalNumber];

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
    std::cout << "===================" << std::endl << std::endl;
    for (int i = 0; i < animalNumber; i++){
        if (i < animalNumber / 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for (int i = 0; i < animalNumber; i++)
        delete animals[i];

    std::cout << "===================" << std::endl << std::endl;
    Cat *cat =  new Cat();
    Brain *brain = new Brain();

    brain->ideas[0] = "test1";
    brain->ideas[1] = "test2";
    brain->ideas[2] = "test3";

    cat->setBrain(brain);
     Cat *cat2 = new Cat();
    *cat2 = *cat;
    delete cat;
    std::cout << cat2->getBrain()->ideas[1] << std::endl;
    delete cat2;
    delete brain;
return 0; 
}