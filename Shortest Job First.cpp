/*
    Not very sure whether this is right or not. Passed two test cases:
        1. {0, 2, 4, 5}, {7, 4, 1, 4} => 4
        2. {0, 1, 3, 9}, {2, 1, 7, 5} => 0.5
*/

//the arrival time is already sorted.
double shortestJobFirstAverageWaitTime(vector<int> &arrive, vector<int> &execute)
{
    if (arrive.empty() || execute.empty()) return 0;

    int cur = arrive[0], total = 0, idx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (idx < arrive.size() || !pq.empty())
    {
        if (pq.empty() && idx < arrive.size() && arrive[idx] > cur)
            cur = arrive[idx];
        while (idx < arrive.size() && cur >= arrive[idx])
        {
            total += cur - arrive[idx];
            pq.push(execute[idx]);
            idx++;
        }

        int job = pq.top();
        pq.pop();
        cur += job;
        total += job * pq.size();
    }
    return (double)total / arrive.size();
}