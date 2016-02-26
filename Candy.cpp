/*
    There are N children standing in a line. Each child is assigned 
        a rating value.

    You are giving candies to these children subjected to the 
        following requirements:

    Each child must have at least one candy.

    Children with a higher rating get more candies than their neighbors.
    
    What is the minimum candies you must give?
*/
//dfs with memoization
class Solution
{
public:
    int dfs(const vector<int>& ratings, vector<int>& dp, int i)
    {
        if (dp[i]) return dp[i];

        dp[i] = 1;
        if(i > 0  && ratings[i] > ratings[i - 1])
            dp[i] = max(dp[i], dfs(ratings, dp, i - 1) + 1);
        if(i < (int)ratings.size()-1 && ratings[i] > ratings[i + 1])
            dp[i] = max(dp[i], dfs(ratings, dp, i + 1) + 1);
        return dp[i];
    }
    int candy(vector<int> &ratings)
    {
        vector<int> dp(ratings.size(), 0);
        int res = 0, len = ratings.size();
        for(int i = 0; i < len; ++i)
            res += dfs(ratings, dp, i);
        return res;
    }
};

//scan twice
class Solution2 {
public:
    int candy(vector<int>& ratings) 
    {
        if (ratings.empty()) return 0;
        vector<int> dp(ratings.size(), 1);
        int len = ratings.size();
        //left to right
        for (int i = 1; i < len; ++i)
            if (ratings[i] > ratings[i-1])
                dp[i] = dp[i-1]+1;
        //right to left
        int cnt = dp.back();
        for (int i = len-2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i+1])
                dp[i] = max(dp[i], dp[i+1]+1);
            cnt += dp[i];
        }
                
        return cnt;
    }
};
