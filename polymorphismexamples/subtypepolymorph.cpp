/* subtype polymrphism */
#include <iostream>
using namespace std;
class A {
    public: virtual void show() = 0;
};
class B : public A {
    public: void show() {
        cout << "This is my polymorphism" << endl;
    }
};
int main(){
    A *a; // base classpointer that we have created
    B b; // object of derived class
    a=&b;
    a->show();
    return 0;
}

// Output>>This is my polymorphism

/*This is calleda runtime polymorphism. In this example, 
we have created a base class pointer and assigned it to the derived class object. 
The show() function is called using the base class pointer.
*/ 
