#include<iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
private:
    string _name="default name";
public:
    Animal(string name) : _name(name){}
    virtual~Animal(){}
    string& getname() { return _name; }
    virtual void makeSound()=0;
};

class Dog : public Animal
{
private:

public:
    Dog(string dogname):Animal(dogname){}
    ~Dog(){}
    void makeSound() { std::cout << "this is " <<&(Animal::getname())<< " sound" << endl; }
};

class Cat :public Animal
{
private:

public:
    Cat(string catname):Animal(catname){}
    ~Cat(){}
    void makeSound(){std::cout << "this is " << &(Animal::getname() )<< " sound" << endl; }
};

int main()
{
    Animal *animal[2];
    Dog *dog = new Dog("small dog");
    animal[0] = dog;
    Cat *cat = new Cat("small cat");
    animal[1] = cat;
    animal[0]->makeSound();
    animal[1]->makeSound();

    delete dog;
    delete cat;

    dog = nullptr;
    cat = nullptr;
    system("pause");
}