/*
    Given a 2d grid map of '1's (land) and '0's (water), count 
        the number of islands. An island is surrounded by water 
        and is formed by connecting adjacent lands horizontally 
        or vertically. You may assume all four edges of the grid 
        are all surrounded by water.

    Example 1:

    11110
    11010
    11000
    00000
    Answer: 1

    Example 2:

    11000
    11000
    00100
    00011
    Answer: 3
*/
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if(grid.empty() || grid[0].empty()) return 0;
            int cnt = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    mark(grid, i, j);
                }
            }
        }
        return cnt;
    }
    
    void mark(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
        if(grid[r][c] == '0' || grid[r][c] == '2') return;
        
        grid[r][c] = '2';
        
        mark(grid, r - 1, c);
        mark(grid, r + 1, c);
        mark(grid, r, c - 1);
        mark(grid, r, c + 1);
    }
};