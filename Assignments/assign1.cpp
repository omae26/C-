#include <iostream>
using namespace std;

int main() {
    // Variables to store marks and total
    float marks[5], total = 0, average;
    char grade;

 // Input marks for 5 subjects
    cout << "Enter marks for 5 subjects (out of 100):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i]; // Calculate total marks
    }

    // Calculate average percentage
    average = total / 5.0;
    cout << "\nAverage Percentage: " << average << "%" << endl;

    // Determine grade using if-else
    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';

    cout << "Grade: " << grade << endl;

    // Provide recommendation using switch-case
    cout << "\nRecommendation: ";
    switch (grade) {
        case 'A': cout << "Excellent! Keep it up."; break;
        case 'B': cout << "Good, but you can improve."; break;
        case 'C': cout << "Average. Focus more on studies."; break;
        case 'D': cout << "Below average. Seek help."; break;
        case 'F': cout << "Fail. Attend remedial classes."; break;
        default: cout << "Invalid grade.";
    }

    return 0;
}