class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i1 = 0, i2 = 0, sz1 = (int)s.size(), sz2 = (int)t.size();
        while (i1 < sz1 and i2 < sz2) {
            if (s[i1] == t[i2]) {
                ++i1; ++i2;
            } else {
                ++i2;
            }
        }
        return i1 == sz1;
    }
};
