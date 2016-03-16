/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

class Solution 
{
public:
    int strobogrammaticInRange(string low, string high) 
    {
        cnt = 0;
        int low_sz = low.size(), high_sz = high.size();
        for (int i=low_sz; i<=high_sz; i++)
        {
            string path(i, '0');
            dfs(low, high, 0, i-1, path);
        }
        return cnt;
    }
private:
    void dfs(string &low, string &high, int b, int e, string &path)
    {
        if (b > e)
        {
            if (path.size() == low.size() && path < low) return;
            if (path.size() == high.size() && path > high) return;
            cnt++;
            return;
        }
        
        for (auto &v : p)
        {
            if (b == 0 && v[0] == '0' && b != e) continue;
            if (b == e && v[0] != v[1]) continue;
            path[b] = v[0]; path[e] = v[1];
            dfs(low, high, b+1, e-1, path);
        }
    }
    
private:
    int cnt;
    char p[5][2] = {{'1','1'},{'0','0'},{'6','9'},{'9','6'},{'8','8'}};
};
