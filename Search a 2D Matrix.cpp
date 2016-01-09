/*
    Write an efficient algorithm that searches for a value in an m x n 
        matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    
    The first integer of each row is greater than the last integer of 
        the previous row.
    
    For example,

        Consider the following matrix:

        [
          [1,   3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]
        ]
        
        Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int r = (int)matrix.size(), c = matrix[0].size();
        
        int b1 = 0, e1 = r;
        while (b1 < e1)
        {
            int m = b1 + (e1 - b1) / 2;
            if (matrix[m][c - 1] < target) b1 = m + 1;
            else e1 = m;
        }
        if (b1 == r) return false;
        
        int b2 = 0, e2 = c;
        while (b2 < e2)
        {
            int m = b2 + (e2 - b2) / 2;
            if (matrix[b1][m] < target) b2 = m + 1;
            else e2 = m;
        }
        return b2 != c && matrix[b1][b2] == target;
    }
};