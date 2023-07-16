// You are given an array of size 'n' and an integer 'k'. Your task is to determine the sum of the minimum and maximum elements of all subarrays of size 'k'. 
// A subarray is formed by deleting a few (possibly zero) elements from the front and back of an array.
#include <bits/stdc++.h> 
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	deque <long long int> maxi(k);
	deque <long long int> mini(k);
	for(int i=0; i<k; i++){
		while(!maxi.empty() && nums[maxi.back()]<=nums[i])
		maxi.pop_back();
		while(!mini.empty() && nums[mini.back()]>=nums[i])
		mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);
	}
	long long int ans = 0;
	ans = ans + nums[maxi.front()] + nums[mini.front()];
	for(int i=k; i<n; i++){

		while(!maxi.empty() && i-maxi.front()>=k)
		maxi.pop_front();
		while(!mini.empty() && i-mini.front()>=k)
		mini.pop_front();

		while(!maxi.empty() && nums[maxi.back()]<=nums[i])
		maxi.pop_back();
		while(!mini.empty() && nums[mini.back()]>=nums[i])
		mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);
		ans = ans + nums[maxi.front()] + nums[mini.front()];
	}
	return ans;
}
int main(){
    
    return 0;
}