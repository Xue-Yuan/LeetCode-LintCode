/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        auto itr = st.lower_bound(Interval(val, val));
        if (itr != st.begin() and prev(itr)->end+1 >= val) {
            itr--;
        }
        int s = val, e = val;
        while (itr != st.end() and itr->start <= val+1 and itr->end >= val-1) {
            s = min(s, itr->start);
            e = max(e, itr->end);
            itr = st.erase(itr);
        }
        st.insert(Interval(s, e));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(), st.end());
    }
private:
    struct IntervalCmp {
        bool operator() (const Interval &i1, const Interval &i2) const {
            return i1.start < i2.start;
        }
    };
    set<Interval, IntervalCmp> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
 