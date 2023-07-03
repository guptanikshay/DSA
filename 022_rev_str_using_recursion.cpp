// PS: Reverse a given string using recursion
#include <iostream>
#include <string>
using namespace std;
void swapS(char &a, char &b){
    char temp= a;
    a=b;
    b=temp;
}
void revStr(string &str, int s=0){
    if(2*s>str.length()-1)
    return;
    swapS(str[s], str[str.length()-s-1]);
    return revStr(str, s+1);
}
int main(){
    string s1="Suicide is never an option.";
    revStr(s1);
    cout<<"The reverse string is "<<s1;
    return 0;
}