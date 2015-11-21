/*
N queens problem
*/

#include <vector>

using std::vector;

class Solution 
{
private:
    vector<bool> isRow;    //This one can be eliminated. Since we iterate by row
    vector<bool> isCol;
    vector<bool> isDig1;  //(i + j)
    vector<bool> isDig2;  //(j - i + n - 1)
public:
    vector<vector<string>> solveNQueens(int n)
    {
        isRow.assign(n, false);
        isCol.assign(n, false);
        isDig1.assign(2 * n - 1, false);
        isDig2.assign(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ret;
        solveNQueens(board, n, 0, ret);
        return ret;
    }
    void solveNQueens(vector<string> &board, int n, int cnt, vector<vector<string>> &ret)
    {
        if(cnt == n)
        {
            ret.push_back(board);
            return;
        }

        for(int j = 0; j < n; ++j)
        {
            if(!isRow[cnt] && !isCol[j] && !isDig1[cnt + j] && !isDig2[j - cnt + n - 1])
            {
                isRow[cnt] = true;
                isCol[j] = true;
                isDig1[cnt + j] = true;
                isDig2[j - cnt + n - 1] = true;
                board[cnt][j] = 'Q';
                solveNQueens(board, n, cnt + 1, ret);
                isRow[cnt] = false;
                isCol[j] = false;
                isDig1[cnt + j] = false;
                isDig2[j - cnt + n - 1] = false;
                board[cnt][j] = '.';
            }
        }
    }
};