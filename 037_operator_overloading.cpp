#include <iostream>
using namespace std;

class madu{
    public:
    int a, b;
    int add(){
        return a+b;
    }
    void operator+ (madu &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"output "<<value2-value1<<endl;
    }
    void operator() (){
        cout<<"Hi there, I am bracket "<<this->a<<"\n";
    }
};
int main(){
    madu obj1, obj2;
    obj1.a=4;
    obj2.a=7;
    obj1+obj2;
    obj1();
    return 0;
}