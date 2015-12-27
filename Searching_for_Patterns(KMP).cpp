/*
    To understand this, lps table stores a length (longest proper prefix and suffix match),
        and the length is related to the index. Index = length - 1
    http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
*/
class KMP
{
public:
    void computeLPS(const string &pat, vector<int> &lps)
    {
        //len: length of the previous longest prefix suffix
        int len = 0, i = 1, m = pat.size();
        lps.assign(m, 0);

        while(i < m)
        {
            if(pat[i] == pat[len])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    ++i;
                }
            }    
        }
        // for(auto &i : lps)
        //     cout << i << ' ';
        // cout << endl;
    }
    void KMPsearch(const string &pat, const string &txt)
    {
        int m = pat.size(), n = txt.size();
        vector<int> lps(m);
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while(i < n)
        {
            if(pat[j] == txt[i])
            {
                ++j;
                ++i;
            }
            if(j == m)
            {
                cout << "found pattern at " << i - j << endl;
                j = lps[j - 1];
            }
            else if(i < n && pat[j] != txt[i])
            {
                if(j != 0)
                    j = lps[j - 1];         //until pa[lps[j - 1] - 1] already match. next index pa[lps[j - 1]]
                else
                    i = i + 1;
            }
        }
    }
};

//consice version
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {

        vector<int> lps(needle.size(), 0);
        for(int i = 1; i < needle.size(); ++i)
        {
            int j = lps[i - 1];
            while(j > 0 && needle[i] != needle[j])
                j = lps[j - 1];
            lps[i] = (j += needle[i] == needle[j]);
        }

        int i = 0, j = 0;
        while(i < haystack.size() && j < needle.size())
        {
            if(j > 0 && haystack[i] != needle[j])
                j = lps[j - 1];
            else
            {
                j += haystack[i] == needle[j];
                ++i;
            }
        }
        return (j == needle.size()) ? i  - j : -1;
    }
};