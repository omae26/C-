/* cohersion polymorphism */
#include<iostream>
using namespace std;

class Integer{
    int value1;
    public:
        Integer(int r):value1(r) {}

        operator int() const {
            return value1;
        }
    
};
void display(int r){
    cout << "Our integer value  is: " << r << endl;
}
int main(){
    Integer r=98;
    display(100);
    display(r);
    return 0;
}
