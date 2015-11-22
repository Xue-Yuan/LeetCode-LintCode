/*
	Given a m x n grid filled with non-negative numbers, find a path 
		from top left to bottom right which minimizes the sum of all 
		numbers along its path.

	Note: You can only move either down or right at any point in time.
*/

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < grid.size(); ++i)
            grid[i][0] += grid[i-1][0];
        for(int j = 1; j < grid[0].size(); ++j)
            grid[0][j] += grid[0][j-1];
        for(int i = 1; i < grid.size(); ++i)
            for(int j = 1; j < grid[0].size(); ++j)
            {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        return grid[m-1][n-1];
    }
};

//If we don't want to modify the original matrix
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int r = grid.size(), c = grid[0].size();
        
        vector<int> row(c + 1, INT_MAX);
        row[1] = 0;
        
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                row[j + 1] = min(row[j], row[j + 1]) + grid[i][j];
        
        return row[c];
    }
};