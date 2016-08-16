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
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == '1')
                {
                    cnt++;
                    mark(grid, i, j);
                }
        return cnt;
    }
    
    void mark(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') return;
        
        grid[r][c] = '2';
        
        mark(grid, r - 1, c);
        mark(grid, r + 1, c);
        mark(grid, r, c - 1);
        mark(grid, r, c + 1);
    }
};

//union-find solution for the number of islandsII
class UF
{
public:
    UF(int N): count(N), size(N, 0), id(N) 
    {
        iota(id.begin(), id.end(), 0);
    }
    ~UF(){}
    int UFFind(int p)
    {
        if (p == id[p]) return;
        return id[p] = UFFind(id[p]);
    }
    int getCount() {return count;}
    bool UFUnion(int p, int q)
    {
        int i = UFFind(p), j = UFFind(q);
        if (i == j) return false;
        if (size[i] > size[j])
            id[j] = i;
        else if (size[i] < size[j])
            id[i] = j;
        else
        {
            id[j] = i;
            size[i]++;
        }
        count--;
        return true;
    }
private:
    int count;
    vector<int> size;
    vector<int> id;
};

class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int row = grid.size(), col = grid[0].size();
        UF myUF(row*col+1);
        int water = row*col;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == '1')
                {
                    //Union with right and down
                    if (i < row-1 && grid[i+1][j] == '1')
                        myUF.UFUnion(i*col+j, (i+1)*col+j);
                    if (j < col-1 && grid[i][j+1] == '1')
                        myUF.UFUnion(i*col+j, i*col+j+1);
                }
                else myUF.UFUnion(i*col+j, water);

        return myUF.getCount() - 1;
    }
};
