/*
    Find the contiguous subarray within an array (containing at least one number) 
        which has the largest sum.

    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
        the contiguous subarray [4,−1,2,1] has the largest sum = 6.

    More practice:
        If you have figured out the O(n) solution, try coding another solution 
            using the divide and conquer approach, which is more subtle.
*/

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int maxhere = nums[0], maxsofar = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            maxhere = max(nums[i], maxhere + nums[i]);
            maxsofar = max(maxhere, maxsofar);
        }
        return maxsofar;
    }
};

//If we are asked to return the indices. Combine with the problem of 
//  two sum.
class Solution2
{
public:
    pair<int, int> maxSubArray(vector<int> &nums)
    {
        if (nums.empty()) return {-1, -1};
        int maxhere = nums[0], maxsofar = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            maxhere = max(nums[i], maxhere + nums[i]);
            maxsofar = max(maxhere, maxsofar);
        }
        cout << maxsofar << endl;
        //Then it becomes the two sum problem.
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (m.find(sum-maxsofar) != m.end())
                return {m[sum-maxsofar]+1, i};
            m[sum] = i;
        }
        return {-1, -1};
    }
};
