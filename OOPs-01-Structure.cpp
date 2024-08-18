// Basics of Class

#include<bits/stdc++.h>
using namespace std;

class Complex{
    private :
        int a,b;
    public :
        // This is the member function we have declared it inside the class, but we can also declare member function outside the class.
        void set_data(int x, int y){  // member function inside the class.
            a = x;
            b = y;
        }
        void show_data();// For declaring member function outside the class we need to define it inside the class.        
};

void Complex::show_data(){ // For defining outside the class we need to add 'MEMBERSHIP LABEL' in front of the function name.
    cout<<" "<<a<<" "<<b;
}

int main(){
    Complex c1;  // c1 is an object.
    c1.set_data(3,4);
    c1.show_data();
    return 0;
}
