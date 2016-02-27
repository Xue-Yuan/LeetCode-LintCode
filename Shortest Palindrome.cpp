/*
    Given a string S, you are allowed to convert it to a palindrome 
        by adding characters in front of it. Find and return the 
        shortest palindrome you can find by performing this transformation.

    For example:

        Given "aacecaaa", return "aaacecaaa".

        Given "abcd", return "dcbabcd".
*/

//Manacher's algorithm
class Solution 
{
private:
    //We do not need actually preprocess the string.
    // We can pretend that. For more info refer to "Longest Palindromic Substring.cpp"
    string preprocess(string s)
    {
        string res = "^#";
        for(char &c : s)
        {
            res += c;
            res += "#";
        }
        res += "$";
        return res;
    }
public:         
    string shortestPalindrome(string s) 
    {
        if(s.size() < 2) return s;
        string str = preprocess(s);
        
        vector<int> dp(str.size(), 0);
        
        int C = 0, R = 0;
        for(int i = 1; i < str.size() - 1; ++i)
        {
            int i_mirror = 2 * C - i;
            dp[i] = (R > i) ? min(R - i, dp[i_mirror]) : 0;

            while(str[i + 1 + dp[i]] == str[i - 1 - dp[i]])
                ++dp[i];
            if(i + dp[i] > R)
            {
                R = i + dp[i];
                C = i;
            }            
        }

        int end = 0;
        for(int i = 0; i < dp.size(); ++i)
        {   //i - dp[i] is the idx of str. (idx(str) - 1) / 2 is the idx of the original string
            if((i - dp[i] - 1) / 2 == 0)
                end = (i + dp[i] - 1) / 2;
        }
        string res = s.substr(end);
        reverse(res.begin(), res.end());
        res += s;
        return res;
    }
};

//KMP
class Solution2 
{
public:         
    string shortestPalindrome(string s) 
    {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        //compute lps
        for (int i = 1; i < l.size(); i++) 
        {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p.back()) + s;
    }
};