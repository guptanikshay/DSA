#include <iostream>
using namespace std;
class Hero{
    private:
    int health;
    char level;
    public:
    void setHealth(int h){
    health=h;
    }
    void getHealth(){
    cout<<health<<"\n";
    }
    void setLevel(char l){
        level=l;
    }
    void getLevel(){
        cout<<level<<"\n";
    }
};
int main(){
    Hero a; // Static Allocation
    a.setHealth(39);
    a.setLevel('b');
    Hero *b = new Hero; // Dynamic Allocation
    // (*b).setHealth(69);
    // (*b).setLevel('a');
    b->setHealth(69);
    b->setLevel('a');
    b->getHealth();
    b->getLevel();
    a.getHealth();
    a.getLevel();
    return 0;
}