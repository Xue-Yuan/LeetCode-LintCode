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
        if (s.size() < 2)
            return s;
        
        int last_idx[26];
        vector<bool> occurence(26, false);
        for (int i = 0; i < s.size(); ++i)
            last_idx[s[i] - 'a'] = i;
        
        string res = {s[0]};
        occurence[s[0] - 'a'] = true;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (occurence[s[i] - 'a'])
                continue;
            while (!res.empty() && s[i] < res.back() && last_idx[res.back() - 'a'] > i)   
            {
                occurence[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += s[i];
            occurence[s[i] - 'a'] = true;
        }
        return res;
    }
};