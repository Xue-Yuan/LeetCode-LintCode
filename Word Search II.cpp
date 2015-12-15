/*
    Given a 2D board and a list of words from the dictionary, find 
        all words in the board.

    Each word must be constructed from letters of sequentially 
        adjacent cell, where "adjacent" cells are those horizontally 
        or vertically neighboring. The same letter cell may not be 
        used more than once in a word.

    For example,
        Given words = ["oath","pea","eat","rain"] and board =

        [
          ['o','a','a','n'],
          ['e','t','a','e'],
          ['i','h','k','r'],
          ['i','f','l','v']
        ]
        Return ["eat","oath"].
*/
struct trieNode
{
    vector<trieNode *> next;
    bool isWord;
    trieNode():isWord(false), next(26, nullptr){}
};

class trie
{
    //Make root public because later we'll manually do the search
public:
    trieNode *root;
private:
    void destory(trieNode *root)
    {
        if(!root)
            return;
        for (trieNode *t : root->next)
            if(t) destory(t);
        delete root;
    }
public:
    trie():root(new trieNode()){}
    ~trie(){ destory(root); }
    void insert(const string &s)
    {
        trieNode *t = root;
        for(auto &c : s)
        {
            if(!t->next[c - 'a'])
                t->next[c - 'a'] = new trieNode();
            t = t->next[c - 'a'];
        }
        t->isWord = true;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        if(board.empty() || board[0].empty() || words.empty()) return {};
        
        trie myTrie;
        for (auto &w : words)
            myTrie.insert(w);
        
        vector<string> ret;
        string s = "";
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                find(board, myTrie.root, i, j, s, ret);
        
        return ret;
    }
    
    //to mannually control the search process is more efficient
    //  than implementing a search method within the trie
    void find(vector<vector<char>>& board, trieNode* t, int r, int c, string &s_sofar, vector<string> &ret)
    {
        if(!t || r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '\0')
            return;
        
        if(!t->next[board[r][c] - 'a'])
            return;
        
        t = t->next[board[r][c] - 'a'];
        
        s_sofar += board[r][c];
        if(t->isWord)
        {
            ret.push_back(s_sofar);
            t->isWord = false;  //avoid duplicates
        }
        
        char visit = board[r][c];
        board[r][c] = '\0';
        
        find(board, t, r + 1, c, s_sofar, ret);
        find(board, t, r - 1, c, s_sofar, ret);
        find(board, t, r, c + 1, s_sofar, ret);
        find(board, t, r, c - 1, s_sofar, ret);
        
        s_sofar.pop_back();
        board[r][c] = visit;
    }    
};