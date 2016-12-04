class Solution {
public:
    vector<int> connections(string item_id, vector<string> &purchases) {
        build_customers(purchases);
        build_graph();
        unordered_set<string> visited{};
        int all_connections = get_all_connections(item_id, visited);
        int strong_connections = graph[item_id].size();
        return {strong_connections, all_connections-strong_connections-1};
    }
private:
    void build_customers(const vector<string> &purchases) {
        for (auto &p : purchases) {
            size_t col = p.find(':');
            string customer = p.substr(0, col), item = p.substr(col+1);
            customers[customer].insert(item);
        }
    }

    void build_graph() {
        for (const auto &k_v : customers) {
            const auto &items = k_v.second;
            for (const auto &item1 : items) {
                for (const auto &item2 : items) {
                    if (item1 != item2) {
                        graph[item1].insert(item2);
                        graph[item2].insert(item1);
                    }
                }
            }
        }
    }
    
    int get_all_connections(string cur, unordered_set<string> &visited) {
        if (visited.find(cur) != visited.end()) {
            return 0;
        }
        visited.insert(cur);
        int cnt = 1;
        for (auto nxt : graph[cur]) {
            cnt += get_all_connections(nxt, visited);
        }
        return cnt;
    } 
private:
    unordered_map<string, unordered_set<string>> customers, graph;
};

int main() {
    Solution s{};
    vector<string> purchases{
        "first:ABC",
        "first:HIJ",
        "sec:HIJ",
        "sec:KLM",
        "third:NOP",
        "fourth:ABC",
        "fourth:QRS",
        "first:DEF",
        "fifth:KLM",
        "fifth:TUV",
    };
    for (auto & i : s.connections("ABC", purchases)) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
