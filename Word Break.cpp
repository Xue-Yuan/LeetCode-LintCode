/*
    Given a string s and a dictionary of words dict, determine 
        if s can be segmented into a space-separated sequence 
        of one or more dictionary words.

    For example, given
        s = "leetcode",
        dict = ["leet", "code"].

    Return true because "leetcode" can be segmented as "leet code".

*/
class Solution
{
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); ++i)
            for (int j = i - 1; j >= 0 && !dp[i]; --j)
                dp[i] = dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end();
        
        return dp[s.size()];
    }
};
