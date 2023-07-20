// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it. In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
// Your task is to return an array of strings that consists of all the possible paths that the rat can take to reach the destination.
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if (x>=0 && x < n && y>=0 && y < n && visited[x][y] != 1 && m[x][y] != 0)
        return true;
    return false;
}
void soln(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // Down
    int newx = x + 1, newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        soln(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }
    // Left
    newx = x, newy = y - 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('L');
        soln(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }
    // Right
    newx = x, newy = y + 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        soln(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }
    // Up
    newx = x - 1, newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        soln(m, n, newx, newy, visited, path + 'U', ans);
    }
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;
    int x = 0, y = 0;
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    string path = "";
    soln(m, n, x, y, visited, path, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<string> ans;
    int n = 4;
    vector<vector<int>> m;
    m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    ans = findPath(m, n);
    for (auto ele : ans)
        cout << ele << " ";
    cout << "\n";
    return 0;
}