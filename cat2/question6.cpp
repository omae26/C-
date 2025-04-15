#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Define a class named Car
class Car {
private:
    // Private member variables to store the brand, model, and year of the car
    string brand, model;
    int year;
public:
    // Constructor to initialize the Car object with brand, model, and year
    Car(string b, string m, int y) : brand(b), model(m), year(y) {}

    // Public method to display the details of the car
    void displayDetails() {
        // Output the brand, model, and year of the car
        cout << "Brand: " << brand << "\nModel: " << model 
             << "\nYear: " << year << endl;
    }
};

// Entry point of the program
int main() {
    // Create a Car object with specific brand, model, and year
    Car myCar("Toyota", "Corolla", 2020);

    // Call the displayDetails method to print the car's details
    myCar.displayDetails(); // Output: Brand, Model, Year

    // Return 0 to indicate successful program execution
    return 0;
}