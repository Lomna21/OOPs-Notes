// A pure virtual function (or abstract function) in C++ is a virtual function for which we can have an implementation.
// But we must override that function in the derived class, otherwise, the derived class will also become an abstract class. A pure virtual function is declared by assigning 0 in the declaration.
// A class is abstract if it has at least one pure virtual function.

// Java abstract class is a class that can not be initiated by itself, it needs to be subclassed by another class to use its properties. An abstract class is declared using the “abstract” keyword in its class definition.

// By making a class abstract in C++, we cannot create objects of the abstract class directly because it contains one or more pure virtual functions. However, we can access and utilize the member functions of the abstract class by inheriting from it in a derived class and then creating objects of the derived class.

#include <iostream>
using namespace std;

// Abstract base class
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    void breathe() {
        cout << "Breathing..." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Implementing the pure virtual function
    void makeSound() override {
        cout << "Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    // Implementing the pure virtual function
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    // Animal a; // Error: Cannot instantiate an abstract class

    Dog dog;
    Cat cat;

    // Accessing inherited member functions
    dog.breathe(); // Inherited from Animal
    dog.makeSound(); // Overridden in Dog

    cat.breathe(); // Inherited from Animal
    cat.makeSound(); // Overridden in Cat

    return 0;
}




// ----------------------------------------------------------
// C++ program to illustrate the abstract class with pure virtual functions
#include <iostream>
using namespace std;
class Test {
	int x;
    public:
        virtual void show() = 0;
        int getX() { return x; }
};

int main(void){
	// Error: Cannot instantiate an abstract class
	Test t;    // Compiler Error: cannot declare variable 't' to be of abstract type 'Test' because the following virtual functions are pure within 'Test'

	return 0;
}
