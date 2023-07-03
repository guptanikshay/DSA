#include <iostream>
using namespace std;

int expo(int base, int pow){
    if(pow==0)
    return 1;
    if(pow==1)
    return base;
    int ans=expo(base, pow/2);
    if(pow&1)
    return base*ans*ans;
    else
    return ans*ans;
}
int main(){
    cout<<"2 to the power 10 is "<<expo(5, 5);
    return 0;
}