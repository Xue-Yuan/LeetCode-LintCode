/*
N queens problem
*/
class Solution 
{
private:
    vector<bool> isCol, isDig1, isDig2;
public:
    vector<vector<string>> solveNQueens(int n)
    {
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
            if(!isCol[j] && !isDig1[cnt + j] && !isDig2[j - cnt + n - 1])
            {
                isCol[j] = isDig1[cnt + j] = isDig2[j - cnt + n - 1] = true;
                board[cnt][j] = 'Q';
                solveNQueens(board, n, cnt + 1, ret);
                isCol[j] = isDig1[cnt + j] = isDig2[j - cnt + n - 1] = false;
                board[cnt][j] = '.';
            }
    }
};
