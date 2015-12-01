/*
    Given two words (beginWord and endWord), and a dictionary's 
        word list, find all shortest transformation sequence(s) 
        from beginWord to endWord, such that:

    Only one letter can be changed at a time
    
    Each intermediate word must exist in the word list
    
    For example,

    Given:
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot","dot","dog","lot","log"]

    Return
      [
        ["hit","hot","dot","dog","cog"],
        ["hit","hot","lot","log","cog"]
      ]
*/

/*
    The idea is to keep trace of the path backward.
 
               --- ......end
             /     ......
            /      ......end
    start--------- ......
            \      ......
             \     ......end
               --- ......
 
    We start from the end, definitely ending up with the start.
*/

//Try bidirection BFS later.

class Solution
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<unordered_set<string>> level(2);     //We can't erase a word until one level ends. The same word may happen in different paths of the same level. But it won't occur is following levels, otherwise those paths cannot be shortest paths.
        int cur = 0, next = 1;
        unordered_map<string, vector<string>> trace;    //this is used to trace back and build the path.
        
        level[cur].insert(start);
        dict.insert(end);
        
        //BFS finding paths
        while (!level[cur].empty())
        {
            for (auto word : level[cur])
                dict.erase(word);
            for (auto word : level[cur])   //unordered_set don't allow change the key directly
            {
                string preWord = word;
                for (size_t i  = 0; i < word.size(); ++i)
                {
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if (word[i] == ch) continue;
                        swap(word[i],ch);
                        if (dict.find(word) != dict.end())
                        {
                            trace[word].push_back(preWord);
                            level[next].insert(word);
                        }
                        swap(word[i], ch);
                    }
                }
            }
            if(level[next].find(end) != level[next].end() || level[next].empty())
                break;
            level[cur].clear();
            swap(cur, next);
        }
        if (level[cur].empty())         //no such path
            return {};
        
        vector<vector<string>> ret;
        vector<string> path;
        buildPath(start, end, trace, path, ret);
        
        return ret;
    }
    
    //DFS building path
    void buildPath(const string &start, const string &cur, unordered_map<string, vector<string>> &trace, vector<string> &path, vector<vector<string>> &ret)
    {
        if (cur == start)
        {
            path.push_back(cur);
            ret.push_back({path.rbegin(), path.rend()});
            path.pop_back();
            return;
        }
        
        path.push_back(cur);
        for (auto & word : trace[cur])
            buildPath(start, word, trace, path, ret);
        path.pop_back();
    }
};