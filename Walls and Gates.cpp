/*
    You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
    Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

    For example, given the 2D grid:
    INF  -1  0  INF
    INF INF INF  -1
    INF  -1 INF  -1
      0  -1 INF INF
    After running your function, the 2D grid should be:
      3  -1   0   1
      2   2   1  -1
      1  -1   2  -1
      0  -1   3   4
*/

class Solution 
{
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if (rooms.empty() || rooms[0].empty()) return;
        
        r = (int)rooms.size(), c = (int)rooms[0].size();
        
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (rooms[i][j] == 0) dfs(rooms, i, j, 0);
    }
private:
    void dfs(vector<vector<int>> &rooms, int x, int y, int dis)
    {
        if (x<0 || x>= r || y<0 || y>=c || rooms[x][y] < dis)
            return;
            
        rooms[x][y] = dis;
        dfs(rooms, x+1, y, dis+1);
        dfs(rooms, x-1, y, dis+1);
        dfs(rooms, x, y+1, dis+1);
        dfs(rooms, x, y-1, dis+1);
    }
private:
    int r, c;
};
