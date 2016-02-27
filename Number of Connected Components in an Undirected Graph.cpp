/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
        (each edge is a pair of nodes), write a function to find the number 
        of connected components in an undirected graph.

    Example 1:
         0          3
         |          |
         1 --- 2    4
    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

    Example 2:
         0           4
         |           |
         1 --- 2 --- 3
    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
*/
class UF
{
public:
    UF(int N):count(N), id(N), size(N, 0)
    {
        iota(id.begin(), id.end(), 0);
    }
    int find(int p)
    {
        if (p == id[p]) return p;
        return id[p] = find(id[p]);
    }
    void unite(int p, int q)
    {
        int i = find(p), j = find(q);
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
    int getCount()
    {
        return count;
    }
private:
    vector<int> id, size;
    int count;
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UF uf(n);
        for (auto &p : edges)
            uf.unite(p.first, p.second);
        return uf.getCount();
    }
};
