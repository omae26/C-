#include <iostream>
using namespace std;
class Geeks{
    public:
        void func(int y){
            cout << "Value of y is: " << y << endl;
        }
        void func(double y){
            cout << "Value of y is: " << y << endl;
        }
        void func(int y,int x){
            cout << "value of y and x is: " << y << ", " << x << endl;
        }
};
int main(){
    Geeks obj;
    obj.func(13);
    obj.func(9.234);
    obj.func(85,54);
    return 0;
}
// functionoverloading
// Output:
// Value of y is: 13
// Value of y is: 9.234
// value of y and x is: 85, 54
/*In the above code, we have defined three functions with the same 
name func but with different parameters. This is called function overloading.
 The compiler decides which function to call based on the number and type of arguments passed to the function.
  In the main function, we have created an object of the 
  Geeks class and called the func function with different arguments. 
  The compiler calls the appropriate function based on the arguments passed.*/