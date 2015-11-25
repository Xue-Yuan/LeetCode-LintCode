/*
    You are a professional robber planning to rob houses along a street. 
        Each house has a certain amount of money stashed, the only 
        constraint stopping you from robbing each of them is that adjacent 
        houses have security system connected and it will automatically 
        contact the police if two adjacent houses were broken into on the 
        same night.

    Given a list of non-negative integers representing the amount of money 
        of each house, determine the maximum amount of money you can rob 
        tonight without alerting the police.
*/

/*
 states:
     rob  => able to rob
     skip => have to skip
 */
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        const int rob = 0, skip = 1;
        int cur = 0, next = 1;
        
        vector<vector<int>> states(2, vector<int>(2, 0));
        
        for(int &n : nums)
        {
            states[next][rob] = max(states[cur][rob], states[cur][skip]);
            states[next][skip] = states[cur][rob] + n;
            swap(next, cur);
        }
        return max(states[cur][skip], states[cur][rob]);
    }
};