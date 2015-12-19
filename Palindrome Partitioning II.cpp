/*
    Given a string s, partition s such that every substring of the 
        partition is a palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s.

    For example, given s = "aab",
        Return 1 since the palindrome partitioning ["aa","b"] could 
            be produced using 1 cut.
*/

class Solution
{
public:
    int minCut(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        int slen = (int)s.size();
        for (int i = slen - 1; i >= 0; --i)
            for (int j = i; j < slen; ++j)
                dp[i][j] = (s[i] == s[j]) && (j <= i + 2 || dp[i + 1][j - 1]);
        
        vector<int> cnt(s.size(), slen - 1);
        for (int i = slen - 1; i >= 0; --i)
        {
            for (int j = i; j < slen; ++j)
            {
                if (dp[i][j])
                {
                    if (j == slen - 1)  cnt[i] = 0;
                    else cnt[i] = min(cnt[i], cnt[j + 1] + 1);
                }
            }
        }
        return cnt[0];
    }
};

//Use less memory.
class Solution2
{
public:
    int minCut(string s)
    {
        int slen = (int)s.size();
        vector<vector<bool>> dp(2, vector<bool>(s.size(), false));
        vector<int> cnt(s.size(), slen - 1);
        int cur = 0, next = 1;
        
        for (int i = slen - 1; i >= 0; --i)
        {
            for (int j = i; j < slen; ++j)
            {
                if(dp[next][j] = (s[i] == s[j]) && (j <= i + 2 || dp[cur][j - 1]))
                {
                    if (j == slen - 1)  cnt[i] = 0;
                    else cnt[i] = min(cnt[i], cnt[j + 1] + 1);
                }
            }
            swap(cur, next);
        }
        return cnt[0];
    }
};

//Taken from leetcode discussion
//https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
class Solution3 
{
public:
    int minCut(string s)
    {
        int n = (int)s.size();
        vector<int> cut(n + 1, n - 1);
        
        for (int i = 0; i <= n; i++)
            cut[i] = i - 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) // odd length palindrome
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
            
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) // even length palindrome
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
        }
        return cut[n];
    }
};