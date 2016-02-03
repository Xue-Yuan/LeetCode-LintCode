/*
    Given two strings, find the longest common subsequence (LCS).

    Your code should return the length of LCS.

    Example
        For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

        For "ABCD" and "EACB", the LCS is "AC", return 2.
*/

/*
    DP: longest common subsequence
*/
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
        for(int i = 0; i <= s1.size(); ++i)
            for(int j = 0; j <= s2.size(); ++j)
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        return dp[s1.size()][s2.size()];
    }
};

//As usually, we do space optimization
class Solution2 {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        vector<int> dp(s2.size()+1);
        dp[0] = 0;
        for(size_t i = 0; i <= s1.size(); ++i)
        {
            int pre = dp[0];
            for(size_t j = 1; j <= s2.size(); ++j)
            {
                int tmp = dp[j];
                if(s1[i - 1] == s2[j - 1]) dp[j] = pre + 1;
                else dp[j] = max(dp[j], dp[j - 1]);
                pre = tmp;
            }
        }
        return dp[s2.size()];
    }
};
