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
//Compare with backpack, coin change maximum way.
class Solution 
{
public:    
    int numDistinct(string &S, string &T) 
    {
        int ssz = S.size(), tsz = T.size();
        vector<vector<int>> dp(ssz + 1, vector<int>(tsz + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= ssz; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= tsz; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[ssz][tsz];
    }
};

class Solution2
{
public:    
    int numDistinct(string &S, string &T) 
    {
        int ssz = S.size(), tsz = T.size();
        vector<int> dp(tsz + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= ssz; ++i)
        {
            int prev = dp[0];
            for (int j = 1; j <= tsz; ++j)
            {
                int tmp = dp[j];
                if (S[i - 1] == T[j - 1]) dp[j] += prev;
                prev = tmp;
            }
        }
        return dp[tsz];
    }
};
