/*
    You want to build a house on an empty land which reaches all buildings 
        in the shortest amount of distance. You can only move up, down, left 
        and right. You are given a 2D grid of values 0, 1 or 2, where:

    Each 0 marks an empty land which you can pass by freely.
    Each 1 marks a building which you cannot pass through.
    Each 2 marks an obstacle which you cannot pass through.
    For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle 
        at (0,2):

            1 - 0 - 2 - 0 - 1
            |   |   |   |   |
            0 - 0 - 0 - 0 - 0
            |   |   |   |   |
            0 - 0 - 1 - 0 - 0
        The point (1,2) is an ideal empty land to build a house, as the total 
            travel distance of 3+3+1=7 is minimal. So return 7.

    Note:
        There will be at least one building. If it is not possible to build 
            such house according to the above rules, return -1.
*/
//https://leetcode.com/discuss/74453/36-ms-c-solution
class Solution 
{
public:
    int shortestDistance(vector<vector<int>> grid) 
    {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
        for (int i=0; i<m; ++i) 
            for (int j=0; j<n; ++j) 
                if (grid[i][j] == 1) 
                {
                    mindist = -1;
                    int dist = 0;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) 
                    {
                        dist++;
                        size_t q_sz = q.size();
                        for (size_t k = 0; k < q_sz; ++k)
                        {
                            auto ij = q.front(); q.pop();
                            for (int d=0; d<4; ++d) 
                            {
                                int x = ij.first + delta[d];
                                int y = ij.second + delta[d+1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == walk) 
                                {
                                    grid[x][y]--;
                                    total[x][y] += dist;
                                    q.emplace(x, y);
                                    if (mindist < 0 || mindist > total[x][y])
                                        mindist = total[x][y];
                                }
                            }
                        }
                    }
                    walk--;
                }
        return mindist;
    }
};
