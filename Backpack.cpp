/*
    Given n items with size Ai, an integer m denotes the size of a 
        backpack. How full you can fill this backpack?

    Example
    If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, 
        we can select [2, 3, 5], so that the max size we can fill this 
        backpack is 10. If the backpack size is 12. we can select 
        [2, 3, 7] so that we can fulfill the backpack.

    You function should return the max size we can fill in the given 
        backpack.
*/
        
//This question is very similar to the coin change problem, distinct 
//  subsequence
class Solution
{
public:
    int backPack(int m, vector<int> A) 
    {
        vector<vector<int>> dp(A.size()+1, vector<int>(m+1, 0));
        int Asz = (int)A.size();
        
        for (int i = 1; i <= Asz; ++i)
            for (int j = 1; j <= m; ++j)
                //notice that each elememt can only be used once.
                dp[i][j] = max(dp[i-1][j], 
                    j >= A[i-1] ? dp[i-1][j-A[i-1]] + A[i-1] : 0); 
        return dp[Asz][m];
    }
};

//Notice that dp[i][j] is dependent on dp[i][j - A[i - 1]], we have to
//  do the loop backwards.
class Solution2
{
public:
    int backPack(int m, vector<int> A)
    {
        vector<int> dp(m+1, 0);
        int Asz = (int)A.size();
        for (int i = 1; i <= Asz; ++i)
            for (int j = m; j >= 1; --j)
                dp[j] = max(dp[j], j >= A[i-1] ? dp[j-A[i-1]] + A[i-1] : 0);
        return dp[m];
    }
};
