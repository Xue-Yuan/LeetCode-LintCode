/*
    Given a 2D binary matrix filled with 0's and 1's, find the 
        largest square containing all 1's and return its area.

    For example, given the following matrix:

        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0
        Return 4.
*/

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int cnt = 0;
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            dp[0][col] = matrix[0][col] == '1';
            cnt = max(cnt, dp[0][col]);
        }
        
        for (int row = 0; row < matrix.size(); ++row)
        {
            dp[row][0] = matrix[row][0] == '1';
            cnt = max(cnt, dp[row][0]);
        }
        
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    cnt = max(cnt, dp[i][j]);
                }
        return cnt * cnt;
    }
};

//With less space.
class Solution2
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        vector<vector<int>> dp(2, vector<int>(matrix[0].size(), 0));
        
        int cnt = 0;
        int cur = 0, next = 1;
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            dp[cur][col] = matrix[0][col] == '1';
            cnt = max(cnt, dp[cur][col]);
        }
        
        for (int i = 1; i < matrix.size(); ++i)
        {
            dp[next][0] = matrix[i][0] == '1';
            cnt = max(cnt, dp[next][0]);
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[next][j] = min(min(dp[cur][j], dp[next][j - 1]), dp[cur][j - 1]) + 1;
                    cnt = max(cnt, dp[next][j]);
                }
                else
                    dp[next][j] = 0;
            }
            swap(cur, next);
        }
        return cnt * cnt;
    }
};

//with even less space
class Solution3
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        vector<int> dp(matrix[0].size(), 0);
        
        int cnt = 0;
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            dp[col] = matrix[0][col] == '1';
            cnt = max(cnt, dp[col]);
        }
        
        for (int i = 1; i < matrix.size(); ++i)
        {
            int pre = dp[0];
            dp[0] = matrix[i][0] == '1';
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                int tmp = dp[j];
                if (matrix[i][j] == '1')
                {
                    dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
                    cnt = max(cnt, dp[j]);
                }
                else dp[j] = 0;
                pre = tmp;
            }
        }
        return cnt * cnt;
    }
};
