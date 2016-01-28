/*
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.
*/

//brute force
class Solution 
{
public:
    int strStr(string haystack, string needle)
    {
        for (size_t i = 0; ; ++i)
            for (size_t j = 0; ; ++j)
            {
                if (j == needle.size()) return (int)i;
                if (i + j == haystack.size()) return -1;
                if (haystack[i + j] != needle[j]) break;
            }
        return -1;
    }
};

//KMP
class Solution2 
{
public:
    int strStr(string haystack, string needle) 
    {
        vector<int> lps(needle.size(), 0);
        for (size_t i = 1; i < needle.size(); ++i)
        {
            int len = lps[i - 1];
            while (len > 0 && needle[len] != needle[i]) 
                len = lps[len - 1];
            lps[i] = len += needle[i] == needle[len];
        }
        
        size_t i = 0, j = 0;
        while (i < haystack.size() && j < needle.size())
        {
            if (j > 0 && haystack[i] != needle[j])
                j = lps[j - 1];
            else
                j += haystack[i++] == needle[j];
        }
        return j == needle.size() ? i - j : -1;
    }
};
