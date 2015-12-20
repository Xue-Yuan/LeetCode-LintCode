/*
    Given n non-negative integers representing the histogram's bar 
        height where the width of each bar is 1, find the area of 
        largest rectangle in the histogram.

    For example,
        Given height = [2,1,5,6,2,3],
        return 10.
*/

//A really hard problem. The solution taken form
//  http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

class Solution 
{
public:
    int largestRectangleArea(vector<int> &height) 
    {
        int N = height.size();
        int res = 0, i = 0;
        stack<int> s;
        while(i < N) 
        {
            if(s.empty() || height[s.top()] <= height[i])
                s.push(i++);
            else
            {
                int idx = s.top(); 
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                res = max(res, height[idx] * width);
            }
        }
        while(!s.empty())
        {
            int idx = s.top(); 
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            res = max(res, height[idx] * width);
        }
        return res;
    }
};