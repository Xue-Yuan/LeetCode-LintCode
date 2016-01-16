/*
    Clone an undirected graph. Each node in the graph contains a 
        label and a list of its neighbors.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/**************************************/
/*    my initial INCORRECT solution   */
/**************************************/
/*
    The reason why it is wrong is because I shouldn't create a
        new node for every neighbor. Some neighbor should 
        refer to a node created before! But with merely an unordered_set
        we are not able to find it! We should use an unordered_map
        istead.
*/
class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        unordered_set<UndirectedGraphNode *> ust;
        UndirectedGraphNode *clone = nullptr;
        cloneGraph(clone, node, ust);
        return clone;
    }
    void cloneGraph(UndirectedGraphNode * &clone, UndirectedGraphNode * &node, unordered_set<UndirectedGraphNode *> &ust)
    {
        if(!node) return;
        clone = new UndirectedGraphNode(node->label);
        clone->neighbors.assign(node->neighbors.size(), nullptr);
        ust.insert(node);
        for(int i = 0; i < node->neighbors.size(); ++i)
        {
            if(ust.find(node->neighbors[i]) != ust.end()) continue;
            cloneGraph(clone->neighbors[i], node->neighbors[i], ust);
        }
    }
};
/***  The solution above is WRONG!!!  ***/
/****************************************/

/**         CORRECT SOLUTION           **/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution2 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        cloneGraph(node, m);
        return m[node];
    }
    
    void cloneGraph(UndirectedGraphNode *&node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &m)
    {
        if (!node) return;
        m[node] = new UndirectedGraphNode(node->label);
        for(auto &n : node->neighbors)
        {
            if(m.find(n) == m.end()) cloneGraph(n, m);
            m[node]->neighbors.push_back(m[n]);
        }
    }
};

/**************************************/
//This concise solution is taken from:
//https://leetcode.com/discuss/26440/9-line-c-dfs-solution
class Solution3 
{
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node) return node;
        if(hash.find(node) == hash.end())
        {
            hash[node] = new UndirectedGraphNode(node -> label);
            for (auto &n : node->neighbors)
                (hash[node]->neighbors).push_back( cloneGraph(n) );
        }
        return hash[node];
    }
};

//BFS
class Solution4 
{
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node) return node;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            //actually this will only be executed once, i.e.
            //  the first time. Because we cannot express a 
            //  disjoint graph with one node. So this sentence
            //  can be put outside the while loop, by doing which
            //  may promote the performance a little bit.
            if(map.find(t)  == map.end())   
                map[t] = new UndirectedGraphNode(t->label);
            for(auto &n : t->neighbors)
            {
                if(map.find(n) == map.end())
                {
                    map[n] = new UndirectedGraphNode(n->label);
                    map[t]->neighbors.push_back(map[n]);
                    q.push(n);
                }
                else
                    map[t]->neighbors.push_back(map[n]);
            }
        }
        return map[node];
    }
};
