/*
    Given a string S, find the longest palindromic substring 
        in S. You may assume that the maximum length of S is 
        1000, and there exists one unique longest palindromic 
        substring.
    http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/
//Manacher's
class Solution 
{
private:
    string preProcess(string s)
    {
        if(s.empty()) return "^$";
        string ret = "^";
        for(auto &c : s)
        {
            ret += "#";
            ret += c;
        }
        ret += "#$";
        return ret;
    }
public:
    string longestPalindrome(string s) 
    {
        string T = preProcess(s);
        vector<int> P(T.size(), 0);
        int C = 0, R = 0;
        for(int i = 1; i < T.size() - 1; ++i)
        {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

            while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
                ++P[i];
            if(i + P[i] > R)
            {
                R = i + P[i];
                C = i;
            }
        }
        int maxLen = 0, cen = 0;
        for(int i = 1; i < T.size() - 1; ++i)
        {
            if(P[i] > maxLen)
            {
                maxLen = P[i];
                cen = i;
            }
        }
        return s.substr((cen - maxLen - 1) / 2, maxLen);
    }
    //We don't have to actually preprocess the string
    string longestPalindrome_2(string s) 
    {
        vector<int> P(2 * s.size() + 3, 0);

        int C = 0, R = 0;
        for(int i = 1; i < P.size() - 1; ++i)
        {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            //^#a#a#$   --padding in odd index, char in even
            int left = i - 1 - P[i], right = i + 1 + P[i];
            for(;left > 0 && right <= P.size() + 1; --left, ++right)
            {
                if((left & 0x1) || s[(left - 1) / 2] == s[(right - 1) / 2])
                    P[i]++;
                else
                    break;
            }

            if(i + P[i] > R)
            {
                R = i + P[i];
                C = i;
            }

        }
        int maxLen = 0, cen = 0;
        for(int i = 1; i < P.size() - 1; ++i)
        {
            if(P[i] > maxLen)
            {
                maxLen = P[i];
                cen = i;
            }
        }
        // cout << cen << ' ' << maxLen << endl;
        return s.substr((cen - maxLen) / 2, maxLen);
    }
};