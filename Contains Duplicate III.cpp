/*
    an array of integers, find out whether there are 
        two distinct indices i and j in the array such 
        that the difference between nums[i] and nums[j] 
        is at most t and the difference between i and j 
        is at most k.
*/

/*  sliding window
    erase the element falling out of the window, insert 
        the new element.

    The range: nums[i] - t ~ nums[i] + t
        Find the lower bound of nums[i] - t,
        then go checking whether it's in the
        range.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if(nums.empty() || nums.size() == 1 || k <= 0 || t < 0) return false;
        std::set<int> s;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > k) s.erase(nums[i-k-1]);
            auto itr = s.lower_bound(nums[i]-t);
            //if we use *itr <= nums[i] + t, we must use long int
            if(itr != s.end() && *itr - nums[i] <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};