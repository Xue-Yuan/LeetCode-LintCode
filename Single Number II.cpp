/*
    Given an array of integers, every element appears three times except
        for one. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you 
        implement it without using extra memory?
*/

class Solution 
{
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0, b = 0;
        for (int &c : nums)
        {
            int t = a&~b&~c | ~a&b&c;
            b = ~a&~b&c | ~a&b&~c;
            a = t;
        }
        return b;
    }
};
