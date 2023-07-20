#include <bits/stdc++.h>
using namespace std;

// N QUEENS
// PS:- You are a given a N x N chess board and N queens and you are supposed to place those N queens on the chess board such that no two queens attack each other. You need to return all the correct possible combinations of the chess board and queen arrangement.
// Approach 1: TC=O(N!) and SC=O(N^2); The approach is to check every possible combination in the board (backtracking), we create a chess board whose all spaces are empty and then we place queens on it if the position is unattacked.
// bool isUnattacked(vector<string> &board, int row, int col, int n)
// {
//     // Here we only check the row, upper back diagonal and lower back diagonal because according to our code only squares behind the square in question will be filled and all the square ahead of this square will be empty.
//     int x = row, y = col;
//     while (y >= 0)
//     {
//         if (board[x][y--] == 'Q')
//             return false;
//     }
//     x = row, y = col;
//     while (x >= 0 && y >= 0)
//     {
//         if (board[x--][y--] == 'Q')
//             return false;
//     }
//     x = row, y = col;
//     while (x < n && y >= 0)
//     {
//         if (board[x++][y--] == 'Q')
//             return false;
//     }
//     return true;
// }
// void solve(vector<string> &board, vector<vector<string>> &ans, int col, int n)
// {
//     if (col == n)
//     {
//         ans.push_back(board);
//         return;
//     }
//     for (int row = 0; row < n; row++)
//     {
//         if (isUnattacked(board, row, col, n))
//         {
//             board[row][col] = 'Q';
//             solve(board, ans, col + 1, n);
//             board[row][col] = '.';
//         }
//     }
// }
// vector<vector<string>> solveNQueens(int n)
// {
//     string s;
//     for (int i = 0; i < n; i++)
//         s.push_back('.');
//     vector<string> board;
//     for (int i = 0; i < n; i++)
//         board.push_back(s);
//     vector<vector<string>> ans;
//     solve(board, ans, 0, n);
//     return ans;
// }
// Approach 2: Here we optimize the isUnattacked function to O(1) from O(n) using maps
void solve(vector<string> &board, vector<vector<string>> &ans, int col, int n, map<int, bool> &QinRow, map<int, bool> &QinUpperD, map<int, bool> &QinLowerD)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (!QinRow[row] && !QinUpperD[row + col] && !QinLowerD[n - 1 + col - row])
        {
            QinRow[row] = true, QinUpperD[row + col] = true, QinLowerD[n - 1 + col - row] = true;
            board[row][col] = 'Q';
            solve(board, ans, col + 1, n, QinRow, QinUpperD, QinLowerD);
            board[row][col] = '.';
            QinRow[row] = false, QinUpperD[row + col] = false, QinLowerD[n - 1 + col - row] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    string s;
    for (int i = 0; i < n; i++)
        s.push_back('.');
    vector<string> board;
    for (int i = 0; i < n; i++)
        board.push_back(s);
    vector<vector<string>> ans;
    map<int, bool> QinRow, QinUpperD, QinLowerD;
    solve(board, ans, 0, n, QinRow, QinUpperD, QinLowerD);
    return ans;
}

// SUDOKU SOLVER
// Approach: Its the usual backtracking approach. We check if number(1-9) we are trying to place is a valid option or not, if yes we move to the next empty block, else we try the next number, and if no number matches, we discard this solution and try the next one. TC=O(9^m), where m=>no. of empty cells and SC=O(1), because max recursive calls = 81 (countable).w
bool isSafe(vector<vector<char>> &board, int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val + 48 || board[i][col] == val + 48 || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val + 48)
            return false;
    }
    return true;
}
bool soln(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isSafe(board, row, col, i))
                    {
                        board[row][col] = i + 48;
                        bool isSol = soln(board);
                        if (isSol)
                            return true;
                        else
                            board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    soln(board);
}
int main()
{

    return 0;
}