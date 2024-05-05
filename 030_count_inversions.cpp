// PS: Count the number of inversions in an array
// BRUTE FORCE: Iss qstn mein hume ye batana hai ki ek array mein kitne aise pairs hai jisme bada element chhote element ke pehle aa rha hai. Jaise {1, 3, 2, 3, 1} array diya hai to isme total 3 inversions hai ({3, 2}, {3, 1}, {3, 1}). Basic method use kre to hum bas har element ke liye ye count kr lenge ki uske aage uss se chhote kitne elements hai. Isme time complexity O(n^2) rahegi.

// OPTIMAL: Apn merge sort ka use krenge. Jb apn do arrays ko merge kr rhe hote hai uss time pr inversions bhi count kr skte hai. Jaise {1, 3, 4, 6} aur {2, 5, 7} ko merge krna hai, to jb apn 3 aur 2 compare kr rhe honge tb pta lagega ki 3 to 2 se bada hai yaha pr inversion hai, pr total kitne inversions hai ye apne ko 'mid-i' se milega (mid => 2nd wale array ka starting point). 'mid-i' le rhe hai kyuki 3 apne 2 se bada mila hai to 3 ke aage jitne elements hai wo sb bhi 2 se bade hi honge.
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &nums, int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv = 0;
	i = k = left;
	j = mid;
	while (i < mid && j <= right)
	{
		if (nums[i] <= nums[j])
			temp[k++] = nums[i++];
		else
		{
			temp[k++] = nums[j++];
			inv += (mid - i);
		}
	}
	while (i < mid)
		temp[k++] = nums[i++];
	while (j <= right)
		temp[k++] = nums[j++];
	for (i = left; i <= right; i++)
		nums[i] = temp[i];
	return inv;
}
int mergeSort(vector<int> &nums, int temp[], int left, int right)
{
	int inv = 0, mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		inv += mergeSort(nums, temp, left, mid);
		inv += mergeSort(nums, temp, mid + 1, right);
		inv += merge(nums, temp, left, mid + 1, right);
	}
	return inv;
}
int countInversions(vector<int> &nums)
{
	int n = nums.size(), temp[n];
	return mergeSort(nums, temp, 0, n - 1);
}

int main()
{
	vector<int> nums = {1, 3, 2, 3, 1};
	cout << countInversions(nums);
	return 0;
}