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
        vector<int> perNum(10, 1);
        for(int i = 1; i <= 10; ++i)
            perNum[i] = i * perNum[i-1];

        cout << endl;
        vector<int> nums(10);
        for(int i = 0; i <= 9; ++i)
            nums[i] = i+1;

        string str = "";
        k = k - 1;
        while(n)
        {
            int pos = k / perNum[n-1];
            str += to_string(nums[pos]);
            nums.erase(nums.begin() + pos);
            k %= perNum[n-1];
            --n;
        }
        return str;
    }
};
