/*
    Not very sure whether this is right or not. Passed two test cases:
        1. {0, 2, 4, 5}, {7, 4, 1, 4} => 4
        2. {0, 1, 3, 9}, {2, 1, 7, 5} => 0.5
*/

//the arrival time is already sorted.
struct Task {
    int arr, exe;
    Task(int _arr, int _exe): arr(_arr), exe(_exe) {}
    bool operator<(const Task &other) const {
        if (exe == other.exe) {
            return arr > other.arr;
        }
        return exe > other.exe;
    }
};

double shortestJobFirst(vector<int> &arrivals, vector<int> &executions) {
    priority_queue<Task> q;
    int idx = 0, waitTime = 0, curTime = 0, sz = arrivals.size();
    while (idx < sz || !q.empty()) {
        if (q.empty()) {
            q.push(Task(arrivals[idx], executions[idx]));
            curTime = arrivals[idx++];
        } else {
            Task curTask = q.top(); q.pop();
            waitTime += curTime - curTask.arr;
            curTime += curTask.exe;
            while (idx < sz && arrivals[idx] < curTime) {
                q.push(Task(arrivals[idx], executions[idx]));
                ++idx;
            }
        }
    }
    return sz ? (double)waitTime / sz : 0;
}


//Only save the execution time.
double shortestJobFirstAverageWaitTime(vector<int> &arrivals, vector<int> &executions) {
    priority_queue<int, vector<int>, greater<int> > q;
    int curTime = 0, waitTime = 0, idx = 0, sz = arrivals.size();
    while (!q.empty() || idx < sz) {
        while (idx < sz && arrivals[idx] < curTime) {
            q.push(executions[idx]);
            waitTime += curTime - arrivals[idx++];
        }
        if (q.empty()) {
            q.push(executions[idx]);
            curTime = arrivals[idx++];
        } else {
            int curExe = q.top(); q.pop();
            curTime += curExe;
            waitTime += curExe * q.size();
        }
    }
    return sz ? (double)waitTime / sz : 0;
}

int main() {
    int req[] = {1, 3, 3, 6, 6, 6, 7};
    int dur[] = {2 ,2 ,3 ,2, 4, 4, 2};
    vector<int> arrivals(req, req+7), executions(dur, dur+7);
    cout << shortestJobFirst(arrivals, executions) << endl;
}
