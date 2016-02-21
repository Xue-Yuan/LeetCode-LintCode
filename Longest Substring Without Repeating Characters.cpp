/*
    Given a string, find the length of the longest substring without 
        repeating characters. For example, the longest substring 
        without repeating letters for "abcabcbb" is "abc", which the 
        length is 3. For "bbbbb" the longest substring is "b", with 
        the length of 1.
*/

/*
    Use a map to keep track of how many times each letter occurs.
        Move the end pointer first. When a letter occurs more than
        once, move the start pointer to shrink the window to exclude
        the duplicate letter.
*/
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty()) return 0;
        
        vector<int> map(256, 0);
        int len = 1, start = 0, end = 0, s_sz = (int)s.size();
        while (end < s_sz)
        {
            if (map[s[end]]++ == 0)
                len = max(len, end-start+1);            
            while (map[s[end]] > 1)
                map[s[start++]]--;
            end++;
        }
        return len;
    }
};

/*
    The idea is to keep track of the recent occuring position of
        the character. If a duplicate is found before the current
        start position, there won't be a problem. We just need to
        update the duplicate position. Otherwise the start postion
        has to be changed to the pos of the duplicate.
*/
class Solution2 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        // for ASCII char sequence, use this as a hashmap
        vector<int> charIndex(256, -1);
        int longest = 0, start = 0;

        for (int i = 0; i < (int)s.length(); i++) 
        {
            start = max(charIndex[s[i]] + 1, start);    // automatically takes care of -1 case
            charIndex[s[i]] = i;
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};
