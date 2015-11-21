/*
Given a string, find the length of the longest substring without 
    repeating characters. For example, the longest substring 
    without repeating letters for "abcabcbb" is "abc", which the 
    length is 3. For "bbbbb" the longest substring is "b", with 
    the length of 1.
*/

/*
    The idea is to keep track of the recent occuring position of
        the character. If a duplicate is found before the current
        start position, there won't be a problem. We just need to
        update the duplicate position. Otherwise the start postion
        has to be changed to the pos of the duplicate.
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() < 2) return s.size();
        unordered_map<char, int> mp;
        mp[s[0]] = 0;
        int max_cnt = 0, beg = 0, cur = 1;
        for(int i = 1; i < s.size(); ++i)
        {
            if(mp.find(s[i]) == mp.end())
            {
                ++cur;
            }
            else
            {
                if((beg > mp[s[i]]))
                {
                    ++cur;
                }
                else
                {
                    beg = mp[s[i]] + 1;
                    cur = i - mp[s[i]];
                }
            }
            mp[s[i]] = i;
            max_cnt = max(max_cnt, cur);
        }
        return max_cnt;
    }
};

/*
    This is the concise version of the same idea
*/
class Solution2 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        // for ASCII char sequence, use this as a hashmap
        vector<int> charIndex(256, -1);
        int longest = 0, start = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            start = max(charIndex[s[i]] + 1, start);    // automatically takes care of -1 case
            charIndex[s[i]] = i;
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};