/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
        (each edge is a pair of nodes), write a function to check whether 
        these edges make up a valid tree.

    For example:

        Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

        Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], 
            return false.

        Note: you can assume that no duplicate edges will appear in edges. 
            Since all edges are undirected, [0, 1] is the same as [1, 0] and 
            thus will not appear together in edges.
*/
class UF
{
public:
    UF(int N): count(N), size(N, 0), id(N)
    {
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int p)
    {
        if (p == id[p]) return p;
        return id[p] = find(id[p]);
    }
    
    bool unite(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i == j) return false;
        if (size[i] < size[j])
            id[i] = j;
        else if (size[j] < size[i])
            id[j] = i;
        else 
        {
            id[j] = i;
            size[i]++;
        }
        count--;
        return true;
    }
    int getCount() { return count; }
private:
    vector<int> size, id;
    int count;
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        UF uf(n);
        for (auto &p : edges)
        {
            if (!uf.unite(p.first, p.second)) return false;
        }
        return uf.getCount() == 1;
    }
};
