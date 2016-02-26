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
        str[start] = str[end] = '1';
        find(start+1, end-1, str, ret);
        
        if (start == end || start != 0)
        {
            str[start] = str[end] = '0';
            find(start+1, end-1, str, ret);
        }

        str[start] = str[end] = '8';
        find(start+1, end-1, str, ret);

        if (start != end)
        {
            str[start] = '6'; str[end] = '9';
            find(start+1, end-1, str, ret);
            str[start] = '9'; str[end] = '6';
            find(start+1, end-1, str, ret);
        }
    }
};
