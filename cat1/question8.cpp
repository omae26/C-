#include <iostream> 
// Include the iostream library for input and output operations
using namespace std;
 // Use the standard namespace to avoid prefixing std::

// Entry point of the program
int main() {
    // Declare and initialize an array of integers with 5 elements
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Declare a pointer to an integer and initialize it to point to the first element of the array
    int *ptr = arr;

    // Print a message indicating the start of array elements output
    cout << "Array elements:\n";

    // Loop through the array using the pointer to access each element
    for (int i = 0; i < 5; i++) {
        // Dereference the pointer (ptr + i) to access the value at the current index
        cout << *(ptr + i) << " "; // Output: 10 20 30 40 50
    }

    // Return 0 to indicate successful program execution
    return 0;
}