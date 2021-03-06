/*
    You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
        One envelope can fit into another if and only if both the width and height of one 
        envelope is greater than the width and height of the other envelope.

    What is the maximum number of envelopes can you Russian doll? (put one inside other)

    Example:
    Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can 
        Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& en) {
        sort(en.begin(), en.end(), [](pair<int, int> &p1, pair<int, int> &p2)
                                      {
                                        return p1.first == p2.first ?
                                            p1.second > p2.second :
                                            p1.first < p2.first;
                                      });
        vector<int> dp;
        for (auto itr = en.begin(); itr != en.end(); itr++)
        {
            auto t = lower_bound(dp.begin(), dp.end(), itr->second);
            if (t == dp.end()) dp.push_back(itr->second);
            else *t = itr->second;
        }
        return dp.size();
    }
};


class Solution2 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end());
        int sz = (int)envelopes.size(), total = 1;
        vector<int> dp(sz, 1);
        for (int i = 1; i < sz; ++i) {
            auto &e2 = envelopes[i];
            for (int j = 0; j < i; ++j) {
                auto &e1 = envelopes[j];
                if (e1.first < e2.first and e1.second < e2.second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            total = max(total, dp[i]);
        }
        return total;
    }
};
