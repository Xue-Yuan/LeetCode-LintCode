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

/*
             +---------+      +---------+      +---------+      +---------+
    root --> |  [e]    | ---> |  [a]    | ---> |  [t]    | ---> |  []     |
             |isWord: F|      |isWord: F|      |isWord: F|      |isWord: T|
             +---------+      +---------+      +---------+      +---------+
*/
struct trieNode
{
    vector<trieNode *> next;
    bool isWord;
    trieNode(): next(26, nullptr), isWord(false){}
};

class Solution
{
private:
    void insert(trieNode *root, string &str)
    {
        for (auto &ch : str)
        {
            if (!root->next[ch - 'a']) root->next[ch - 'a'] = new trieNode();
            root = root->next[ch - 'a'];
        }
        root->isWord = true;
    }
    void destory(trieNode *root)
    {
        if (!root) return;
        for (auto &e : root->next)
            if (e) destory(e);
        delete root;
    }
    
    void findWords(vector<vector<char>>& board, int r, int c, trieNode *cur, string &path, vector<string> &ret)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] == '\0' || !cur->next[board[r][c] - 'a']) return;
        
        cur = cur->next[board[r][c] - 'a'];
        path += board[r][c];
        char save = board[r][c];
        board[r][c] = '\0';

        if (cur->isWord) 
        {
            ret.push_back(path);
            cur->isWord = false;
        }

        findWords(board, r + 1, c, cur, path, ret);
        findWords(board, r - 1, c, cur, path, ret);
        findWords(board, r, c + 1, cur, path, ret);
        findWords(board, r, c - 1, cur, path, ret);
        
        path.pop_back();
        board[r][c] = save;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        if (words.empty() || words[0].empty() || board.empty() || board[0].empty()) return {};
        root = new trieNode();
        for (auto &s : words)
            insert(root, s);
            
        string path = "";
        vector<string> ret;
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                findWords(board, i, j, root, path, ret);
        
        destory(root);
        return ret;
    }
private:
    trieNode *root;
};

//This unordered_set solution gives out the Time-Limit-Exceeded problem.
class Solution2 
{
public:
    vector<string> findWords(vector<vector<char>>& board, unordered_set<string>& words)
    {
        if (board.empty() || board[0].empty() || words.empty()) return {};
        string so_far = "";
        vector<string> ret;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                findWords(board, i, j, words, so_far, ret);

        return ret;
    }

    void findWords(vector<vector<char>> &board, int r, int c, unordered_set<string> &words, string &so_far, vector<string> &ret)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] == '\0') return;

        so_far += board[r][c];
        if (words.find(so_far) != words.end())
        {
            words.erase(so_far);
            ret.push_back(so_far);
        }

        char save = board[r][c];
        board[r][c] = '\0';
        findWords(board, r + 1, c, words, so_far, ret);
        findWords(board, r - 1, c, words, so_far, ret);
        findWords(board, r, c + 1, words, so_far, ret);
        findWords(board, r, c - 1, words, so_far, ret);
        board[r][c] = save;
        so_far.pop_back();
    }
};

