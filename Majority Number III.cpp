/*
    Given an array of integers and a number k, the majority number is 
        the number that occurs more than 1/k of the size of the array.

    Find it.

    Example
        Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.

    Note
        There is only one majority number in the array.
*/

//Can also be used to find all of the majority numbers.
class Solution 
{
public:
    int majorityNumber(vector<int> nums, int k) 
    {
        unordered_map<int, int> m;
        for (int &n : nums)
        {
            m[n]++;
            if ((int)m.size() == k)
                for (auto itr = m.begin(); itr != m.end();)
                {
                    if (--itr->second == 0) itr = m.erase(itr);
                    else ++itr;
                }
        }
        for (auto &p : m) p.second = 0;
        for (int &n : nums)
            if (m.find(n) != m.end()) m[n]++;
            
        int q = (int)nums.size() / k;
        for (auto &p : m) 
            if (p.second > q) return p.first;
        
        return -1;
    }
};
