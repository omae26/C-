#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Define a base class named Employee
class Employee {
protected:
    // Protected member variables to store the name and salary of the employee
    string name;
    double salary;
public:
    // Constructor to initialize the Employee object with name and salary
    Employee(string n, double s) : name(n), salary(s) {}
};

// Define a derived class named Manager that inherits from Employee
class Manager : public Employee {
private:
    // Private member variable to store the department of the manager
    string department;
public:
    // Constructor to initialize the Manager object with name, salary, and department
    Manager(string n, double s, string d) : Employee(n, s), department(d) {}

    // Public method to display the details of the manager
    void showDetails() {
        // Output the name, salary, and department of the manager
        cout << "Name: " << name << "\nSalary: $" << salary 
             << "\nDepartment: " << department << endl;
    }
};

// Entry point of the program
int main() {
    // Create a Manager object with specific name, salary, and department
    Manager mgr("John Doe", 75000, "IT");

    // Call the showDetails method to print the manager's details
    mgr.showDetails(); // Output: Name, Salary, Department

    // Return 0 to indicate successful program execution
    return 0;
}