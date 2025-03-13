#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, marks;
    cin >> n;
    map<int, set<string>> list;
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> marks;
        list[marks].insert(name);
    }
    auto &it = --list.end();
    while (it != list.begin())
    {
        for (auto &name : it->second)
            cout << name << " " << it->first << "\n";
        it--;
    }
    for (auto &name : it->second)
        cout << name << " " << it->first << "\n";
}