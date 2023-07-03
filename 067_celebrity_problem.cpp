#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack <int> s;
        for(int i=0; i<n; i++)
        s.push(i);
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b]==1)
            s.push(b);
            else
            s.push(a);
        }
        int ans = s.top(), isCeleb = 1;
        for(int i=0; i<n; i++){
            if(M[ans][i]==1)
            isCeleb=0;
        }
        for(int i=0; i<n; i++){
            if(i!=ans && M[i][ans]==0)
            isCeleb = 0;
        }
        if(isCeleb)
        return ans;
        return -1;
    }
};
int main(){
    
    return 0;
}