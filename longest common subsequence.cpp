/*
    DP: longest common subsequence
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(const string &s1, const string &s2)
{
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
    {
        for(int i = 0; i <= s1.size(); ++i)
            for(int j = 0; j <= s2.size(); ++j)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
    }
    return dp[s1.size()][s2.size()];
}