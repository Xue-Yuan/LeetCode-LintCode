/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/
#include <vector>

using std::vector;

class Solution
{
private:
    void swap4(int &a, int &b, int &c, int &d)
    {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size()-1;
        int i = 0;
        while(i < n)
        {
            for(int j = i; j < n; ++j)
                swap4(matrix[i][j], matrix[j][n], matrix[n][n-j+i], matrix[n-j+i][i]);
            ++i;
            --n;
        }
    }
    /*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
    void rotate2(vector<vector<int> > &matrix) 
    {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
    void anti_rotate(vector<vector<int> > &matrix)
    {
        for (auto vi : matrix) reverse(vi.begin(), vi.end());
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};