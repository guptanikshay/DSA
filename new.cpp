#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <string> board;
	string s;
	for(int i=0; i<4; i++) s.push_back('.');
	for(int i=0; i<4; i++) board.push_back(s);
	vector<vector<string>> ans;
	ans.push_back(board);
	s.clear();
	board.clear();
	for(int i=0; i<4; i++) s.push_back('-');
	for(int i=0; i<4; i++) board.push_back(s);
	ans.push_back(board);
	for(auto i: ans){
		for(auto j: i) cout<<j<<"\n";
	}
	return 0;
}