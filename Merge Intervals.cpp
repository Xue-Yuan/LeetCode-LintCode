/*
    Given a collection of intervals, merge all overlapping 
        intervals.

    For example,
        Given [1,3],[2,6],[8,10],[15,18],
        return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution 
{
private:
    //a.start <= b.start
    bool contains(Interval &a, Interval &b) {return a.end >= b.end;}
    bool overlaps(Interval &a, Interval &b) {return a.end >= b.start && a.end < b.end;}
    bool disjoint(Interval &a, Interval &b) {return a.end < b.start;}
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        
        vector<Interval> ret;
        int i = 0;
        while (i < intervals.size())
        {
            auto cur = intervals[i++];
            while (i < intervals.size() && !disjoint(cur, intervals[i]))
            {
                while (i < intervals.size() && contains(cur, intervals[i])) i++;
                while (i < intervals.size() && overlaps(cur, intervals[i]))
                {
                    cur.end = intervals[i].end;
                    i++;
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};

class Solution2 
{
private:
    bool isDisjoint(Interval &a, Interval &b) {return a.end < b.start || a.start > b.end;}
    void merge2(Interval &a, Interval &b) {a.end = max(a.end, b.end);}
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        Interval cur = intervals.front();
        
        vector<Interval> ret;
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (isDisjoint(cur, intervals[i]))
            {
                ret.push_back(cur);
                cur = intervals[i];
            }
            else merge2(cur, intervals[i]);
        }
        ret.push_back(cur);
        return ret;
    }
};
