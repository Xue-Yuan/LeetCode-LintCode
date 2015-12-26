/*
    For a undirected graph with tree characteristics, we can choose any node as the root. 
        The result graph is then a rooted tree. Among all possible rooted trees, those 
        with minimum height are called minimum height trees (MHTs). Given such a graph, 
        write a function to find all the MHTs and return a list of their root labels.

    Format
        The graph contains n nodes which are labeled from 0 to n - 1. You will be given 
            the number n and a list of undirected edges (each edge is a pair of labels).

        You can assume that no duplicate edges will appear in edges. Since all edges are 
            undirected, [0, 1] is the same as [1, 0] and thus will not appear together in 
            edges.

    Example 1:

        Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

            0
            |
            1
           / \
          2   3
        return [1]

    Example 2:

        Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

         0  1  2
          \ | /
            3
            |
            4
            |
            5
        return [3, 4]
*/

//remove leave layer by layer. The answer is(are) the node(s) left.

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (n == 1) return {0};
        
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        for (auto &p : edges)
        {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
            degree[p.first]++;
            degree[p.second]++;
        }
        
        queue<int> cur, next;
        for (int i = 0; i < degree.size(); ++i)
            if (degree[i] == 1)
                cur.push(i);
        
        //A node is considered deleted only when it gets out of the queue.
        while (n > 2)
        {
            while (!cur.empty())
            {
                auto node = cur.front();
                cur.pop();
                degree[node]--;
                n--;
                for (auto &i : graph[node])
                    if (--degree[i] == 1)
                        next.push(i);
            }
            swap(cur, next);
        }
        
        vector<int> ret;
        while (!cur.empty())
        {
            ret.push_back(cur.front());
            cur.pop();
        }
        return ret;
    }
};