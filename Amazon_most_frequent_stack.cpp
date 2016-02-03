class Solution 
{
public:
    void push(int v)
    {
        val.push_back(v);
        ++m[v];
        if (mostF.empty())
        {
            mostF.push_back(v);
            return;
        }
        if (m[v] > m[mostF.back()])
            mostF.push_back(v);
        else mostF.push_back(mostF.back());
    }
    int pop()
    {
        val.pop_back();
        int tmp = mostF.back(); mostF.pop_back();
        if (--m[tmp] == 0) m.erase(tmp);
        return tmp;    
    }
    int top()
    {
        return mostF.back();
    }
    bool isEmpty() {return val.empty();}
private:
    vector<int> val;
    vector<int> mostF;
    unordered_map<int, int> m;
};

int main()
{
    Solution so;
    string cmd;
    while (true)
    {
        cout << "push, pop or top? :";
        cin >> cmd;
        if (cmd == "push")
        {
            int t;
            cin >> t;
            so.push(t);
        }
        else if (cmd == "pop")
            cout << so.pop() << endl;
        else if (cmd == "top")
            cout << so.top() << endl;
        else break;
    }
    return 0;
}
