//dp[i][j] means use the first i coins to get the value j.
// compare with backpack, distinct subsequence.
class Solution
{
public:
    int coinChange(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        int csz = coins.size();
        for (int i = 1; i <= csz; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[csz][amount];
    }
};
