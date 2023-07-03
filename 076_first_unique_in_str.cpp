#include <bits/stdc++.h> 
using namespace std;
vector<char> firstNonRepeating(string stream) 
{
    // Write your code here
    queue <char> q;
    vector <char> ans;
    map <char, int> count;
    int n = stream.length();
    for(int i=0; i<n; i++){
        count[stream[i]]++;
        q.push(stream[i]);
        while(!q.empty()){
            if(count[q.front()]!=1)
            q.pop();
            else{
                ans.push_back(q.front());
                break;
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}