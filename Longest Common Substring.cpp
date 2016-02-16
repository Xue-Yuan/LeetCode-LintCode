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
    int longestCommonSubstring(string &A, string &B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int ret = 0;
        for (size_t i = 1; i <= A.size(); ++i)
            for (size_t j = 1; j <= B.size(); ++j)
            {
                if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                ret = max(ret, dp[i][j]);
            }   
        return ret;
    }
};
