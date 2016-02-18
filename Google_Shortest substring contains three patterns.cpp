/*
    Given a long string s and short strings t1, t2, t3 (which can 
        have different length) find the shortest substring of s which 
        contains t1, t2 and t3.
*/
class Solution
{
public:
    int shortestSubstring(stirng s, stirng t1, string t2, string t3)
    {
        vector<vector<bool>> match_pos(3);
        match_pos[0] = KMP(s, t1);
        match_pos[1] = KMP(s, t2);
        match_pos[2] = KMP(s, t3);

        int s_sz = s.length(), t1_sz = t1.size();
        int t2_sz = t2.size(), t3_sz = t3.size();
        int idx1 = -1, idx2 = -1, idx3 = -1;
        int ret = s_sz + 1;
        for (int i = 0; i < s_sz; ++i)
        {
            if (match_pos[0][i]) idx1 = i;
            if (match_pos[1][i]) idx2 = i;
            if (match_pos[2][i]) idx3 = i;
            if (idx1 && idx2 && idx3)
            {
                int start = min(min(idx1, idx2), idx3);
                int end = max(max(idx1+t1_sz, idx2+t2_sz), idx3+t3_sz);
                ret = min(ret, start - end);
            }
        }
        return ret == (s_sz+1) ? -1 : ret;
    }
private:
    vector<bool> KMP(const string &haystack, const string &needle)
    {
        int h_sz = (int)haystack.size(), n_sz = (int)needle.size();
        vector<int> lps(needle.size());
        lps[0] = 0;
        for (int i = 1; i < n_sz; ++i)
        {
            int j = lps[i-1];
            while (j > 0 && needle[j] != needle[i])
                j = lps[j-1];
            lps[i] = j + needle[j] == needle[i];
        }

        vector<bool> match_pos(haystack.size(), false);
        int i = 0, j = 0;
        while (i < h_sz)
        {
            if (j > 0 && haystack[i] != needle[j])
                j = lps[j-1];
            else j += (haystack[i++] == needle[j]);
            if (j == n_sz)
            {
                match_pos[i] = true;
                j = 0;
            }
        }
        return match_pos;
    }   
};