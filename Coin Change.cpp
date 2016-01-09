/*
    You are given coins of different denominations and a total amount 
        of money amount. Write a function to compute the fewest number 
        of coins that you need to make up that amount. If that amount 
        of money cannot be made up by any combination of the coins, 
        return -1.

    Example 1:
        coins = [1, 2, 5], amount = 11
    
    return 3 (11 = 5 + 5 + 1)

    Example 2:
        coins = [2], amount = 3
   
    return -1.

    Note:
        You may assume that you have an infinite number of each kind of 
            coin
*/

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i)
            for (auto & c : coins)
                if (i - c >= 0 && dp[i - c] != -1)
                    dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
        
        return dp[amount];
    }
};

//This would be faster.
class Solution2
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 0; i <= amount; ++i)
        {
            if (dp[i] < 0) continue;
            for (int &c : coins)
                if (i + c <= amount && (dp[i + c] < 0 || dp[i + c] > dp[i] + 1))
                    dp[i + c] = dp[i] + 1; 
                    
        }
        return dp[amount];
    }
};

//BFS
class Solution3
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount == 0) return 0;
        queue<int> cur, nxt;
        vector<bool> visited(amount + 1, false);
        cur.push(0);
        int cnt = 0;
        bool exist = true;
        while (exist)
        {
            ++cnt;
            exist = false;
            while (!cur.empty())
            {
                int tmp = cur.front(); cur.pop();
                for (auto &c : coins) 
                {
                    int now = tmp + c;
                    if (now > amount || visited[now]) continue;
                    if (now == amount) return cnt;
                    exist = true;
                    nxt.push(now);
                    visited[now] = true;
                }
            }
            swap(cur, nxt);
        }
        return -1;
    }
};
