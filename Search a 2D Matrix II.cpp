/*
    Write an efficient algorithm that searches for a value in an 
        m x n matrix, return the occurrence of it.

    This matrix has the following properties:

        Integers in each row are sorted from left to right.
        Integers in each column are sorted from up to bottom.
        No duplicate integers in each row or column.

    Example
        Consider the following matrix:

        [
          [1, 3, 5, 7],
          [2, 4, 7, 8],
          [3, 5, 9, 10]
        ]
    Given target = 3, return 2.
*/

class Solution 
{
public:
    int searchMatrix(vector<vector<int> > &matrix, int target) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int r = (int)matrix.size(), c = (int)matrix[0].size(), cnt = 0;
        int x = 0, y = c - 1;
        while (x >= 0 && x < r && y >= 0 && y < c)
        {
            cnt += matrix[x][y] == target;
            if (matrix[x][y] <= target) x++;
            else y--;
        }
        return cnt;
    }
};
