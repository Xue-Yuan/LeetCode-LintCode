/*
    Given a string s and a dictionary of words dict, 
        add spaces in s to construct a sentence where 
        each word is a valid dictionary word.

    Return all such possible sentences.

    For example, given
        s = "catsanddog",
        dict = ["cat", "cats", "and", "sand", "dog"].

    A solution is ["cats and dog", "cat sand dog"].
*/

/*
    I took advantage of the result of Word Break
*/

class Solution 
{
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
       /******** Below is the result form word break **********/
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        if(!dp[s.size()]) return {};
        /******************************************************/
        vector<string> ret;
        wordBreak(s, 0, wordDict, dp, "", ret);
        return ret;
    }

    void wordBreak(const string &s, int beg, unordered_set<string> &wordDict, vector<bool> &dp, string str, vector<string> &ret)
    {
        if(beg == s.size())
        {
            ret.push_back(str.substr(0, str.size() - 1));  //eliminate the last space
            return;
        }

        for(int i = beg + 1; i <= s.size(); ++i)
         //We only go further for certain cases
            if(dp[i] && wordDict.find(s.substr(beg, i - beg)) != wordDict.end()) 
                wordBreak(s, i, wordDict, dp, str + s.substr(beg, i - beg) + " ", ret);
    }
};