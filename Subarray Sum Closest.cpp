/*
    Given an integer array, find a subarray with sum closest to zero. 
        Return the indexes of the first number and last number.

    Example
        Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] 
            or [0, 4].
*/

class Solution
{
public:
    vector<int> subarraySumClosest(vector<int> nums)
    {
        using PIS = pair<int, size_t>;
        vector<PIS> vec(nums.size());
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            vec[i] = {sum += nums[i], i};
        
        sort(vec.begin(), vec.end(), [](const PIS &a, const PIS &b){return a.first < b.first;});
        
        int closest = abs(nums[0]);
        vector<int> ans(2);
        for (size_t i = 1; i < vec.size(); ++i)
            if (abs(vec[i].first - vec[i - 1].first) < closest)
            {
                closest = abs(vec[i].first - vec[i - 1].first);
                ans[0] = min(vec[i].second, vec[i - 1].second) + 1;
                ans[1] = max(vec[i].second, vec[i - 1].second);
            }
                
        return ans;
    }
};
