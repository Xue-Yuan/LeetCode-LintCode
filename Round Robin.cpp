/*
        1. {0, 1, 4}, {5, 2, 3}, 3 => 2.33333
        2. {0, 1, 3, 9}, {2, 1, 7, 5}, 2 => 1
*/

struct Task {
    int arr, exe;
    Task(int _arr, int _exe): arr(_arr), exe(_exe) {}
};


double round_robin(vector<int> arrivals, vector<int> executions, int quantum) {
    queue<Task> q;
    int idx = 0, sz = arrivals.size(), curTime = 0, waitTime = 0;
    while (idx < sz || !q.empty()) {
        if (q.empty()) {
            q.push(Task(arrivals[idx], executions[idx]));
            curTime = arrivals[idx++];
        } else {
            Task cur = q.front(); q.pop();
            waitTime += curTime - cur.arr;
            curTime += min(quantum, cur.exe);
            while (idx < sz && arrivals[idx] <= curTime) {
                q.push(Task(arrivals[idx], executions[idx]));
                ++idx;
            }
            if (cur.exe > quantum) {
                cur.arr = curTime;
                cur.exe -= quantum;
                q.push(cur);
            }
        }
    }
    return sz ? (double)waitTime / sz : 0;
}


int main() {
    int a[] = {0,1,4};
    int b[] = {5,2,3};
    vector<int> arrivals(a, a+3), executions(b, b+3);
    int quantum = 3;
    cout << round_robin(arrivals, executions, quantum) << endl;
    return 0;
}
