/*
    Given n items with size Ai and value Vi, and a backpack with size m. 
        What's the maximum value can you put into the backpack?

    Example
    Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], 
        and a backpack with size 10. The maximum value is 9.

    Note
    You cannot divide item into small pieces and the total size of 
        items you choose should smaller or equal to m.
*/

class Solution 
{
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<vector<int>> dp(A.size()+1, vector<int>(m+1, 0));
        int Asz = (int)A.size();
        
        for (int i = 1; i <= Asz; ++i)
            for (int j = 1; j <= m; ++j)
            {
                //because each elememt can only be used once, so here
                //  is dp[i-1][j-A[i-1]]. It's different from the
                //  coin change maximun way problem
                dp[i][j] = max(dp[i-1][j], 
                    (j >= A[i-1] ? dp[i-1][j-A[i-1]] + V[i-1] : 0));
            }
        
        return dp[Asz][m];
    }
};