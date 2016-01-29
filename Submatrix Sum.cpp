/*
    Given an integer matrix, find a submatrix where the sum of numbers 
        is zero. Your code should return the coordinate of the left-up 
        and right-down number.

    Example
        Given matrix

        [
          [1 ,5 ,7],
          [3 ,7 ,-8],
          [4 ,-8 ,9],
        ]
        return [(1,1), (2,2)]
*/
class Solution 
{
public:
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return {};
        int row = (int)matrix.size(), col = (int)matrix[0].size();
        
        for (int i = 0; i < col; ++i)
        {
            //sums[k] is the sum from matrix[k][i] to matrix[k][j]
            vector<int> sums(row, 0);
            for (int j = i; j < col; ++j)
            {
                for (int k = 0; k < row; ++k)
                    sums[k] += matrix[k][j];
                
                unordered_map<int, int> m;
                m[0] = -1;
                int curSum = 0;
                
                for (int k = 0; k < row; ++k)
                {
                    curSum += sums[k];
                    if (m.find(curSum) != m.end())
                        return {{m[curSum] + 1, i}, {k, j}};
                    m[curSum] = k;
                }
            }
        }
        return {};
    }
};
