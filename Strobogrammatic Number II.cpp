/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n <= 0) return {};
        
        string str(n, '1');
        vector<string> ret;
        find(0, n-1, str, ret);
        return ret;
    }
private:
    void find(int start, int end, string &str, vector<string> &ret)
    {
        if (start > end)
        {
            ret.push_back(str);
            return;
        }
        
        for (auto v : p)
        {
            if (start == 0 && v[0] == '0' && start != end) continue;
            if (start == end && v[0] != v[1]) continue;
            str[start] = v[0], str[end] = v[1];
            find(start+1, end-1, str, ret);
        }
    }
private:
    char p[5][2] = {{'1','1'},{'0','0'},{'6','9'},{'9','6'},{'8','8'}};
};

