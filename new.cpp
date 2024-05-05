#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &nums, int temp[], int left, int mid, int right)
{
	cout << "Inside merge with " << left << " " << mid << " " << right << "\n";
	int i, j, k;
	int rev = 0;
	i = k = left;
	j = mid;
	while (i < mid && j <= right)
	{
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
		{
			if (nums[i] > 2 * nums[j])
				rev++;
			temp[k++] = nums[j++];
		}
	}
	while (i < mid)
		temp[k++] = nums[i++];
	while (j <= right)
		temp[k++] = nums[j++];
	for (i = left; i <= right; i++)
		nums[i] = temp[i];
	cout << left << " " << mid << " " << right << " " << " merge returned rev = " << rev << "\n\n";
	return rev;
}
int mergeSort(vector<int> &nums, int temp[], int left, int right)
{
	cout << "Inside mergeSort with " << left << " " << right << "\n";
	int rev = 0, mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		rev += mergeSort(nums, temp, left, mid);
		rev += mergeSort(nums, temp, mid + 1, right);
		rev += merge(nums, temp, left, mid + 1, right);
	}
	cout << left << " " << right << " mergeSort return rev = " << rev << "\n\n";
	return rev;
}
int reversePairs(vector<int> &nums)
{
	int n = nums.size(), ans = 0;
	int temp[n];
	int mid = (n - 1) / 2;
	ans += mergeSort(nums, temp, 0, mid);
	ans += mergeSort(nums, temp, mid + 1, n - 1);
	ans += merge(nums, temp, 0, mid + 1, n - 1);
	return ans;
}

int main()
{
	vector<int> nums = {1, 3, 2, 3, 1};
	cout << reversePairs(nums);
	return 0;
}