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
    int numTrees(int n) 
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (size_t i = 1; i <= n; ++i)
        {
            dp[i] = 0;
            for (int j = i - 1; j >= 0; --j)
                dp[i] += dp[j] * dp[i - 1 - j];
        }
        return dp[n];
    }
};
