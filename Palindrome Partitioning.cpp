/*
    Given a string s, partition s such that every substring of the 
        partition is a palindrome.

    Return all possible palindrome partitioning of s.

    For example, given s = "aab",
    Return

      [
        ["aa","b"],
        ["a","a","b"]
      ]
*/

class Solution {
private:
    bool check(const string &s, int b, int e)
    {
        if (b > e) return false;
        while (b <= e)
            if (s[b++] != s[e--]) return false;
        return true;
    }
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        vector<string> vec;
        partition(s, 0, vec, ret);
        return ret;
    }
    void partition(const string &s, int beg, vector<string> &vec, vector<vector<string>> &ret)
    {
        int slen = (int)s.size();
        if (beg >= slen)
        {
            ret.push_back(vec);
            return;
        }
        
        for (int end = beg; end != slen; ++end)
        {
            if (check(s, beg, end))
            {
                vec.push_back(s.substr(beg, end - beg + 1));
                partition(s, end + 1, vec, ret);
                vec.pop_back();
            }
        }
    }
};

//Dynamic programming
class Solution2
{
private:
    vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s)
    {
        dp.assign(s.size(), vector<bool>(s.size(), false));
        for (int i = (int)s.size() - 1; i >= 0; --i)
            for (int j = i; j < (int)s.size(); ++j)
                dp[i][j] = (s[i] == s[j]) && (j <= i + 2 || dp[i + 1][j - 1]);
        
        vector<vector<string>> ret;
        vector<string> vec;
        partition(s, 0, vec, ret);
        return ret;
    }
    void partition(const string &s, int beg, vector<string> &vec, vector<vector<string>> &ret)
    {
        int slen = (int)s.size();
        if (beg >= slen)
        {
            ret.push_back(vec);
            return;
        }
        
        for (int end = beg; end != slen; ++end)
        {
            if (dp[beg][end])
            {
                vec.push_back(s.substr(beg, end - beg + 1));
                partition(s, end + 1, vec, ret);
                vec.pop_back();
            }
        }
    }
};