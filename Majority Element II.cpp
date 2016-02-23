/*
    Given an integer array of size n, find all elements that 
        appear more than ⌊ n/3 ⌋ times. The algorithm should 
        run in linear time and in O(1) space.
*/
        
//vote down on both candidates
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return {};
        
        int can1, can2, cnt1 = 0, cnt2 = 0;
        for (int &i : nums)
        {
            if (can1 == i) cnt1++;
            else if (can2 == i) cnt2++;
            else if (cnt1 == 0) {can1 = i; cnt1 = 1;}
            else if (cnt2 == 0) {can2 = i; cnt2 = 1;}
            else {cnt1--; cnt2--;}
        }
        
        cnt1 = cnt2 = 0;
        for (int &i : nums)
        {
            cnt1 += can1 == i;
            cnt2 += can2 == i;
        }
        
        int sz = nums.size();
        vector<int> ret;
        if (cnt1 > sz/3) ret.push_back(can1);
        if (cnt2 > sz/3) ret.push_back(can2);
        
        return ret;
    }
};
