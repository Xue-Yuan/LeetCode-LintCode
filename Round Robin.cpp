/*
    Not very sure whether this is right or not. Passed two test cases:
        1. {0, 1, 4}, {5, 2, 3}, 3 => 2.33333
        2. {0, 1, 3, 9}, {2, 1, 7, 5}, 2 => 1
*/

//This is not on LeetCood, but one I saw on an online forum. It is an
//  interview problem asked by Amazon.
double roundRobinAverageWaitTime(vector<int> &arrive, vector<int> &execute, int quantum)
{
    if (arrive.empty() || execute.empty()) return 0;

    int cur = 0, total = 0, idx = 0;
    queue<int> q;
    while (idx < arrive.size() || !q.empty())
    {
        //in case we may stuck forever. Say the queue is empty,
        //  current time is 13, but the next job starts at 15.
        //  We simply move the current time to 15.
        if (q.empty() && idx < arrive.size() && cur < arrive[idx]) 
            cur = arrive[idx];
        while (idx < arrive.size() && arrive[idx] <= cur)
        {
            q.push(execute[idx]);
            total += cur - arrive[idx];
            idx++;
        }

        int job = q.front(); 
        q.pop();
        if (job <= quantum)
        {
            cur += job;
            total += q.size() * job;
        }
        else
        {
            cur += quantum;
            total += q.size() * quantum;
            //the unfinished job must be arranged in the end.
            while (idx < arrive.size() && arrive[idx] <= cur)
            {
                q.push(execute[idx]);
                total += cur - arrive[idx];
                idx++;
            }
            q.push(job - quantum);
        }
    }
    return (double)total / arrive.size();
}
