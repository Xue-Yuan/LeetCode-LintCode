/*
    Given two strings s and t, determine if they are isomorphic.

    Two strings are isomorphic if the characters in s can be replaced to 
        get t.

    All occurrences of a character must be replaced with another character 
        while preserving the order of characters. No two characters may map 
        to the same character but a character may map to itself.

    For example,
        Given "egg", "add", return true.

        Given "foo", "bar", return false.

        Given "paper", "title", return true.
*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<char> m(256, '\0');
        
        for (int i = 0; i < s.size(); ++i)
            if (m[s[i]] == '\0') m[s[i]] = t[i];
            else if (m[s[i]] != t[i]) return false;
        
        m.assign(256, '\0');
        for (int i = 0; i < s.size(); ++i)
            if (m[t[i]] == '\0') m[t[i]] = s[i];
            else if (m[t[i]] != s[i]) return false;
        
        return true;
    }
};

class Solution2
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> m1(256, -1), m2(256, -1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};