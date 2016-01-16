/*
    There are a total of n courses you have to take, labeled from 0 
        to n - 1.

    Some courses may have prerequisites, for example to take course 0 
        you have to first take course 1, which is expressed as a pair: 
        [0,1]

    Given the total number of courses and a list of prerequisite pairs, 
        is it possible for you to finish all courses?

    For example:

        2, [[1,0]]
        There are a total of 2 courses to take. To take course 1 
            you should have finished course 0. So it is possible.

        2, [[1,0],[0,1]]
        There are a total of 2 courses to take. To take course 1 you 
            should have finished course 0, and to take course 0 you 
            should also have finished course 1. So it is impossible.
*/

//BFS
class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> degree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites)
        {
            degree[p.first]++;
            graph[p.second].push_back(p.first);
        }
        
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < degree.size(); ++i)
            if (degree[i] == 0) 
            {
                q.push(i);
                ++cnt;
            }
            
        while (!q.empty())
        {
            int tmp = q.front(); q.pop();
            for (int &nb : graph[tmp])
                if (--degree[nb] == 0) 
                {
                    q.push(nb);
                    ++cnt;
                }
        }
        
        return cnt == numCourses;
    }
};

//DFS
class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        for (auto &p : prerequisites)
        {
            graph[p.second].push_back(p.first);
            degree[p.first]++;
        }
            
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i)
            if (degree[i] == 0) dfs(graph, degree, i, cnt);
        
        return cnt == numCourses;
    }
    
    void dfs(vector<vector<int>> &graph, vector<int> &degree, int cur, int &cnt)
    {
        cnt++;
        degree[cur]--;
        for (int &nb : graph[cur])
            if (--degree[nb] == 0) dfs(graph, degree, nb, cnt);
    }
};
