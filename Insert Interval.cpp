/*
    Given a set of non-overlapping intervals, insert a new interval 
        into the intervals (merge if necessary).

    You may assume that the intervals were initially sorted according 
        to their start times.

    Example 1:
    Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] 
        in as [1,2],[3,10],[12,16].

    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

class Solution
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        if (intervals.empty()) return {newInterval};
        
        auto left = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval &a, const Interval &b) {return a.start < b.start;});
        left--;
        auto right = upper_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval &a, const Interval &b) {return a.end < b.end;});
        
        if (left >= intervals.begin() && left->end >= newInterval.start) newInterval.start = (*left--).start;
        if (right != intervals.end() && right->start <= newInterval.end) newInterval.end = (*right++).end;
        
        vector<Interval> ret;
        for (auto itr = intervals.begin(); itr <= left; ++itr)
            ret.push_back(*itr);
        
        ret.push_back(newInterval);
        
        for (auto itr = right; itr < intervals.end(); ++itr)
            ret.push_back(*itr);
        
        return ret;
    }
};