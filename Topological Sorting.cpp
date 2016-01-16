/*
    Given an directed graph, a topological order of the graph nodes is 
        defined as follow:

    For each directed edge A -> B in graph, A must before B in the order 
        list.

    The first node in the order can be any node in the graph with no nodes 
        direct to it.
    
    Find any topological order for the given graph.
*/

//BFS
class Solution 
{
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) 
    {
        // write your code here
        unordered_map<DirectedGraphNode*, int> degree;
        for (auto &node : graph)
        {
            degree[node];
            for (auto &nb : node->neighbors)
                degree[nb]++;
        }
                
        queue<DirectedGraphNode *> q;
        for (auto &p : degree)
            if (p.second == 0) q.push(p.first);

        vector<DirectedGraphNode *> ret;
        while (!q.empty())
        {
            auto tmp = q.front(); q.pop();
            ret.push_back(tmp);
            for (auto &nb : tmp->neighbors)
                if (--degree[nb] == 0) q.push(nb);
        }
        return ret;
    }
};

//DFS
class Solution 
{
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) 
    {
        // write your code here
        unordered_map<DirectedGraphNode*, int> degree;
        for (auto &node : graph)
        {
            degree[node];
            for (auto &nb : node->neighbors)
                degree[nb]++;
        }

        vector<DirectedGraphNode *> ret;
        for (int i = 0; i < graph.size(); ++i)
            if (degree[graph[i]] == 0) dfs(graph[i], degree, ret);

        return ret;
    }

    void dfs(DirectedGraphNode *cur, unordered_map<DirectedGraphNode*, int> &degree, vector<DirectedGraphNode*> &ret)
    {
        ret.push_back(cur);
        --degree[cur];  //avoid duplicates. Think about it.
        for (auto &nb : cur->neighbors)
            if (--degree[nb] == 0) dfs(nb, degree, ret);
    }
};
