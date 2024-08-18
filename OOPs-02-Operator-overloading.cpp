// B. OPERATOR OVERLOADING
// C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can make use of the addition operator (+) for string class to concatenate two strings. We know that the task of this operator is to add two operands. So a single operator ‘+’, when placed between integer operands, adds them and when placed between string operands, concatenates them.

// addition operator “+” is predefined to operate only on built-in data types. But here, “class A” is a user-defined type, so the compiler generates an error. This is where the concept of “Operator overloading” comes in.

// Operator functions are the same as normal functions. The only differences are, that the name of an operator function is always the operator keyword followed by the symbol of the operator, and operator functions are called when the corresponding operator is used. 

// Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded. 
// 1. sizeof
// 2. typeid
// 3. Scope resolution (::)
// 4. Class member access operators (.(dot), .* (pointer to member operator))
// 5. Ternary or conditional (?:)


#include<bits/stdc++.h>
using namespace std;

class Complex{
    private :
        int a,b;
    public :
        void set_data(int x, int y){
            a = x;
            b = y;
        }
        void show_data(){
            cout<<" "<<a<<" "<<b<<endl;
        } 

        Complex add(Complex c){
            Complex temp;
            // c3.a = c1.a + c2.a; --> below lines are read like this. 
            // c is c2 cause it is passed as an argument and c1 has called the function so we don't have to specify for that.
            temp.a = a + c.a;
            temp.b = b + c.b;
            return (temp);
        }

        // Operator overloading for '+'
        Complex operator+(Complex c){
            Complex temp;
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
        }

        Complex operator-(){
		Complex temp;
		temp.a = -a;
		temp.b = -b;
	}
};

class Integer {
	private :
		int x;
	public :
		void setData (int a){
			x=a;
		}
		void showData(){
			cout<<"x"<<x;
		}
		Integer operator++(){		  // Pre Increment
			Integer i;
			i.x = ++x;
			return i;
		}
		Integer operator++(int){      // Post Increment
			Integer i;
			i.x = x++;
			return i;
		}
};

int main(){
    Complex c1,c2,c3,c4;  // c1 is an object.
    c1.set_data(3,4);
    c2.set_data(5,6);
    
    c3 = c1.add(c2); // OUTPUT -- 8 10
    c3.show_data();
    // c1 is calling the 'add function' and c2 is going as an argument.

    // c3 = c1 + c2; --> it is not possible because c1,c2 are not primitive data type, they are of Complex type so we need to do it differently. But we can do it in this way by operator overloading.
    c4 = c1 + c3; // Using operator overloading  --->  Works as --> c4 = c1.operator+(c3);
    c4.show_data(); // OUTPUT -- 8 10

    // Unary operator overloading
	c4 =-c1;     // Works as --> c2 = c1.operator-();


    Integer i1,i2,i3,i4;
	i1.setData(3);
	i2 = i1++;          // Works as i2 = i1.operator++(); 

	i3.setData(6);
	i4=++i3;			// Works as i4 = i3.operator++();

    
    return 0;
}


