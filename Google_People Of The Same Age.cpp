/*
    You have a sorted array containing the age of every person on Earth. 

    [0, 0, 0, 0, ..., 1, 1, ..., 28, 28, ..., 110, ...] 

    Find out how many people have each age.
*/

class Solution
{
private:
    size_t lower_bound(vector<int> &ages, size_t b, size_t e, int target) 
    {
        while(b < e)
        {
            size_t m = b + (e - b) / 2;
            if (ages[m] < target) b = m+1;
            else e = m;
        }
        return b;
    }
public:
    vector<size_t> peopleOfEachAge(vector<int> &ages)
    {
        size_t b = 0, e = ages.size();
        vector<size_t> ret;
        while (b < ages.size())
        {
            size_t l = lower_bound(ages, b, e, ages[b]);
            size_t h = lower_bound(ages, b, e, ages[b]+1);
            ret.push_back(h-l);
            b = h;
        }
        return ret;
    }
};