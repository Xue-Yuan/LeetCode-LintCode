/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <vector>

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums(n), tot(n, 1);
        for (int i = 0; i < n; ++i)
            nums[i] = i + 1;
        for (int i = 1; i < n; ++i)
            tot[i] = tot[i - 1] * i;
            
        --k;
        string ret = "";
        while (n)
        {
            int i = k / tot[n - 1];
            ret += char(nums[i] + '0');
            nums.erase(nums.begin() + i);
            k = k % tot[n - 1];
            n--;
        }
        return ret;
    }
};
