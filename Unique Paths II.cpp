/*
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many 
        unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in 
        the grid.

    For example,
        There is one obstacle in the middle of a 3x3 grid as 
            illustrated below.

        [
          [0,0,0],
          [0,1,0],
          [0,0,0]
        ]
        
        The total number of unique paths is 2.

    Note: m and n will be at most 100.
*/

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        vector<int> dp(obstacleGrid[0].size(), 0);
        dp[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i)
        {
            dp[0] = obstacleGrid[i][0] != 1 && dp[0];
            for (int j = 1; j < obstacleGrid[0].size(); ++j)
            {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j - 1];
            }
        }
        
        return dp.back();
    }
};