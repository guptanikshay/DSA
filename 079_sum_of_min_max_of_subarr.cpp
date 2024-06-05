// You are given an array of size 'n' and an integer 'k'. Your task is to determine the sum of the minimum and maximum elements of all subarrays of size 'k'.
// A subarray is formed by deleting a few (possibly zero) elements from the front and back of an array.
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Run two loops to find all the subarrays, check the length of each subarray, whenever the length is equal to 'k', find the minimum and maximum element of that subarray and add it to the answer variable.
int SumOfKsubArray(int arr[], int N, int k)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int length = 0;
		for (int j = i; j < N; j++)
		{
			length++;
			if (length == k)
			{
				int maxi = INT_MIN;
				int mini = INT_MAX;
				for (int m = i; m <= j; m++)
				{
					maxi = max(maxi, arr[m]);
					mini = min(mini, arr[m]);
				}
				sum += maxi + mini;
			}
		}
	}
	return sum;
}

// OPTIMAL: We use the sliding window method using dequeue. For every window, we keep track of the maximum and minimum element.
long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
	// Write your code here.
	deque<long long int> maxi(k);
	deque<long long int> mini(k);
	for (int i = 0; i < k; i++)
	{
		while (!maxi.empty() && nums[maxi.back()] <= nums[i])
			maxi.pop_back();
		while (!mini.empty() && nums[mini.back()] >= nums[i])
			mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);
	}
	long long int ans = 0;
	ans = ans + nums[maxi.front()] + nums[mini.front()];
	for (int i = k; i < n; i++)
	{

		while (!maxi.empty() && i - maxi.front() >= k)
			maxi.pop_front();
		while (!mini.empty() && i - mini.front() >= k)
			mini.pop_front();

		while (!maxi.empty() && nums[maxi.back()] <= nums[i])
			maxi.pop_back();
		while (!mini.empty() && nums[mini.back()] >= nums[i])
			mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);
		ans = ans + nums[maxi.front()] + nums[mini.front()];
	}
	return ans;
}
int main()
{

	return 0;
}