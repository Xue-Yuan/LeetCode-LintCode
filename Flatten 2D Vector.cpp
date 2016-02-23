/*
    Implement an iterator to flatten a 2d vector.

    For example,
        Given 2d vector =

        [
          [1,2],
          [3],
          [4,5,6]
        ]
    By calling next repeatedly until hasNext returns false, the order of 
        elements returned by next should be: [1,2,3,4,5,6].
*/
class Vector2D 
{
public:
    Vector2D(vector<vector<int>>& vec2d) 
    {
        rb = begin(vec2d), re = end(vec2d);
        while (rb != re && (*rb).empty()) rb++;
        if (rb != re && !(*rb).empty())
        {
            cb = begin(*rb);
            ce = end(*rb);
        }
    }

    int next() 
    {
        int ret = *cb++;
        if (cb == ce)
            while (rb != re)
                if (!(*++rb).empty())
                {
                    cb = begin(*rb);
                    ce = end(*rb);
                    break;
                }
                
        return ret;
    }

    bool hasNext() 
    {
        return rb != re;
    }
private:
    vector<vector<int>>::iterator rb, re;
    vector<int>::iterator cb, ce;
};
