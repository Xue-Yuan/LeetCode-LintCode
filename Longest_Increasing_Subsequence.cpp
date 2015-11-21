/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.
*/

#include <vector>

using std::vector;

/*
    Dynamic programming. An auxiliary array is used to store the
        longest length from this position on.
*/

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int maxLen = 1;
        vector<int> len(nums.size(), 1);
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[j] > nums[i])
                    len[i] = max(len[i], len[j] + 1);
            }
            maxLen = max(len[i], maxLen);
        }
        return maxLen;
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

class Solution
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
                auto itr = upper_bound(v.begin(), v.begin() + len, nums[i] - 1);
                *itr = nums[i];
            }
        }
        return len;
    }
};