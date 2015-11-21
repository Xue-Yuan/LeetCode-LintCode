/*
	Given an unsorted array of integers, find the length of 
		the longest consecutive elements sequence.

	For example,
		Given [100, 4, 200, 1, 3, 2],
		The longest consecutive elements sequence is [1, 2, 3, 4]. 
		Return its length: 4.

	Your algorithm should run in O(n) complexity.
*/

/*
	The idea is to maintain the boundary of the consecutive sequence.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        int max = 0;
        for(auto &n : nums)
        {
            if(m[n]) continue;
            //save length info in the boundaries
            m[n] = m[n+m[n+1]] = m[n-m[n-1]] = m[n-1] + m[n+1] + 1;
            max = std::max(max, m[n]);
        }
        return max;
    }       
};