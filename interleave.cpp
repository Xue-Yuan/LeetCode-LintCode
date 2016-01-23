/*
    Given three strings: s1, s2, s3, determine whether s3 is formed 
        by the interleaving of s1 and s2.

    Example
        For s1 = "aabcc", s2 = "dbbca"

        When s3 = "aadbbcbcac", return true.
        When s3 = "aadbbbaccc", return false.
*/

//check whether string s3 is the interleaving of string s1 and string s2
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> v(s1.size() + 1, vector<bool>(s2.size() + 1));
        v[0][0] = true;
        for(int j = 1; j <= s2.size(); ++j)
            v[0][j] = (v[0][j - 1] && (s2[j - 1] == s3[j - 1]));
        for(int i = 1; i <= s1.size(); ++i)
            v[i][0] = (v[i - 1][0]) && (s1[i - 1] == s3[i - 1]);

        for(int i = 1; i <= s1.size(); ++i)
            for(int j = 1; j <= s2.size(); ++j)
                v[i][j] = (v[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) 
                    || (v[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
        return v[s1.size()][s2.size()];
    }
};

class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s3.size() != s1.size() + s2.size()) return false;
        vector<bool> dp(s2.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s2.size(); ++i)
            dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];
            
        for (int i = 1; i <= s1.size(); ++i)
        {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= s2.size(); ++j)
                dp[j] = (dp[j - 1] && s2[j - 1] == s3[i + j - 1])
                        || (dp[j] && s1[i - 1] == s3[i + j - 1]);
        }
        return dp[s2.size()];
    }
};
