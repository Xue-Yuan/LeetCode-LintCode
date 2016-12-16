class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cntr;
        for (char ch : s) {
            ++cntr[ch];
        }
        priority_queue<pair<int, char>> q;
        for (auto k : cntr) {
            q.push({k.second, k.first});
        }
        string ans;
        while (!q.empty()) {
            const auto &p = q.top();
            ans.append(p.first, p.second);
            q.pop();
        }
        return ans;
    }
};
