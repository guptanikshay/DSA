#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, flag = 0;
	    cin>>n;
	    char s[n];
	    map<char, vector<int>> index;
	    for(int i=0; i<n; i++){
	        cin>>s[i];
	        index[s[i]].push_back(i);
	    }
	    if(n%3==1)
	    cout<<"YES\n";
	    else if(n%3==0){
	        for(auto i: index){
	            if(i.second.size()%3==0){
	                for(int j = 0; j<i.second.size()-1; j++){
	                    if((i.second[j+1]-i.second[j]-1)%3==0)
	                    flag=1;
	                    else
	                    flag=0;
	                }
	                if(flag){
	                    cout<<"YES\n";
	                    break;
	                }
	            }
	        }
	        if(!flag) cout<<"NO\n";
	    }
	    else{
	        for(auto i: index){
	            if(i.second.size()>1){
	                for(int j = 0; j<i.second.size()-1; j++){
	                    if((i.second[j+1]-i.second[j]-1)%3==0){
	                        flag=1;
	                        break;
	                    }
	                }
	                if(flag){
	                    cout<<"YES\n";
	                    break;
	                }
	            }
	        }
	        if(!flag) cout<<"NO\n";
	    }
	}
	return 0;
}
