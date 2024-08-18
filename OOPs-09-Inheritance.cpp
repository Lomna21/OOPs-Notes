//  INHERITANCE --> It is a process of inheriting properties and behavours of existing class into a new class.

// ------Syntax-------- 
// class base_class_name{
// };
// class  derived_class_name : access-specifier  base_class_name{
//        //    body ....
// };
// --> If no access-specifier is used then it will be private by default.

// -------Types of Inheritance------
// 1. Single Inheritance
// 2. Multi level Inheritance
// 3. Multiple Inheritance
// 4. Hierarchical Inheritance
// 5. Hybrid Inheritace 

// C++ program to show that a derived class doesn’t inherit access to private data members.
// However, it does inherit a full parent object.

class A {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};
class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};
class D : private A{ // 'private' is default for classes
    // x is private
    // y is private
    // z is not accessible from D
};

// -------------------------------------------------
// C++ program to illustrate how to access the private data members of the base class in derived class using public getter methods of base class

#include <iostream>
using namespace std;

class Base {
    private:
        int privateVar;

    public:
        // Constructor to initialize privateVar
        Base(int val): privateVar(val){}

        // Public getter function to get the value of privateVar
        int getPrivateVar() const { return privateVar; }

        // Public setter function to set the value of privateVar
        void setPrivateVar(int val) { privateVar = val; }
};

class Derived : public Base {
public:
    
    // Constructor to initialize the base class
    Derived(int val) : Base(val){}

    // Function to display the private member of the base class
    void displayPrivateVar(){
        // Accessing privateVar using the public member function of the base class
        cout << "Value of privateVar in Base class: "<< getPrivateVar() << endl;
    }

    // Function to modify the private member of the base class
    void modifyPrivateVar(int val){
        // Modifying privateVar using the public member function of the base class
        setPrivateVar(val);
    }
};

int main(){
    // Create an object of Derived class
    Derived obj(10);
    obj.displayPrivateVar();   // Value of privateVar in Base class: 10
    obj.modifyPrivateVar(20);
    obj.displayPrivateVar();   // Value of privateVar in Base class: 20
    return 0;
}

// ----------------------------------------------------
// C++ program to illustrate how to access the private members of the base class by declaring the derived class as friend class in the base class

#include <iostream>
using namespace std;

// Forward declaration of the Derived class
class Derived;

class Base {
private:
    int privateVar;
public:
    // Constructor to initialize privateVar
    Base(int val) : privateVar(val){}
    
    // Declare Derived class as a friend
    friend class Derived;
};

class Derived {
public:
    // Function to display the private member of the baseclass
    void displayPrivateVar(Base& obj){
        // Accessing privateVar directly since Derived is a friend of Base
        cout << "Value of privateVar in Base class: "<< obj.privateVar << endl;
    }

    // Function to modify the private member of the base class
    void modifyPrivateVar(Base& obj, int val){
        // Modifying privateVar directly since Derived is a friend of Base
        obj.privateVar = val;
    }
};
int main(){
    // Create an object of Base class
    Base baseObj(10);
    Derived derivedObj;
    derivedObj.displayPrivateVar(baseObj);
    derivedObj.modifyPrivateVar(baseObj, 20);
    derivedObj.displayPrivateVar(baseObj);
    return 0;
}

// ------------------------------------------------------------
// Constructors and Destructors in Inheritance

// --> Constructors and Destructors are generally defined by the programmer and if not, the compiler automatically creates them so they are present in every class in C++. Now, the question arises what happens to the constructor and destructor when a class is inherited by another class.
// --> In C++ inheritance, the constructors and destructors are not inherited by the derived class, but we can call the constructor of the base class in derived class.

// --> The constructors will be called by the complier in the order in which they are inherited. It means that base class constructors will be called first, then derived class constructors will be called.
// --> The destructors will be called in reverse order in which the compiler is declared.

#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    public:
        A(int k){
            a=k;
        }
};
class B : public A{
    int b;
    public:
        B(int x, int y): A(x){
            b=y;
        }
};

int main(){
    B obj(2,3);
}