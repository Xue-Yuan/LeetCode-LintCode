/*
    Design a data structure that supports the following two operations:

        void addWord(word)
        bool search(word)
    
    search(word) can search a literal word or a regular expression 
        string containing only letters a-z or .. A . means it can 
        represent any one letter.

    For example:

        addWord("bad")
        addWord("dad")
        addWord("mad")
        search("pad") -> false
        search("bad") -> true
        search(".ad") -> true
        search("b..") -> true

    Note:
    You may assume that all words are consist of lowercase letters a-z.
*/

//Always initialize your data instances
class WordDictionary {
public:
    WordDictionary(){root = new Node();}
    ~WordDictionary() {destory(root);}

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        Node *t = root;
        for (char &ch : word)
        {
            if (!t->next[ch-'a']) t->next[ch-'a'] = new Node();
            t = t->next[ch-'a'];
        }
        t->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return search(word, 0, root);
    }
private:
    struct Node
    {
        vector<Node *> next;
        bool isWord;
        Node():next(26, nullptr), isWord(false){}
    };
    Node *root;
private:
    void destory(Node *root)
    {
        for (size_t i = 0; i < 26; ++i)
            if (root->next[i]) destory(root->next[i]);
        delete root;
    }
    bool search(string &word, size_t idx, Node *t)
    {
        if (!t) return false;
        if (idx >= word.size()) return t->isWord;
        
        if (word[idx] == '.')
        {
            for (Node *&cur : t->next)
                if (cur && search(word, idx + 1, cur)) return true;
            return false;
        }
        return search(word, idx + 1, t->next[word[idx] - 'a']);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");