/*
	Given a string s consists of upper/lower-case alphabets and 
		empty space characters ' ', return the length of last word 
		in the string.

	If the last word does not exist, return 0.

	Note: A word is defined as a character sequence consists of 
		non-space characters only.

	For example, 
		Given s = "Hello World",
		return 5.
*/

class Solution
{
public:
    int lengthOfLastWord(string s) 
    {
        int end, beg, idx = (int)s.size() - 1;
        while (idx >= 0 && s[idx] == ' ') idx--;
        end = idx;
        while (idx >= 0 && s[idx] != ' ') idx--;
        beg = idx;
        return end - beg;
    }
};