// PS: Check whether a given string is palindrome or not using recursion.
#include <iostream>
using namespace std;

bool checkPal(string str, int s=0){
    if(2*s>str.length()-1)
    return true;
    else if(str[s]!=str[str.length()-s-1])
    return false;    
    return checkPal(str, ++s);
}
int main(){
    string s="abbccdccbba";
    if(checkPal(s))
    cout<<s<<" is a Palindrome\n";
    else cout<<s<<" is not a Palindrome\n";
    return 0;
}