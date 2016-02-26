/*
    There is a fence with n posts, each post can be painted with one of 
        the k colors.

    You have to paint all the posts such that no more than two adjacent 
        fence posts have the same color.

    Return the total number of ways you can paint the fence.

    Note:
        n and k are non-negative integers.
*/

class Solution {
public:
    int numWays(int n, int k) {
        vector<int> same(n+1), diff(n+1);
        same[1] = 0, diff[1] = k;
        for (int i = 2; i <= n; ++i)
        {
            same[i] = diff[i-1];
            diff[i] = (k-1)*(diff[i-1] + same[i-1]);
        }
        return same[n] + diff[n];
    }
};

//The space complexity can be further optimized
class Solution2
{
public:
    int numWays(int n, int k)
    {
        int same = 0, diff = k;
        for (int i = 2; i <= n; ++i)
        {
            int nxt_same = diff;
            diff = (k - 1) * (diff + same);
            same = nxt_same;
        }
        return same + diff;
    }
};
