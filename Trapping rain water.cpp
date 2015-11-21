/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <vector>

using namespace std;

/*
	In my implemention, I keep track of the highest from the left
		and the highest from the right for each position respectively.
	orginal: 		0, 1, 0, 2, 1, 0, 3, 2, 1, 2, 1
	left_highest:   0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3
	right_highest:  3, 3, 3, 3, 3, 3, 2, 2, 2, 1, 0
*/
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        if(height.size() < 3) return 0;
        vector<int> left_highest(height.size(), 0), right_highest(height.size(), 0);
        int l = 1, r = height.size() - 2;
        while(l < height.size() && r >= 0)
        {
            left_highest[l] = max(height[l - 1], left_highest[l - 1]);
            right_highest[r] = max(height[r + 1], right_highest[r + 1]);
            ++l;
            --r;
        }
        
        int sum = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            if(height[i] < min(left_highest[i], right_highest[i]))
                sum += min(left_highest[i], right_highest[i]) - height[i];
        }
        return sum;
    }
};

/*
	The auxiliary vector can be eliminated by updating the left and right
		highest dynamically
*/
class Solution2 
{
public:
    int trap(vector<int>& height) 
    {
        if(height.size() < 3) return 0;
        int l = 0, r = height.size() - 1;
        int left_highest = 0, right_highest = 0;
        int sum = 0;
        while(l < r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] >= left_highest)
                    left_highest = height[l];
                else
                    sum += left_highest - height[l];
                ++l;
            }
            else
            {
                if(height[r] >= right_highest)
                    right_highest = height[r];
                else
                    sum += right_highest - height[r];
                --r;
            }
        }
        return sum;
    }
};
