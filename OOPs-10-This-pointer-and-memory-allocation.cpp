// ---------------THIS POINTER---------------------

// Each object gets its own copy of data members and all objects share a single copy of member functions.
// Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?

// The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

// 1) When local variable’s name is same as member’s name
#include<iostream> 
using namespace std; 

class Test{ 
    private: 
        int x; 
    public: 
        void setX (int x) 
        { 
            // The 'this' pointer is used to retrieve the object's x hidden by the local variable 'x' 
            this->x = x; 
        } 
        void print() { cout << "x = " << x << endl; } 
}; 

int main() { 
    Test obj; 
    int x = 20; 
    obj.setX(x); 
    obj.print();    // x = 20 
    return 0; 
} 

// -------------------------------------------------------
//When a reference to a local object is returned, the returned reference can be used to chain function calls on a single object.

#include<iostream> 
using namespace std; 
  
class Test { 
    private: 
        int x; 
        int y; 
    public: 
        Test(int x = 0, int y = 0) { this->x = x; this->y = y; } 
        Test &setX(int a) { x = a; return *this; } 
        Test &setY(int b) { y = b; return *this; } 
        void print() { cout << "x = " << x << " y = " << y << endl; } 
}; 
  
int main() { 
  Test obj1(5, 5); 
  
  // Chained function calls.  All calls modify the same object as the same object is returned by reference 
  obj1.setX(10).setY(20); 
  
  obj1.print();      // x = 10 y = 20
  return 0; 
} 



// Object destroy themselves by calling the following code :
delete this; 




// -------------Static Memory Allocation (SAM)---------------
// 1. Static Memory is allocated for declared variables by the compiler. The address can be found using the address of operator and can be assigned to a pointer. The memory is allocated during compile time. 
// 2. It uses stack for managing the static allocation of memory
// 3. In this memory allocation scheme, we cannot reuse the unused memory.
// 4. Example: This static memory allocation is generally used for array.
int x;
float y;
Complex c2;

// --------------Dynamic Memory Allocation (DMA)---------------
// 1. Memory allocation done at the time of execution(run time) is known as dynamic memory allocation. Functions calloc() and malloc() support allocating dynamic memory. 
// 2. It uses heap (not heap data structure) of memory for managing the dynamic allocation of memory.
// 3. This allows reusing the memory. The user can allocate more memory when required. Also, the user can release the memory when the user needs it.
// 4. Example: This dynamic memory allocation is generally used for linked list.
int *p = new int;
float *q = new float;
Complex *ptr = new Complex;
float *q = new float[5];     // for dynamic array
int x; cin>>x; int *p = new int[x];




