// Constructor is a member function of a class, whose name is the same as the class name.
// Constructor is a special type of member function that is used to initialize the data members for an object of a class automatically when an object of the same class is created.
// Constructors do not return value, hence they do not have a return type.
// A constructor gets called automatically when we create the object of the class.
// Constructor is used to solve problem of initilization.
// It must be an instance member function, that is it can never be static.
// Constructors can be overloaded.
// A constructor can not be declared virtual.

//Syntax for Defining the Constructor Within the Class
<class-name> (list-of-parameters)
{
     // constructor definition
}
//Syntax for Defining the Constructor Outside the Class
<class-name>::<class-name>(list-of-parameters)
{
     // constructor definition
}

// Types of constructors
    // 1. Default Constructor
    // 2. Parameterized Constructor
    // 3. Copy Constructor

// Important Note: Whenever we define one or more non-default constructors( with parameters ) for a class, a default constructor( without parameters ) should also be explicitly defined as the compiler will not provide a default constructor in this case. However, it is not necessary but it’s considered to be the best practice to always define a default constructor.

// DEFAULT CONSTRUCTOR
#include <iostream>
using namespace std;
class construct {
public:
	int a, b;
	// Default Constructor
	construct(){
		a = 10;
		b = 20;
	}
};
int main()
{
	// Default constructor called automatically when the object is created
	construct c;
	cout << "a: " << c.a << endl << "b: " << c.b;  // OUTPUT --> a: 10 b: 20
	return 1;
}


// PARAMETRIZED CONSTRUCTOR
//  Defining Parameterized Constructor Inside the Class.

class Point {
private:
	int x, y;

public:
	// Parameterized Constructor
	Point(int x1, int y1){
		x = x1;
		y = y1;
	}
	int getX() { return x; }
	int getY() { return y; }
};
int main(){
	// Constructor called
	Point p1(10, 15), p2=Point(11,12);

	// Access values assigned by constructor
	cout << "p1.x = " << p1.getX()<< ", p1.y = " << p1.getY(); // OUTPUT --> p1.x = 10, P1.y = 15
	cout << "p2.x = " << p2.getX()<< ", p2.y = " << p2.getY(); // OUTPUT --> p1.x = 11, P1.y = 12
	return 0;
}
 
// C++ Program to illustrate the error caused by not defining the explicit defualt constructor after parameterized constructor

class student {
	int rno;
	char name[50];
	double fee;

public:
	student(int no, char n[], double f)
	{
		rno = no;
		strcpy(name, n);
		fee = f;
	}
};
int main(){
	student s; // this will cause error (Important Note: Whenever we define one or more non-default constructors( with parameters ) for a class, a default constructor( without parameters ) should also be explicitly defined as the compiler will not provide a default constructor in this case. However, it is not necessary but it’s considered to be the best practice to always define a default constructor.)
	return 0;
}

// Defining Parameterized Constructor with Default Values

class GFG {
private:
	int data;

public:
	// parameterized constructor with default values
	GFG(int x = 0) { data = x; }
	int getData() { return data; }
};

int main(){

	GFG obj1; // will not throw error
	GFG obj2(25);

	cout << "First Object Data: " << obj1.getData() << endl; // OUTPUT --> First Object Data: 0
	cout << "Second Object Data: " << obj2.getData() << endl; // OUTPUT --> Second Object Data: 25
	return 0;
}

// 3. COPY CONSTRUCTOR
// Defining of Explicit Copy Constructor
class Sample {
	int id;

public:
	// default constructor with empty body
	Sample() {}

	// parameterized constructor
	Sample(int x){
        id = x;
    }

	// copy constructor
	Sample(Sample &t){  
        id = t.id; 
    }
	
	// --> If a copy constructor took its parameter by value, it would involve creating a copy of the argument being passed. Creating this copy would call the copy constructor again, resulting in infinite recursion and eventually causing a stack overflow.

	// Hypothetical incorrect copy constructor
	Sample(Sample t) {  // This would cause infinite recursion
    	id = t.id;
	}

	// Copy constructor
    Sample(const Sample &t) {
		// --> Const Qualification: The use of const ensures the original object cannot be modified, maintaining data integrity.
        id = t.id;
    }


	void display(){
        cout << "ID=" << id;
    }
};

int main(){
	Sample obj1(10);
	obj1.display();
	cout << endl;

	// copy constructor called
	Sample obj2(obj1); // or obj2=obj1;
	obj2.display();

	return 0;
}

