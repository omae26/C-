/* Polymorphism is the ability of being able to assign a different meaning or usage to something in different contexts and 
the property of an object responds to a query according to its type. */
/* adhoc polymorphism*/ 
/* It allows functions to work or to appera to work on several differnt types*/
#include <iostream>
using namespace std;
class brian{
    public:
    void show (int y){
        cout << "Display my integer value y: " << y << endl;
    }
    void show (double t){
        cout<< "Display my floating point value t: " << t << endl;
    }
    
};
int main(){
    brian br;
    br.show(7);
    br.show(8.14);
    return 0;
}

/* Output:
Display my integer value y: 7   
Display my floating point value t: 8.14 */
