/*
    A 2d grid map of m rows and n columns is initially filled with water. 
        We may perform an addLand operation which turns the water at position 
        (row, col) into a land. Given a list of positions to operate, count 
        the number of islands after each addLand operation. An island is 
        surrounded by water and is formed by connecting adjacent lands 
        horizontally or vertically. You may assume all four edges of the grid 
        are all surrounded by water.

    Example:

    Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
    Initially, the 2d grid grid is filled with water. (Assume 0 represents 
    water and 1 represents land).

    0 0 0
    0 0 0
    0 0 0
    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

    1 0 0
    0 0 0   Number of islands = 1
    0 0 0
    Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

    1 1 0
    0 0 0   Number of islands = 1
    0 0 0
    Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

    1 1 0
    0 0 1   Number of islands = 2
    0 0 0
    Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

    1 1 0
    0 0 1   Number of islands = 3
    0 1 0
    We return the result as an array: [1, 1, 2, 3]
*/
class UF
{
public:
    UF(int N): count(0), id(N, -1), size(N, 0) {}
    ~UF(){}
    int getCount(){return count;}
    int UFFind(int p)
    {
        if (id[p] < 0) return -1;
        if (p == id[p]) return p;
        return id[p] = UFFind(id[p]);
    }
    void UFUnion(int p, int q)
    {
        int i = UFFind(p), j = UFFind(q);
        if (i == j) return;
        if (size[i] < size[j])
            id[i] = j;
        else if (size[i] > size[j])
            id[j] = i;
        else 
        {
            id[j] = i;
            size[i]++;
        }
        count--;
    }
    void add(int i)
    {
        if (id[i] >= 0) return;
        id[i] = i;
        count++;
    }
private:
    int count;
    vector<int> id, size;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) 
    {
        if (m <= 0 || n <= 0) return {};
        
        int dir[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        row = m, col = n;
        UF myUF(m*n);
        
        vector<int> ret;
        for (auto &p : positions)
        {
            int x = p.first, y = p.second;
            myUF.add(index(x, y));
            for (auto &d : dir)
            {
                int r = x+d[0], c = y+d[1];
                if (r >= 0 && r < row && c >= 0 && c < col && myUF.UFFind(index(r,c)) >= 0)
                    myUF.UFUnion(index(x, y), index(r, c));
            }
            ret.push_back(myUF.getCount());
        }
        return ret;
    }
private:
    int row, col;
    int index(int x, int y)
    {
        return x*col+y;
    }
};
