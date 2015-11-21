/*
    Note: This is an extension of House Robber.

    After robbing those houses on that street, the thief has 
        found himself  a new place for his thievery so that 
        he will not get too much attention. This time, all 
        houses at this place are arranged in a circle. That 
        means the first house is the neighbor of the last one. 
        Meanwhile, the security system for these houses remain 
        the same as for those in the previous street.

    Given a list of non-negative integers representing the 
        amount of money of each house, determine the maximum 
        amount of money you can rob tonight without alerting 
        the police.
*/
        
//state[2][2]: [][0]--skip; [][1]--rob
//state[next][0] = state[cur][]
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        
        vector<vector<int>> state(2, vector<int>(2, 0));
        int cur = 0, next = 1, ma = nums[0];
        //rob the first one
        state[cur][1] = nums[0];
        for(int i = 1; i < nums.size() - 1; ++i)
        {
            state[next][0] = max(state[cur][1], state[cur][0]);
            state[next][1] = max(state[cur][0] + nums[i], state[cur][1]);
            ma = max(max(state[next][0], state[next][1]), ma);
            swap(next, cur);
        }
        //skip the first one
        state[cur][0] = state[cur][1] = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            state[next][0] = max(state[cur][1], state[cur][0]);
            state[next][1] = max(state[cur][0] + nums[i], state[cur][1]);
            ma = max(max(state[next][0], state[next][1]), ma);
            swap(next, cur);
        }
        return ma;
    }
};