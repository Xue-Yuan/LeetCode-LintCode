/*
    Given a string, find the length of the longest substring T that contains 
        at most 2 distinct characters.

    For example, Given s = “eceba”,

    T is "ece" which its length is 3.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        vector<int> m(256, 0);
        
        int start = 0, end = 0, len = (int)s.size();
        int ret = 0, cnt = 0;
        while (end < len)
        {
            while (cnt < 3 && end <= len)  //exclusive end
            {
                ret = max(ret, end-start);
                if (end < len) 
                    if(m[s[end]]++ == 0) cnt++;
                end++;
            }
            
            while (start < end && cnt >= 3)
            {
                if (m[s[start++]]-- == 1)
                    cnt--;
            }
        }
        return ret;
    }
};
