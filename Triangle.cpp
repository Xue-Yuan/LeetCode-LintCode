/*
    Given a triangle, find the minimum path sum from top to bottom. Each 
        step you may move to adjacent numbers on the row below.

    For example, given the following triangle
        [
             [2],
            [3,4],
           [6,5,7],
          [4,1,8,3]
        ]
    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if (triangle.empty() || triangle[0].empty()) return 0;
        vector<int> dp(triangle.back().size(), 0);
        
        for (size_t i = 0; i < triangle.size(); ++i)
        {
            int pre = dp[0];
            for (size_t j = 0; j < triangle[i].size(); ++j)
            {
                int tmp = dp[j];
                if (j == 0) dp[0] += triangle[i][0];
                else if (j == triangle[i].size()-1) dp[j] = triangle[i][j] + pre;
                else dp[j] = min(dp[j], pre) + triangle[i][j];
                pre = tmp;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
