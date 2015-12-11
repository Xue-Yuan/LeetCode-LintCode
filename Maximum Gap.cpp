/*
    Given an unsorted array, find the maximum difference between the 
        successive elements in its sorted form.

    Try to solve it in linear time/space.

    Return 0 if the array contains less than 2 elements.

    You may assume all elements in the array are non-negative integers 
        and fit in the 32-bit signed integer range.
*/

/*
    Radix sort.

    The time complexity is O(log(max) *(N + base)). For int, log(max)
        is const.
*/
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        if(nums.size() < 2) return 0;
        
        int ma = nums[0];
        for (auto &e : nums)
            ma = max(e, ma);
        
        const int base = 10;
        int t = 1;
        while (ma / t)
        {
            vector<int> count(base, 0);
            for (auto &e : nums)
                count[e / t % 10]++;
            for (int i = 0; i < base - 1; ++i)
                count[i + 1] += count[i];
            vector<int> tmp(nums.size(), 0);
            for (int i = (int)nums.size() - 1; i >= 0; --i)
                tmp[--count[nums[i] / t % 10]] = nums[i];
            swap(nums, tmp);
            t *= 10;
        }
        
        ma = 0;
        for (int i = 1; i < (int)nums.size(); ++i)
            ma = max(ma, abs(nums[i] - nums[i - 1]));
        return ma;
    }
};

/*
    The idea from bucket sort.

    One more bucket than the size of nums. so there be at least one empty bucket.

    The max gap lies between the ends of the empty bucket(s).
*/

class Solution2
{
public:
    int maximumGap(vector<int>& nums)
    {
        if(nums.size() < 2) return 0;
        
        int n = (int)nums.size();
        auto p = minmax_element(nums.begin(), nums.end());
        int mi = *p.first, ma = *p.second;
        if(mi == ma) return 0;
        
//        double delta = (ma - mi) / (n + 1);
        
        vector<pair<int, int>> bucket(n + 1, {-1, -1});
        
        for (auto &e : nums)
        {
            int idx = int((long long)(e - mi) * (n + 1) / (ma + 1 - mi));   //(ma + 1 - mi) so the max_element will be in the last bucket.
            bucket[idx].second = max(e, bucket[idx].second);
            if (bucket[idx].first == -1)
                bucket[idx].first = e;
            else
                bucket[idx].first = min(e, bucket[idx].first);
        }
        
        int res = 0, prev = bucket[0].second;
        for (int i = 1; i < n + 1; ++i)
        {
            if(bucket[i].first != -1)
            {
                res = max(res, bucket[i].first - prev);
                prev = bucket[i].second;
            }
        }
        return res;
    }
};
