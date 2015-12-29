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

class Solution2
{
private:
    void setIthRowZeros(vector<vector<int>> &matrix, int i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
            matrix[i][j] = 0;
    }
    void setJthColZeros(vector<vector<int>> &matrix, int j)
    {
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][j] = 0;
    }
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty()) return;
        int N = matrix.size(), M = matrix[0].size();
        bool setFirstRowZero = false;
        bool setFirstColZero = false;

        for (int i = 0; i < N && !setFirstColZero; ++i)
            setFirstColZero = (matrix[i][0] == 0);
        for (int j = 0; j < M && !setFirstRowZero; ++j)
            setFirstRowZero = (matrix[0][j] == 0);

        for (int i = 1; i < N; ++i)
            for (int j = 1; j < M; ++j)
                if (matrix[i][j] == 0) 
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for (int i = 1; i < N; ++i)
            if (matrix[i][0] == 0)
                setIthRowZeros(matrix, i);

        for (int j = 1; j < M; ++j)
            if (matrix[0][j] == 0)
                setJthColZeros(matrix, j);

        if (setFirstRowZero) setIthRowZeros(matrix, 0);
        if (setFirstColZero) setJthColZeros(matrix, 0);
    }
};