/*
    Implement a trie with insert, search, and startsWith methods.

    Note:
    You may assume that all inputs are consist of lowercase letters a-z.
*/
    
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): isWord(false), next(26, nullptr) {}
    vector<TrieNode *> next;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() { destory(root); }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *t = root;
        for (char &ch : word)
        {
            if (!t->next[ch-'a'])
                t->next[ch-'a'] = new TrieNode();
            t = t->next[ch-'a'];
        }
        t->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *t = root;
        for (char &ch : word)
        {
            if (!t->next[ch-'a']) return false;
            t = t->next[ch-'a'];
        }
        return t->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for (char &ch : prefix)
        {
            if (!t->next[ch-'a']) return false;
            t = t->next[ch-'a'];
        }
        return true;
    }
private:
    void destory(TrieNode *t)
    {
        if (!t) return;
        for (auto ptr : t->next)
            destory(ptr);
        delete t;
    }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
