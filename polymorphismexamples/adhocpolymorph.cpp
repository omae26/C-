/* adhoc polymorphism*/ 
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
