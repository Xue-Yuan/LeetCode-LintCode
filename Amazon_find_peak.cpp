/*
    Given an array containing elements 
*/
class Solution
{
public:
    int peak(vector<int> &vec)
    {
        if (vec.size() < 3) return -1;
        int b = 0, e = (int)vec.size() - 1;
        while (b + 2 <= e)
        {
            int m = b + (e - b) / 2;
            if (vec[m - 1] <= vec[m] && vec[m] >= vec[m + 1]) return vec[m];
            if (vec[m-1] <= vec[m] && vec[m] <= vec[m + 1]) b = m;
            else e = m;
        }
        return -1;
    }
};
