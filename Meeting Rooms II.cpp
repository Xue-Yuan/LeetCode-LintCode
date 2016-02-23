/*
    Given an array of meeting time intervals consisting of start and 
        end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum 
        number of conference rooms required.

    For example,
        Given [[0, 30],[5, 10],[15, 20]],
        return 2.
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
//worst case O(n^2)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](Interval &a, Interval &b){return a.start < b.start;});

        list<Interval> lst;
        int max_room = 0;
        for (auto &elem : intervals)
        {
            auto itr = find_if(lst.begin(), lst.end(),
                [&](Interval &a){return a.end <= elem.start;});
            if (itr == lst.end()) lst.push_back(elem);
            else *itr = elem;
            max_room = max(max_room, (int)lst.size());
        }
        return max_room;
    }
};

//We can use a heap to optimize the find step.
class Solution2 {
private:
    struct myGreater
    {
        bool operator()(Interval &a, Interval &b) {return a.end > b.end;}
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        
        priority_queue<Interval, vector<Interval>, myGreater> pq;
        pq.push(intervals.front());
        
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            auto tmp = pq.top(); pq.pop();
            if (tmp.end <= intervals[i].start)
                tmp.end = intervals[i].end;
            else pq.push(intervals[i]);
            pq.push(tmp);
        }
        return (int)pq.size();
    }
};
