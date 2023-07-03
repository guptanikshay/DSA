#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute force O(n^2)
bool canComplete(int index, vector<int> gas, vector<int> cost)
{
    int fuel = gas[index];
    int n = gas.size(), i = index;
    do
    {
        if (i == n - 1)
        {
            fuel = fuel - cost[i] + gas[0];
            i = 0;
        }
        else
        {
            fuel = fuel - cost[i] + gas[i + 1];
            i++;
        }
    } while (fuel >= cost[i] && i != index);
    if (i == index)
        return true;
    else
        return false;
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        if (gas[i] >= cost[i])
        {
            if (canComplete(i, gas, cost))
                return i;
        }
    }
    return -1;
}

// Approach 2: Optimal Approach
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int bal = 0, def = 0, start = 0, n = gas.size();
    for (int i = 0; i < n; i++)
    {
        bal += (gas[i] - cost[i]);
        if (bal < 0)
        {
            def += bal;
            start = i + 1;
            bal = 0;
        }
    }
    if (bal + def >= 0)
        return start;
    else
        return -1;
}
int main()
{

    return 0;
}