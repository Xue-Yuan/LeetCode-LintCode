/*
    Sudoku Solver.
    Assume unique solution.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char>> &board, int row, int col)
    {
        if(row > 8)
            return true;
        nextAvailable(board, row, col);
        vector<bool> isValid(9, true);
        isValidTbale(board, row, col, isValid);
        for(int i = 1; i <=9; ++i)
        {
            if(isValid[i - 1])
            {
                board[row][col] = char(i + '0');
                int nrow = row, ncol = col;
                nextAvailable(board, nrow, ncol);
                if(solveSudoku(board, nrow, ncol))
                    return true;
                board[row][col] = '.';
            }
        }        
        return false;
    }
    void isValidTbale(vector<vector<char>> &board, int row, int col, vector<bool> &isValid)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(board[row][i] != '.') isValid[board[row][i] - '1'] = false;
            if(board[i][col] != '.') isValid[board[i][col] - '1'] = false;
            int subRow = row / 3 * 3 + i / 3, subCol = col / 3 * 3 + i % 3;
            if(board[subRow][subCol] != '.') isValid[board[subRow][subCol] - '1'] = false;
        }
    }
    void nextAvailable(vector<vector<char>> &board, int &row, int &col)
    {
        do 
        {
            if (board[row][col] == '.') return;
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
        } while (row < 9);
    }
};

int main()
{
    vector<vector<char>> b = {{'5','3','.','.','7','.','.','.','.'},
                              {'6','.','.','1','9','5','.','.','.'},
                              {'.','9','8','.','.','.','.','6','.'},
                              {'8','.','.','.','6','.','.','.','3'},
                              {'4','.','.','8','.','3','.','.','1'},
                              {'7','.','.','.','2','.','.','.','6'},
                              {'.','6','.','.','.','.','2','8','.'},
                              {'.','.','.','4','1','9','.','.','5'},
                              {'.','.','.','.','8','.','.','7','9'}};

    Solution so;
    so.solveSudoku(b);
    for(auto &r : b)
    {
        for(auto &c : r)
            cout << c << ' ';
        cout << endl;
    }
    return 0;
}