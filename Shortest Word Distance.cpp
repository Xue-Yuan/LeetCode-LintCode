/*
    Given a list of words and two words word1 and word2, return the shortest 
        distance between these two words in the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “coding”, word2 = “practice”, return 3.
    Given word1 = "makes", word2 = "coding", return 1.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        if (word1 == word2) return 0;
        
        int idx1 = -1, idx2 = -1, len = (int)words.size(), ret = len;
        for (int i = 0; i < len; ++i)
        {
            if (words[i] == word1)
            {
                idx1 = i;
                if (idx2 >= 0) ret = min(ret, idx1-idx2);
            }
            else if (words[i] == word2)
            {
                idx2 = i;
                if (idx1 >= 0) ret = min(ret, idx2-idx1);
            }
        }
        return ret;
    }
};
