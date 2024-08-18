
// // ----------------------------------------------------------------------
// // Friend Function can become friend to more than one class.

// #include<bits/stdc++.h>
// using namespace std;

// class B; // we have define class B before otherwise 'fun' function in the class will not able to recognise B as it is defined after class A, so we need to define before A. 
// class A{
//     private:
//         int a;
//     public:
//     void setData(int x){ a=x; }
//     friend void fun(A,B);
// };
// class B{
//     private:
//         int b;
//     public:
//         void setData(int y){ b=y; }
//         friend void fun(A,B);
// };

// // Friend function can access private members of more than one class at a same time.
// void fun(A o1, B o2){
//     cout<<"Sum is : "<<o1.a+o2.b;
// }

// int main(){
//     A obj1; B obj2;
//     obj1.setData(2);
//     obj2.setData(3);
//     fun(obj1, obj2);
// }

// // -----------------------------------------------------------
// // Overloading of operator as a friend function

// #include<bits/stdc++.h>
// class Complex{
//     private:
//         int a,b;
//     public:
//         void setData( int x, int y){ a=x; b=y; }
//         void showData(){ cout<<" "<<a<<" "<<b<<endl; }

//         // We declare friend function inside the class and we define it outside the class.
//         // In friend function --> While overloadig we send exact number of parameters as required for the operation like "for binary - we send 2 parameters" and "for unary - we send one parameter".
//         friend Complex operator+(Complex, Complex); 

//         friend Complex operator-(Complex);
// };

// Complex operator+(Complex X, Complex Y){  // overloading binary operator
//     Complex temp;
//     temp.a = X.a + Y.a;
//     temp.b = X.b + Y.b;
//     return temp;
// }
// Complex operator-(Complex X){            // overloading unary operator
//     Complex temp; 
//     temp.a = -X.a;
//     temp.b = -X.b;
//     return temp;
// }
//  int main(){
//     Complex c1,c2,c3,c4;
//     c1.setData(3,4);
//     c2.setData(5,6);

//     // c3 = c1 + c2; --> for member function --> we read it as 'c3 = c1.operator(c2)'
//     c3 = c1 + c2;     // for friend function --> we read it as 'c3 = operator+(c1,c2)'
//     c3. showData();

//     // c4 = -c3;   --> for member function  --> we read it as 'c4 = c3.operator-();
//     c4 = -c3;       // for friend function  --> we read it as 'c4 = operator-(c3);
//  }

// // -------------------------------------------------------------
// // Member functin of one class can become friend to another class

// #include<bits/stdc++.h>
// using namespace std;

// class A{
//     public: 
//         void fun(){
//             // code lines
//         }
//         void foo(){
//             // code lines
//         }
// };

// class B{
//     friend class A; // From this statement we can access all the member function of class A in the class B.
    
//     friend void A::fun(); // by using scope resolution we can access any member function one by one.
//     friend void A::foo();
// };
 
//  // -----------------------------------------------------
//  // Overloading of insertion and extraction operator

// #include<bits/stdc++.h>
// using namespace std;

// class Complex{
//     private:
//         int a,b;

//     public:
//         void setData(int x,int y){
//             a=x;
//             b=y;
//         }
//         void showData(){
//             cout<<"a : "<<a<<" b : "<<b;
//         }
//         friend ostream& operator<<(ostream&, Complex);
//         friend istream& operator>>(istream&, Complex&);
// };
// ostream& operator<<(ostream &dout,Complex C){
//     cout<<"a : "<<C.a<<" b : "<<C.b;
//     return (dout);
// }
// istream& operator>>(istream &din, Complex &C){
//     cin>>C.a>>C.b;
// }

// int main(){
//     Complex c1;
//     cout<<"Enter a complex number";
//     cin>>c1;
//     cout<<"You Entered";
//     cout<<c1;      // operator<<(cout,c1);
// }
