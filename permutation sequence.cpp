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
class Solution {
public:
    string getPermutation(int n, int k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n)
        {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};
