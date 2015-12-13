/*
    There are N children standing in a line. Each child is assigned 
        a rating value.

    You are giving candies to these children subjected to the 
        following requirements:

    Each child must have at least one candy.

    Children with a higher rating get more candies than their neighbors.
    
    What is the minimum candies you must give?
*/

class Solution
{
public:
    int dfs(const vector<int>& ratings, vector<int>& dp, int i)
    {
        if (dp[i] != -1)
            return dp[i];
        dp[i] = 1;
        if(i > 0  && ratings[i] > ratings[i - 1])
            dp[i] = max(dp[i], dfs(ratings, dp, i - 1) + 1);
        if(i < ratings.size()-1 && ratings[i] > ratings[i + 1])
            dp[i] = max(dp[i], dfs(ratings, dp, i + 1) + 1);
        return dp[i];
    }
    int candy(vector<int> &ratings)
    {
        vector<int> dp(ratings.size(), -1);
        int res = 0;
        for(int i = 0;i < ratings.size(); ++i)
            res += dfs(ratings, dp, i);
        return res;
    }
};