/*
    Given a m x n matrix, if an element is 0, set its entire 
        row and column to 0. Do it in place.
*/
//Mark the elememt first
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j)
                if(matrix[i][j] == 0) 
                    mark(matrix, i, j);

        for(auto &v : matrix)
            for(auto &c : v)
                if(c == INT_MAX - 3)
                    c = 0;
        
    }
    void mark(vector<vector<int>> &matrix, int r, int c)
    {
        for(int i = 0; i < matrix.size(); ++i)
            if(matrix[i][c] != 0)
                matrix[i][c] = INT_MAX - 3;
        for(int i = 0; i < matrix[0].size(); ++i)
            if(matrix[r][i] != 0)
                matrix[r][i] = INT_MAX - 3;
    }
};