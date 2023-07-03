/* Run Time or Dynamic Polymorphism 
 * Done by function overriding
 * RULES:-
 * The method of the parent class and the method of the child class must have the same name and same parameters.
 * It is possible through inheritance only.
 */
#include <iostream>
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Speaking\n";
    }
};
class Dog: public Animal{
    public:
    void speak(){
        cout<<"Barking\n";
    }
};
int main(){
    Dog a;
    a.speak();
    return 0;
}