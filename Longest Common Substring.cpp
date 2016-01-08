/*
    Given two strings, find the longest common substring.

    Return the length of it.

    Example
        Given A = "ABCD", B = "CBCE", return 2.

    Note
        The characters in substring should occur continuously in 
            original string. This is different with subsequence.
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        
        int res = 0;
        for (int i = 1; i < dp.size(); ++i)
            for (int j = 1; j < dp[0].size(); ++j)
            {
                if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        return res;
    }
};