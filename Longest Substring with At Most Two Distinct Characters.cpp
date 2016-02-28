/*
    Given a string, find the length of the longest substring T that contains 
        at most 2 distinct characters.

    For example, Given s = “eceba”,

    T is "ece" which its length is 3.
*/
//can further extend to k distinct characters
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        vector<int> m(256, 0);
        
        int start = 0, len = (int)s.size();
        int ret = 0, cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (m[s[i]]++ == 0) cnt++;
            while (cnt > 2)
            {
                if (m[s[start++]]-- == 1)
                    cnt--;
            }
            ret = max(ret, i-start+1);
        }
        return ret;
    }
};

//Just for 2 distinct characters
class Solution2 { 
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = -1, len = 0, n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) continue;
            if (r >= 0 && s[i] != s[r]) {
                len = max(len, i - l); 
                l = r + 1;
            }
            r = i - 1;
        }
        return max(n - l, len);  
    }
};
