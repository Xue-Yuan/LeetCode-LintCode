/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.
*/

/*
    Dynamic programming. An auxiliary array is used to store the
        longest length from this position on.
*/

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int max_res = 1;
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_res = max(max_res, dp[i]);
                }
        return max_res;
    }
};

/*
    This approach is posted on 
        http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

    Our strategy determined by the following conditions,

        1. If A[i] is smallest among all end candidates of active lists, 
            we will start new active list of length 1 to replace the original one

        2. If A[i] is largest among all end candidates of active lists, 
            we will clone the largest active list, and extend it by A[i].

        3. If A[i] is in between, we will find a list with largest end 
            element that is smaller than A[i]. Clone and extend this 
            list by A[i]. We will discard all other lists of same length 
            as that of this modified list.

    Note that at any instance during our construction of active lists, 
        the following condition is maintained.
        "end element of smaller list is smaller than end elements of larger lists”.
*/

class Solution2
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() == 0) return 0;
        vector<int> v(nums.size());
        int len = 1;
        v[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] < v[0])
                v[0] = nums[i];
            else if(nums[i] > v[len - 1])
                v[len++] = nums[i];
            else
            {
                auto itr = lower_bound(v.begin(), v.begin() + len, nums[i]);
                *itr = nums[i];
            }
        }
        return len;
    }
};

//https://leetcode.com/discuss/67554/9-lines-c-code-with-o-nlogn-complexity
class Solution3
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> res;
        for (auto &e : nums)
        {
            auto itr = lower_bound(res.begin(), res.end(), e);
            if (itr == res.end()) res.push_back(e);
            else *itr = e;
        }
        return res.size();
    }
};
