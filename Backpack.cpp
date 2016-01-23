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

class Solution 
{
public:
    int backPack(int m, vector<int> A) 
    {
        vector<vector<bool>> dp(m + 1, vector<bool>(A.size() + 1, false));
        int Asz = (int)A.size();
        for (int i = 0; i <= Asz; ++i) dp[0][i] = true;
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= Asz; ++j)
                dp[i][j] = dp[i][j - 1] || (i >= A[j - 1] && dp[i - A[j - 1]][j - 1]);
                
        for (int i = m; i >= 0; --i)
            if (dp[i][Asz]) return i;
        
        return 0;
    }
};

//It's easier for us to optimize the space complexity if we rotate the 
//  dp matrix.
class Solution2 
{
public:
    int backPack(int m, vector<int> A) 
    {
        vector<vector<bool>> dp(A.size() + 1, vector<bool>(m + 1));
        int Asz = (int)A.size();
        dp[0][0] = true;
        for (int i = 1; i <= Asz; ++i)
        {
            dp[i][0] = true;
            for (int j = 1; j <= m; ++j)
                dp[i][j] = dp[i - 1][j] || (j >= A[i - 1] && dp[i - 1][j - A[i - 1]]);
        }
        
        for (int i = m; i >= 0; --i)
            if (dp[Asz][i]) return i;
        return 0;
    }
};

//Notice that dp[i][j] is dependent on dp[i][j - A[i - 1]], we have to
//  do this backwards.
class Solution3 
{
public:
    int backPack(int m, vector<int> A) 
    {
        vector<bool> dp(m + 1, false);
        int Asz = (int)A.size();
        dp[0] = true;
        for (int i = 1; i <= Asz; ++i)
            //have to do this backwards
            for (int j = m; j >= 1; --j)
                dp[j] = dp[j] || (j >= A[i - 1] && dp[j - A[i - 1]]);
        
        for (int i = m; i >= 0; --i)
            if (dp[i]) return i;
        return 0;
    }
};
