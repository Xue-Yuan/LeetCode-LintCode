/*
    Follow up for N-Queens problem.

    Now, instead outputting board configurations, return the total 
        number of distinct solutions.

    Example
        For n=4, there are 2 distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        col.assign(n, true);
        dig1.assign(2*n-1, true);
        dig2.assign(2*n-1, true);
        cnt = 0;
        dfs(n, 0);
        return cnt;
    }
private:
    void dfs(int n, int r)
    {
        if (r >= n)
        {
            cnt++;
            return;
        }
        for (int i = 0; i < n; ++i)
            if (col[i] && dig1[n-r+i-1] && dig2[r+i])
            {
                col[i] = dig1[n-r+i-1] = dig2[r+i] = false;
                dfs(n, r+1);
                col[i] = dig1[n-r+i-1] = dig2[r+i] = true;
            }
    }
private:
    vector<bool> col, dig1, dig2;
    int cnt;
};
