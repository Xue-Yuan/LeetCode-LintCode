/*
    Given n, how many structurally unique BSTs (binary search trees) 
        that store values 1...n?

    Example
        Given n = 3, there are a total of 5 unique BST's.

        1           3    3       2      1
         \         /    /       / \      \
          3      2     1       1   3      2
         /      /       \                  \
        2     1          2                  3
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = 0;
            for (int j = 0; j < n; ++j)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp[n];
    }
};