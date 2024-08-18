// A destructor is also a special member function like a constructor. Destructor destroys the class objects created by the constructor. 
// Destructor has the same name as their class name preceded by a tilde (~) symbol.
// It is not possible to define more than one destructor. 
// The destructor is only one way to destroy the object created by the constructor. Hence destructor can-not be overloaded.
// Destructor neither requires any argument nor returns any value.
// It is automatically called when an object goes out of scope. 
// Destructor release memory space occupied by the objects created by the constructor.
// In destructor, objects are destroyed in the reverse of an object creation.

// The syntax for defining the destructor within the class:
~ <class-name>() {
    // some instructions
}

//The syntax for defining the destructor outside the class:
<class-name> :: ~<class-name>() {
    // some instructions
}

// Note: destructor can also be called explicitly for an object.
object_name.~class_name()

// C++ program to demonstrate the number of times constructor and destructors are called
#include <iostream>
using namespace std;
static int Count = 0;	 //It is static so that every class object has the same value 
class Test {
public:
	// User-Defined Constructor
	Test(){
		// Number of times constructor is called
		Count++;
		cout << "No. of Object created: " << Count << endl;
	}
	// User-Defined Destructor
	~Test(){
		cout << "No. of Object destroyed: " << Count << endl; //It will print count in decending order 
        Count--;
	}
};

// driver code
int main(){
	Test t, t1, t2, t3;
	return 0;
}
// OUTPUT
// No. of Object created: 1
// No. of Object created: 2
// No. of Object created: 3
// No. of Object created: 4
// No. of Object destroyed: 4
// No. of Object destroyed: 3
// No. of Object destroyed: 2
// No. of Object destroyed: 1