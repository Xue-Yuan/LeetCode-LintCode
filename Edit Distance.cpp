/*
    Given two words word1 and word2, find the minimum number of 
        steps required to convert word1 to word2. (each operation is counted as 1 step.)

    You have the following 3 operations permitted on a word:

    a) Insert a character
    b) Delete a character
    c) Replace a character
*/

//https://web.stanford.edu/class/cs124/lec/med.pdf
//http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;
        
        for (int i = 1; i <= word1.size(); ++i)
            for (int j = 1; j <= word2.size(); ++j)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
        
        return dp[word1.size()][word2.size()];
    }
};

//As usual we can do some optimization
class Solution2 
{
public:
    int minDistance(string word1, string word2) 
    {
        vector<int> dp(word2.size() + 1, 0);
        for (int j = 0; j <= word2.size(); ++j)
            dp[j] = j;
        
        for (int i = 1; i <= word1.size(); ++i)
        {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= word2.size(); ++j)
            {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = min(min(dp[j - 1], dp[j]), pre) + 1;
                pre = tmp;
            }
        }
        return dp[word2.size()];
    }
};