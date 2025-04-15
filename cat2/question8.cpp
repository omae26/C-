#include <iostream>
using namespace std;

// Base class Shape with a virtual area() method
class Shape {
public:
    virtual void area() { cout << "Shape area"; } // Default implementation
};

// Derived class Circle overriding the area() method
class Circle : public Shape {
public:
    void area() override { cout << "Circle area: πr²" << endl; }
};

// Derived class Rectangle overriding the area() method
class Rectangle : public Shape {
public:
    void area() override { cout << "Rectangle area: l×b" << endl; }
};

int main() {
    // Create objects of Circle and Rectangle using Shape pointers
    Shape *s1 = new Circle();
    Shape *s2 = new Rectangle();

    // Call the overridden area() methods
    s1->area(); // Output: Circle area: πr²
    s2->area(); // Output: Rectangle area: l×b

    // Free allocated memory
    delete s1, s2;

    return 0;
}