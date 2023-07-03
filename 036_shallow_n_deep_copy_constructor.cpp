// The default copy constructor provided by the compiler uses shallow copy, whereas the user defined constructor uses deep copy.
#include <iostream>
using namespace std;

class Hero
{
private:
    int health;
    char level;

public:
    char *name;
    Hero()
    {
        cout<<"Default constructor called\n";
        name = new char[20];
    }
    // Hero(char *name, int health, char level)
    // {
    //     this->name = new char[20];
    //     this->name = name;
    //     this->health = health;
    //     this->level = level;
    // }
    void setHealth(int h)
    {
        health = h;
    }
    void getHealth()
    {
        cout << health << "\n";
    }
    void setLevel(char l)
    {
        level = l;
    }
    void getLevel()
    {
        cout << level << "\n";
    }
    void setName(char *name)
    {
        this->name = name;
    }
    void print()
    {
        cout << name << " " << health << " " << level << endl;
    }
};
int main()
{
    char name1[] = "Bhanu", name2[] = "Bhalu";
    Hero A;
    A.setName(name1);
    A.setHealth(69);
    A.setLevel('a');
    Hero B(A); // Shallow Copy, as no user defined constructor is present
    A.print();
    B.print();
    A.name[3]='l';
    A.print();
    B.print(); // Here also the name changes as in shallow constructor, no new memory is alloted to B and the same memory is accessed using different names.
    // Whereas in user defined copy constructor, deep copy is used. In this, new memory is allotted to B and the changes made in A are not reflected in B.
    // NOTE: Destructor for statically allocated classes is invoked automatically, but for dynamically allocated classes, it is required to invoke the destructor manually.
    return 0;
}