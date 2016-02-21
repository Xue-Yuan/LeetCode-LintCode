/*
    Given a string S and a string T, find the minimum window in S 
        which will contain all the characters in T in complexity 
        O(n).

    For example,
        S = "ADOBECODEBANC"
        T = "ABC"
        Minimum window is "BANC".

    Note:
    If there is no such window in S that covers all characters in T, 
        return the empty string "".

    If there are multiple such windows, you are guaranteed that there 
        will always be only one unique minimum window in S.
*/
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        if (t.empty()) return t;
        
        vector<int> need(256, 0), found(256, 0);
        for (char &c : t) need[c]++;
        
        size_t start = 0, end = 0, len = s.size()+1;
        size_t head = 0, cnt = 0;
        while (end < s.size())
        {
            if (need[s[end]]) 
                if (found[s[end]]++ < need[s[end]])
                    cnt++;
            end++;

            while (cnt == t.size())
            {
                if (end-start < len)
                {
                    len = end-start;
                    head = start;
                }
                if (need[s[start]])
                    if (found[s[start]]-- <= need[s[start]])
                        cnt--;
                start++;
            }
        }
        return len > s.size() ? "" : s.substr(head, len);
    }
};

//Further, one map is enough.
class Solution2 
{
public:
    string minWindow(string s, string t) 
    {
        if (t.empty()) return t;
        
        vector<int> map(256, 0);
        for (char &c : t) map[c]++;
        
        size_t start = 0, end = 0, cnt = t.size();
        size_t head = 0, len = s.size()+1;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0) cnt--;
            while (cnt == 0)
            {
                if (end-start < len)
                {
                    len = end-start;
                    head = start;
                }
                if (map[s[start++]]++ == 0) cnt++;
            }
        }
        return len > s.size() ? "" : s.substr(head, len);
    }
};
