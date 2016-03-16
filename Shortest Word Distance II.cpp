/*
    This is a follow up of Shortest Word Distance. The only difference is now 
        you are given the list of words and your method will be called repeatedly 
        many times with different parameters. How would you optimize it?

    Design a class which receives a list of words in the constructor, and 
        implements a method that takes two words word1 and word2 and return the 
        shortest distance between these two words in the list.

    For example,
        Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

        Given word1 = “coding”, word2 = “practice”, return 3.
        Given word1 = "makes", word2 = "coding", return 1.

    Note:
        You may assume that word1 does not equal to word2, and word1 and word2 
            are both in the list.
*/

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int len = (int)words.size();
        for (int i = 0; i < len; i++)
            m[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        const vector<int> &v1 = m[word1], &v2 = m[word2];
        int idx1 = 0, idx2 = 0;
        int sz1 = v1.size(), sz2 = v2.size(), ret = abs(v1[idx1]-v2[idx2]);
        while (idx1 < sz1 && idx2 < sz2)
        {
            if (v1[idx1] < v2[idx2])
                ret = min(ret, v2[idx2]-v1[idx1++]);
            else
                ret = min(ret, v1[idx1]-v2[idx2++]);
        }
        return ret;
    }
private:
    unordered_map<string, vector<int>> m;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
