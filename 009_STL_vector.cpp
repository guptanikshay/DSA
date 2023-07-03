#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;

    vector <int> a(5, 2); // Creates a vector of size 5 and initializes all the elements with 2.

    vector <int> last(a); // Copies entire vector 'a' to vector 'last'

    for(int i:last){
        cout<<i<<" ";
    }cout<<endl;
    cout<<v.capacity()<<"\n";
    v.push_back(1);

    cout<<v.capacity()<<"\n";
    v.push_back(3);

    cout<<v.capacity()<<"\n";
    cout<<v.size()<<"\n";
    v.push_back(9);

    cout<<v.capacity()<<"\n";
    cout<<v.size()<<"\n";
    v.push_back(4);

    cout<<"Element at index 2 "<<v.at(2)<<"\n";

    cout<<"Front = "<<v.front()<<"\n";
    cout<<"Back = "<<v.back()<<"\n";

    cout<<"Before pop = ";
    for(int i:v){
        cout<<i<<" ";
    }cout<<"\n";

    v.pop_back();

    cout<<"After pop = ";
    for(int i:v){
        cout<<i<<" ";
    }cout<<"\n";

    cout<<"Before Clear, size = "<<v.size()<<"\n";
    v.clear();
    cout<<"After Clear, size = "<<v.size()<<"\n";
    return 0;
}