/*
    Given a 2D matrix matrix, find the sum of the elements 
        inside the rectangle defined by its upper left corner 
        (row1, col1) and lower right corner (row2, col2).

    Range Sum Query 2D

    Example:
        Given matrix = [
          [3, 0, 1, 4, 2],
          [5, 6, 3, 2, 1],
          [1, 2, 0, 1, 5],
          [4, 1, 0, 1, 7],
          [1, 0, 3, 0, 5]
        ]

    sumRegion(2, 1, 4, 3) -> 8
    sumRegion(1, 1, 2, 2) -> 11
    sumRegion(1, 2, 2, 4) -> 12
*/
class NumMatrix
{
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            sum = matrix;
            return;
        }
        sum.assign(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));        
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                sum[i + 1][j + 1] += matrix[i][j] + sum[i + 1][j];
    
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                sum[i + 1][j + 1] += sum[i][j + 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (sum.empty() || sum[0].empty()) return 0;
        int br = (int)sum.size() - 2, bc = (int)sum[0].size() - 2;
        if (row1 < 0 || col1 < 0 || row2 > br || col2 > bc) return 0;
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }
};
