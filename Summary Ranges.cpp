/*
    Given a sorted integer array without duplicates, return the summary 
        of its ranges.

    For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int len = nums.size();
        vector<string> ret;
        for (int i = 0; i < len;)
        {
            int start = i++;
            while (i < len && nums[i] == nums[i-1]+1)
                i++;
            if (nums[start] == nums[i-1])
                ret.push_back(to_string(nums[start]));
            else
                ret.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
        }
        return ret;
    }
};
