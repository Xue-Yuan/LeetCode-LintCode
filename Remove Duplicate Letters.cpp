/*
    Given a string which contains only lowercase letters, remove 
        duplicate letters so that every letter appear once and 
        only once. You must make sure your result is the smallest 
        in lexicographical order among all possible results.

    Example:
        Given "bcabc"
            Return "abc"

        Given "cbacdcbc"
            Return "acdb"
*/
            
class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        if (s.size() < 2) return s;
        
        vector<int> last_idx(26, -1);
        int len = s.size();
        for (int i=0; i<len; ++i)
            last_idx[s[i]-'a'] = i;
        
        string res;
        vector<bool> used(26, false);
        for (int i=0; i<len; i++)
        {
            if (used[s[i]-'a']) continue;
            while (!res.empty() && s[i] < res.back() && last_idx[res.back()-'a'] > i)
            {
                used[res.back()-'a'] = false;
                res.pop_back();
            }
            res += s[i];
            used[s[i]-'a'] = true;
        }
        return res;
    }
};
