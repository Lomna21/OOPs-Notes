#include<bits/stdc++.h>
using namespace std;

// Static methods are declared with the static keyword. They belong to the class itself rather than any particular object instance.
// Access: Static methods can be called using the class name directly, without needing to create an object of the class first.

// Non-static methods do not use the static keyword. They operate on data specific to each instance of the class.
// Access: Non-static methods can only be called through an instance (object) of the class.

void fun(){
    static int x; 
    // Static local variable are by default initialized to 0.
    // Static loacl variable lifetime is throughout the program.

    int y; // --> memory is only allocated when 'fun' is called and destroyes after work of fun is over. 
    // --> y will be created again and again whenever 'fun' is called but x will be created only once in the begining of the program.
}

class Account {
    private :
        int balance;       // Instance Member variable
        static float roi;  // Static member variable / Class variable
        // this is 'static member variable' --> defined outside the class.
        // Static member variable does not belong to any object, but to the whole class.
        // There will be only one copy of static member variable for the whole class.
        // Any object can use the same copy of class variable.
        
    public:
        void setBalance(int b){
            balance = b;
        }
        // Static Member Function
        // They can be invoked with or without object.
        // They can only access static members of the class.
        static void setRoi(float r){
            roi = r;
        }
        void show() {
            cout << "Balance: " << balance << " | Rate of Interest: " << roi << "%" << endl;
        }
}; 

// --> Declaration: The static member variable is declared inside the class with the static keyword. This declaration informs the compiler of the variable's type and name.
// --> Definition: A static member variable must be defined outside the class definition. This is because the declaration inside the class merely tells the compiler that the class has a static member variable.
float Account:: roi = 3.5;

int main(){
    Account a1,a2;
    // Access: Static members can be accessed using the class name (e.g., MyClass::staticVar) without creating an object of the class. It can also be accessed using the object.
    // --> 'balance' will be created for every object of the class.
    // --> but 'roi' will be created only once it does not depends on the number of object.

    a1.setBalance(1000);
    a2.setBalance(2000);

    // Accessing static member using class name
    Account::setRoi(4.5);  // --> this method can be used when we didn't created any object of the class.

    a1.show(); // Balance: 1000 | Rate of Interest: 4.5%
    a2.show(); // Balance: 2000 | Rate of Interest: 4.5%

    // Accessing static member using object (not recommended, but allowed)
    a1.setRoi(5.7);

    a1.show(); // Balance: 1000 | Rate of Interest: 5.7%
    a2.show(); // Balance: 2000 | Rate of Interest: 5.7%

    return 0;
}
