#include <iostream>
#include <fstream> // Required for file input and output operations
using namespace std;

int main() {
    // Create an output file stream to write to "students.txt"
    ofstream outFile("students.txt");
    string name; 
    int age;

    // Prompt the user to enter the student's name
    cout << "Enter student name: ";
    getline(cin, name); // Read the full name including the spaces

    // Prompt the user to enter the student's age
    cout << "Enter age: ";
    cin >> age; // Read the age as an integer

    // Write the name and age to the file in CSV format
    outFile << name << "," << age << endl;
    outFile.close(); // Close the output file stream

    // Open the file for reading using an input file stream
    ifstream inFile("students.txt");
    cout << "\nSaved Data:\n";

    // Read the entire line from the file (name and age)
    getline(inFile, name); 
    cout << name << endl; // Display the saved data on the console
    inFile.close(); // Close the input file stream

    return 0; // Indicate successful program termination
}
