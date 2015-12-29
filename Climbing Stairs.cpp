/*
    You are climbing a stair case. It takes n steps to reach to 
        the top.

    Each time you can either climb 1 or 2 steps. In how many 
        distinct ways can you climb to the top?
*/
class Solution 
{
public:
    int climbStairs(int n)
    {
        if (n < 3) return n;
        
        int one_away = 2, two_away = 1; //n = 2
        for (int i = 3; i <= n; ++i)
        {
            int cur = one_away + two_away;
            two_away = one_away;
            one_away = cur;
        }
        return one_away;
    }
};