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
	vector<vector<int>> sumMatrix;
public:
    NumMatrix(vector<vector<int>> &matrix): sumMatrix(matrix) 
    {
    	if(matrix.empty()) return;
        for(int i = 0; i < matrix.size(); ++i)
        	for(int j = 1; j < matrix[0].size(); ++j)
        		sumMatrix[i][j] += sumMatrix[i][j - 1];
        for(int j = 0; j < matrix[0].size(); ++j)
        	for(int i = 1; i < matrix.size(); ++i)
        		sumMatrix[i][j] += sumMatrix[i - 1][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
    	if(row1 < 0 || col1 < 0 || row1 >= sumMatrix.size() || col1 >= sumMatrix[0].size())
            return 0;
        if(row1 == 0 && col1 == 0)
        	return sumMatrix[row2][col2];
        else if(row1 == 0)
        	return sumMatrix[row2][col2] - sumMatrix[row2][col1 - 1];
        else if(col1 == 0)
        	return sumMatrix[row2][col2] - sumMatrix[row1 - 1][col2];
        return sumMatrix[row2][col2] - sumMatrix[row1 - 1][col2] - sumMatrix[row2][col1 - 1] + sumMatrix[row1 - 1][col1 - 1];
    }
};