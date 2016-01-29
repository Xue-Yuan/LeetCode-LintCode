class Solution 
{
public:
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return {};
        int row = (int)matrix.size(), col = (int)matrix[0].size();
        
        int max_sofar = matrix[0][0];
        vector<vector<int>> ret;
        for (int i = 0; i < col; ++i)
        {
            //sums[k] is the sum from matrix[k][i] to matrix[k][j]
            vector<int> sums(row, 0);
            for (int j = i; j < col; ++j)
            {
                for (int k = 0; k < row; ++k)
                    sums[k] += matrix[k][j];
                
                //Kadane’s algorithm
                int max_here = sums[0];
                int local_start = 0;
                for (int k = 1; k < row; ++k)
                {
                    max_here += sums[k];
                    if (max_here < sums[k])
                    {
                        max_here = sums[k];
                        local_start = k;
                    }
                    if (max_here > max_sofar)
                    {
                        max_sofar = max_here;
                        ret = {{local_start, i}, {k, j}};
                    }
                }
            }
        }
        return ret;
    }
};


int main() 
{
    vector<vector<int>> vec
    {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    Solution so;
    auto ret = so.submatrixSum(vec);
    for (auto &v : ret)
    {
        for (int &i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
