/*
    Given a string S and a string T, count the number of distinct 
        subsequences of T in S.

    A subsequence of a string is a new string which is formed from 
        the original string by deleting some (can be none) of the 
        characters without disturbing the relative positions of the 
        remaining characters. (ie, "ACE" is a subsequence of "ABCDE" 
        while "AEC" is not).

    Here is an example:
        S = "rabbbit", T = "rabbit"

    Return 3.
*/

/*
    O(N^2) time and O(N^2) space. We can further optimize it to use
        O(N) space.
*/
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        if (s.size() < t.size())
            return 0;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
        
        dp[0][0] = s[0] == t[0];
        for (int i = 1; i < dp.size(); ++i)
            dp[i][0] = dp[i - 1][0] + (s[i] == t[0]);
        
        for (int j = 1; j < dp[0].size(); ++j)
        {
            for (int i = j; i < dp.size(); ++i)
            {
                if (s[i] != t[j])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp[s.size() - 1][t.size() - 1];
    }
};